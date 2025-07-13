
#ifndef SZENEXT_HPP
#define SZENEXT_HPP

#include "../tool/readconfig.hpp"
#include "../tool/mods.hpp"
#include "utils.hpp"
#include "unistd.h"
#include <chrono>
#include <condition_variable>
#include <fstream>
#include <iostream>
#include <math.h>
#include <mutex>
#include <string>
#include <sys/inotify.h>
#include <thread>
#include <atomic>
using namespace std;

class Semaphore{
private:
    mutex mtx;
    condition_variable cv;
    int count;
public:
    Semaphore(int initial = 0) : count(initial) {};

    void release(){
        unique_lock<mutex> lock(mtx);
        ++count;
        cv.notify_all();
    }

    void acquire(){
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this] {return count > 0; });
        --count;
    }

};

class SZENEXT{
public:
    string Mods,Mtemp;
    Utils utils;
    Rconfig config;
    MODS mods;

    string SZE_VERSION = "4.2";
    Semaphore sem1{1};
    Semaphore sem2{0};
    Semaphore sem3{0};

    int OC;
    const char * configfile = "/storage/emulated/0/Android/SZE_NEXT/config.txt";

    int fd = inotify_init();
    int wd = inotify_add_watch(fd, configfile, IN_MODIFY);
    char buff[1024];


    void FREQ(bool Enadle_2,bool Eandle_3){
    config.ReadPolicy();
    while(1){
        sem1.acquire();
        int len = read(fd, buff, sizeof(buff));
        for (char* i = buff; i < buff + len; ) {
            auto *eve = reinterpret_cast<inotify_event *>(i);
            if ( eve -> mask & IN_MODIFY) {
                ifstream file = mods.GETC();
                string modes;
                while (getline(file,modes)) {
                    Mods = std::move(modes);

                    config.ReadFreqConfig(Mods);
                    config.ReadUclamp(Mods);
                    FREQPDMODS();
                    UCLAMP();
                    if (Mods != Mtemp) {
                        Mtemp = Mods;
                        utils.log(("模式更新："+ Mods).c_str());
                    }
                }
            }
            if (Enadle_2) {
                sem2.release();
                }else if (Eandle_3) {
                sem3.release();
                }
                i += sizeof(inotify_event) + eve -> len;
            }
        }
    }

    void GOVER(bool Enadle_1,bool Enadle_3){
        config.ReadPolicy();
        while (1) {
            sem2.acquire();
            ifstream file = mods.GETC();
            string modes;
            while (getline(file,modes)) {
                Mods = std::move(modes);

                config.ReadGoverConfig(Mods);
                GOVERPDMODS();
            }
            if (Enadle_3) {
                sem3.release();
            }else if (Enadle_1) {
                sem1.release();
            }
        }
    }

    void GOVERCONFIG(bool Enadle_1,bool Enadle_2){
        config.ReadPolicy();
        while (1) {
            sem3.acquire();
            ifstream file = mods.GETC();
            string modes;
            while (getline(file,modes)) {
                Mods = std::move(modes);
                config.ReadGoverConfig(Mods);
                config.ReadGoverConfigConfig(Mods);
                GOVERCONFIGPDMODS();
            }
            if (Enadle_1) {
                sem1.release();
            }else if (Enadle_2) {
                sem2.release();
            }
        }
    }



    string GETFreqPath(string policy){
        return "/sys/devices/system/cpu/cpufreq/policy" + policy + "/scaling_max_freq";
    }

    string GETGoverPath(string policy){
        return "/sys/devices/system/cpu/cpufreq/policy" + policy + "/scaling_governor";
    }

    string GETGovernorPath(string policy, string gover, string path){
        return "/sys/devices/system/cpu/cpufreq/policy" + policy + "/" + gover + "/" + path;
    }


    void FREQPDMODS(){
        utils.Writer(GETFreqPath(config.policy1), config.FREQ_MINCORE);
        utils.Writer(GETFreqPath(config.policy2), config.FREQ_MIDCORE);
        utils.Writer(GETFreqPath(config.policy3), config.FREQ_BIGCORE);
        utils.Writer(GETFreqPath(config.policy4), config.FREQ_MAXCORE);
        utils.Writer("/proc/sys/kernel/sched_energy_aware",config.EAS_Enable);
    }

