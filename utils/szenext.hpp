
#ifndef SZENEXT_HPP
#define SZENEXT_HPP

#include "../tool/readconfig.hpp"
#include "../tool/mods.hpp"
#include "utils.hpp"
#include "unistd.h"
#include <cmath>
#include <condition_variable>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <math.h>
#include <mutex>
#include <string>
#include <sys/inotify.h>
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

    string SZE_VERSION = "5.0";
    Semaphore sem1{1};
    Semaphore sem2{0};
    Semaphore sem3{0};

    int OC;
    int cfs;
    const char * configfile = "/storage/emulated/0/Android/SZE_NEXT/config.txt";

    int fd = inotify_init();
    int wd = inotify_add_watch(fd, configfile, IN_MODIFY);
    char buff[1024];


    void FREQ(bool Enadle_2,bool Eandle_3){
    config.ReadPolicy();
    config.ReadSetConfig();
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
                    FREQPDMODS();
                    if (config.Uclamp) {
                        config.ReadUclamp(Mods);
                        UCLAMP();
                    }
                    if (config.CpuSet) {
                        config.ReadCpuSet(Mods);
                        CpuSet();
                    }
                    if (Mods != Mtemp) {
                        Mtemp = Mods;
                        utils.log("INFO: CFS调整完毕");
                        utils.log(("INFO: 模式更新："+ Mods).c_str());
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
                config.ReadSysConfig(Mods);
                SYS();
                config.ReadCFS(Mods);
                CFS();
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
        utils.Writer("/sys/module/mtk_fpsgo/parameters/perfmgr_enable", config.Feas_Enable);
    }

    void GOVERPDMODS(){
        utils.Writer(GETGoverPath(config.policy1), config.GOVER_MINCORE);
        utils.Writer(GETGoverPath(config.policy2), config.GOVER_MIDCORE);
        utils.Writer(GETGoverPath(config.policy3), config.GOVER_BIGCORE);
        utils.Writer(GETGoverPath(config.policy4), config.GOVER_MAXCORE);
    }

    void GOVERCONFIGPDMODS(){
        for (size_t s = 1; s < config.GoverConfigPathMIN.size(); s++) {
            utils.Writer(GETGovernorPath(config.policy1, config.GOVER_MINCORE, config.GoverConfigPathMIN[s]),config.GoverConfigMIN[s]);
        }
        for (size_t s = 1; s < config.GoverConfigPathMID.size(); s++) {
            utils.Writer(GETGovernorPath(config.policy2, config.GOVER_MIDCORE, config.GoverConfigPathMID[s]),config.GoverConfigMID[s]);
        }
        for (size_t s = 1; s < config.GoverConfigPathBIG.size(); s++) {
            utils.Writer(GETGovernorPath(config.policy3, config.GOVER_BIGCORE, config.GoverConfigPathBIG[s]),config.GoverConfigBIG[s]);
        }
        for (size_t s = 1; s < config.GoverConfigPathMAX.size(); s++) {
            utils.Writer(GETGovernorPath(config.policy4, config.GOVER_MAXCORE, config.GoverConfigPathMAX[s]),config.GoverConfigMAX[s]);
        }
    }

    void UCLAMP(){
        int a = utils.Writer("/dev/cpuctl/background/cpu.uclamp.max", config.BACK_C_UCLAMP_MAX);
        if (a < 0) return; 
        utils.Writer("/dev/cpuctl/background/cpu.uclamp.min", config.BACK_C_UCLAMP_MIN);
        utils.Writer("/dev/cpuctl/top-app/cpu.uclamp.max", config.TOP_APP_C_UCLAMP_MAX);
        utils.Writer("/dev/cpuctl/top-app/cpu.uclamp.min", config.TOP_APP_C_UCLAMP_MIN);
        utils.Writer("/dev/cpuctl/system-background/cpu.uclamp.max", config.S_BACK_C_UCLAMP_MAX);
        utils.Writer("/dev/cpuctl/system-background/cpu.uclamp.min", config.S_BACK_C_UCLAMP_MIN);
        utils.Writer("/dev/cpuctl/system/cpu.uclamp.max", config.SYS_C_UCLAMP_MAX);
        utils.Writer("/dev/cpuctl/system/cpu.uclamp.min", config.SYS_C_UCLAMP_MIN);
        utils.Writer("/dev/cpuctl/foreground/cpu.uclamp.max", config.F_C_UCLAMP_MAX);
        utils.Writer("/dev/cpuctl/foreground/cpu.uclamp.min", config.F_C_UCLAMP_MIN);
    }

    void CpuSet(){
        utils.Writer("/dev/cpuset/background/cpus", config.CPUSET_Background);
        utils.Writer("/dev/cpuset/top-app/cpus", config.CPUSET_Top_app);
        utils.Writer("/dev/cpuset/system-background/cpus", config.CPUSET_System_Background);
        utils.Writer("/dev/cpuset/foreground/cpus", config.CPUSET_Foreground);
    }

    void SYS(){
        for (size_t s = 1; s < config.SysConfigPath.size(); s++) {
            utils.Writer(config.SysConfigPath[s],config.SysConfig[s]);
        }
    }

    void CFS(){
        utils.Writer("/proc/sys/kernel/sched_wakeup_granularity_ns", config.Sched_wakeup_granularity_ns);
        int a = utils.Writer("/proc/sys/kernel/sched_migration_cost_ns", config.Sched_migration_cost_ns);
        if (a < 0) {
            utils.log("ERROR: CFS调整失败");
        }
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
        if (config.lv != SZE_VERSION) {
            utils.log("WARN: !!!!!!!!  配置版本与SZE_NEXT版本不一致，请检查！");
            cout << "WARN: 配置版本与SZE_NEXT版本不一致，请检查！" << endl;
            exit(1);
        }else {
            utils.log("INFO: 配置版本与SZE_NEXT版本一致");
            utils.log("INFO: 可以放心使用！");
        }
        config.ReadLogConfig();
        if (config.Debuglog) {
            utils.Debug = true;
            utils.log("WARN: 调试日志已开启");
        } else {
            utils.Debug = false;
            utils.log("WARN: 调试日志未开启");
        
        }
        
    }

};

#endif