    void GOVERPDMODS(){
        utils.Writer(GETGoverPath(config.policy1), config.GOVER_MINCORE);
        utils.Writer(GETGoverPath(config.policy2), config.GOVER_MIDCORE);
        utils.Writer(GETGoverPath(config.policy3), config.GOVER_BIGCORE);
        utils.Writer(GETGoverPath(config.policy4), config.GOVER_MAXCORE);
    }

    void GOVERCONFIGPDMODS(){
        utils.Writer(GETGovernorPath(config.policy1, config.GOVER_MINCORE, config.GOVER_C_MINCORE1_PATH), config.GOVER_C_MINCORE1);
        utils.Writer(GETGovernorPath(config.policy2, config.GOVER_MIDCORE, config.GOVER_C_MIDCORE1_PATH), config.GOVER_C_MIDCORE1);
        utils.Writer(GETGovernorPath(config.policy3, config.GOVER_BIGCORE, config.GOVER_C_BIGCORE1_PATH), config.GOVER_C_BIGCORE1);
        utils.Writer(GETGovernorPath(config.policy4, config.GOVER_MAXCORE, config.GOVER_C_MAXCORE1_PATH), config.GOVER_C_MAXCORE1);

        utils.Writer(GETGovernorPath(config.policy1, config.GOVER_MINCORE, config.GOVER_C_MINCORE2_PATH), config.GOVER_C_MINCORE2);
        utils.Writer(GETGovernorPath(config.policy2, config.GOVER_MIDCORE, config.GOVER_C_MIDCORE2_PATH), config.GOVER_C_MIDCORE2);
        utils.Writer(GETGovernorPath(config.policy3, config.GOVER_BIGCORE, config.GOVER_C_BIGCORE2_PATH), config.GOVER_C_BIGCORE2);
        utils.Writer(GETGovernorPath(config.policy4, config.GOVER_MAXCORE, config.GOVER_C_MAXCORE2_PATH), config.GOVER_C_MAXCORE2);

        utils.Writer(GETGovernorPath(config.policy1, config.GOVER_MINCORE, config.GOVER_C_MINCORE3_PATH), config.GOVER_C_MINCORE3);
        utils.Writer(GETGovernorPath(config.policy2, config.GOVER_MIDCORE, config.GOVER_C_MIDCORE3_PATH), config.GOVER_C_MIDCORE3);
        utils.Writer(GETGovernorPath(config.policy3, config.GOVER_BIGCORE, config.GOVER_C_BIGCORE3_PATH), config.GOVER_C_BIGCORE3);
        utils.Writer(GETGovernorPath(config.policy4, config.GOVER_MAXCORE, config.GOVER_C_MAXCORE3_PATH), config.GOVER_C_MAXCORE3);

        utils.Writer(GETGovernorPath(config.policy1, config.GOVER_MINCORE, config.GOVER_C_MINCORE4_PATH), config.GOVER_C_MINCORE4);
        utils.Writer(GETGovernorPath(config.policy2, config.GOVER_MIDCORE, config.GOVER_C_MIDCORE4_PATH), config.GOVER_C_MIDCORE4);
        utils.Writer(GETGovernorPath(config.policy3, config.GOVER_BIGCORE, config.GOVER_C_BIGCORE4_PATH), config.GOVER_C_BIGCORE4);
        utils.Writer(GETGovernorPath(config.policy4, config.GOVER_MAXCORE, config.GOVER_C_MAXCORE4_PATH), config.GOVER_C_MAXCORE4);

        utils.Writer(GETGovernorPath(config.policy1, config.GOVER_MINCORE, config.GOVER_C_MINCORE5_PATH), config.GOVER_C_MINCORE5);
        utils.Writer(GETGovernorPath(config.policy2, config.GOVER_MIDCORE, config.GOVER_C_MIDCORE5_PATH), config.GOVER_C_MIDCORE5);
        utils.Writer(GETGovernorPath(config.policy3, config.GOVER_BIGCORE, config.GOVER_C_BIGCORE5_PATH), config.GOVER_C_BIGCORE5);
        utils.Writer(GETGovernorPath(config.policy4, config.GOVER_MAXCORE, config.GOVER_C_MAXCORE5_PATH), config.GOVER_C_MAXCORE5);

        utils.Writer(GETGovernorPath(config.policy1, config.GOVER_MINCORE, config.GOVER_C_MINCORE6_PATH), config.GOVER_C_MINCORE6);
        utils.Writer(GETGovernorPath(config.policy2, config.GOVER_MIDCORE, config.GOVER_C_MIDCORE6_PATH), config.GOVER_C_MIDCORE6);
        utils.Writer(GETGovernorPath(config.policy3, config.GOVER_BIGCORE, config.GOVER_C_BIGCORE6_PATH), config.GOVER_C_BIGCORE6);
        utils.Writer(GETGovernorPath(config.policy4, config.GOVER_MAXCORE, config.GOVER_C_MAXCORE6_PATH), config.GOVER_C_MAXCORE6);

        utils.Writer(GETGovernorPath(config.policy1, config.GOVER_MINCORE, config.GOVER_C_MINCORE7_PATH), config.GOVER_C_MINCORE7);
        utils.Writer(GETGovernorPath(config.policy2, config.GOVER_MIDCORE, config.GOVER_C_MIDCORE7_PATH), config.GOVER_C_MIDCORE7);
        utils.Writer(GETGovernorPath(config.policy3, config.GOVER_BIGCORE, config.GOVER_C_BIGCORE7_PATH), config.GOVER_C_BIGCORE7);
        utils.Writer(GETGovernorPath(config.policy4, config.GOVER_MAXCORE, config.GOVER_C_MAXCORE7_PATH), config.GOVER_C_MAXCORE7);

        utils.Writer(GETGovernorPath(config.policy1, config.GOVER_MINCORE, config.GOVER_C_MINCORE8_PATH), config.GOVER_C_MINCORE8);
        utils.Writer(GETGovernorPath(config.policy2, config.GOVER_MIDCORE, config.GOVER_C_MIDCORE8_PATH), config.GOVER_C_MIDCORE8);
        utils.Writer(GETGovernorPath(config.policy3, config.GOVER_BIGCORE, config.GOVER_C_BIGCORE8_PATH), config.GOVER_C_BIGCORE8);
        utils.Writer(GETGovernorPath(config.policy4, config.GOVER_MAXCORE, config.GOVER_C_MAXCORE8_PATH), config.GOVER_C_MAXCORE8);
    }

    void UCLAMP(){
        utils.Writer("/dev/cpuctl/background/cpu.uclamp.max", config.BACK_C_UCLAMP_MAX);
        utils.Writer("/dev/cpuctl/background/cpu.uclamp.min", config.BACK_C_UCLAMP_MIN);
        utils.Writer("/dev/cpuctl/top-app/cpu.uclamp.max", config.TOP_APP_C_UCLAMP_MAX);
        utils.Writer("/dev/cpuctl/top-app/cpu.uclamp.min", config.TOP_APP_C_UCLAMP_MIN);
        utils.Writer("/dev/cpuctl/system-background/cpu.uclamp.max", config.S_BACK_C_UCLAMP_MAX);
        utils.Writer("/dev/cpuctl/system-background/cpu.uclamp.min", config.S_BACK_C_UCLAMP_MIN);
        utils.Writer("/dev/cpuctl/system/cpu.uclamp.max", config.SYS_C_UCLAMP_MAX);
        utils.Writer("/dev/cpuctl/system/cpu.uclamp.min", config.SYS_C_UCLAMP_MIN);
        utils.Writer("/dev/cpuctl/foreground/cpu.uclamp.max", config.F_C_UCLAMP_MAX);
        utils.Writer("/dev/cpuctl/foreground/cpu.uclamp.min", config.F_C_UCLAMP_MIN);
        utils.Writer("/dev/cpuset/background/cpus", config.CPUSET_Background);
        utils.Writer("/dev/cpuset/top-app/cpus", config.CPUSET_Top_app);
        utils.Writer("/dev/cpuset/system-background/cpus", config.CPUSET_System_Background);
        utils.Writer("/dev/cpuset/system/cpus", config.CPUSET_System);
        utils.Writer("/dev/cpuset/foreground/cpus", config.CPUSET_Foreground);
    }


    void init(){
        utils.my_log("***********************************************");
        utils.my_log("*人生路漫漫，每个人都有独属于自己的浪漫*\n*多么想让这独属于自己的浪漫，永恒定格！*");
        utils.my_log("***********************************************");
        utils.my_log("ShenEternity祝你使用愉快！\n");
        utils.log("SZE_NEXT已加载");
        utils.log(("******SZE_NEXT版本：" + SZE_VERSION).c_str());
        config.ReadName();
        utils.log(("******调度配置：" + config.name).c_str());
        utils.log(("******配置版本：" + config.lv).c_str());
        utils.log(("******配置作者：" + config.Out).c_str());
        
    }

};

#endif
