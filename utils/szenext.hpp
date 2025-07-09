
#ifndef SZENEXT_HPP
#define SZENEXT_HPP

#include "../tool/readconfig.hpp"
#include "../tool/mods.hpp"
#include "utils.hpp"
#include "unistd.h"
#include <fstream>
#include <iostream>
#include <math.h>
#include <string>
#include <sys/inotify.h>
#include <thread>
using namespace std;
class SZENEXT:public Rconfig{
public:
    string Mods,Mtemp;
    Utils utils;
    Rconfig config;
    MODS mods;
    int OC;
    const char * configfile = "/storage/emulated/0/Android/SZE_NEXT/config.txt";

    int fd = inotify_init();
    int wd = inotify_add_watch(fd, configfile, IN_MODIFY);
    char buff[1024];


    void FREEQ(){
        ReadPolicy();
        while (1) {
            int len = read(fd, buff, sizeof(buff));
            for (char * i = buff; i < buff + len;) {
                auto *eve= reinterpret_cast<inotify_event*>(i);
                if (eve -> mask & IN_MODIFY) {
                    ifstream file = mods.GETC();
                    string modss;
                    while (getline(file,modss))
                    {
                        Mods = std::move(modss);
                        ReadFreqConfig(Mods);
                        FREQPDMODS();
                        if(Mods != Mtemp){
                            Mtemp = Mods;
                            utils.log(("模式已更新: " + Mods).c_str());
                        }
                    }
                }
                i += sizeof(inotify_event) + eve->len;  
            }
        }
    }

    void GOVER(){
        ReadSetConfig();
        if(!SetGover){
            utils.log("未启用Gover");
            return;
        }
        utils.log("已启用Gover");
        ReadPolicy();
        while (1) {
            int len = read(fd, buff, sizeof(buff));
            for (char * i = buff; i < buff + len;) {
                auto *eve= reinterpret_cast<inotify_event*>(i);
                if (eve -> mask & IN_MODIFY) {
                    ifstream file = mods.GETC();
                    string modss;
                    while (getline(file,modss))
                    {
                        Mods = std::move(modss);
                        ReadGoverConfig(Mods);
                        GOVERPDMODS();
                    }
                }
                i += sizeof(inotify_event) + eve->len;  
            }
        }
    }

    void GOVERCONFIG(){
        ReadSetConfig();
        if(!SetGoverConfig){
            utils.log("未启用GoverConfig");
            return;
        }
        utils.log("已启用GoverConfig");
        ReadPolicy();
        while (1) {
            int len = read(fd, buff, sizeof(buff));
            for (char * i = buff; i < buff + len;) {
                auto *eve= reinterpret_cast<inotify_event*>(i);
                if (eve -> mask & IN_MODIFY) {
                    ifstream file = mods.GETC();
                    string modss;
                    while (getline(file,modss))
                    {
                        Mods = std::move(modss);
                        sleep(1);
                        ReadGoverConfigConfig(Mods);
                        GOVERCONFIGPDMODS();

                    }
                }
                i += sizeof(inotify_event) + eve->len;
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
        utils.Writer(GETFreqPath(policy1), FREQ_MINCORE);
        utils.Writer(GETFreqPath(policy2), FREQ_MIDCORE);
        utils.Writer(GETFreqPath(policy3), FREQ_BIGCORE);
        utils.Writer(GETFreqPath(policy4), FREQ_MAXCORE);
    }

    void GOVERPDMODS(){
        utils.Writer(GETGoverPath(policy1), GOVER_MINCORE);
        utils.Writer(GETGoverPath(policy2), GOVER_MIDCORE);
        utils.Writer(GETGoverPath(policy3), GOVER_BIGCORE);
        utils.Writer(GETGoverPath(policy4), GOVER_MAXCORE);
    }

    void GOVERCONFIGPDMODS(){
        utils.Writer(GETGovernorPath(policy1, GOVER_MINCORE, GOVER_C_MINCORE1_PATH), GOVER_C_MINCORE1);
        utils.Writer(GETGovernorPath(policy2, GOVER_MIDCORE, GOVER_C_MIDCORE1_PATH), GOVER_C_MIDCORE1);
        utils.Writer(GETGovernorPath(policy3, GOVER_BIGCORE, GOVER_C_BIGCORE1_PATH), GOVER_C_BIGCORE1);
        utils.Writer(GETGovernorPath(policy4, GOVER_MAXCORE, GOVER_C_MAXCORE1_PATH), GOVER_C_MAXCORE1);

        utils.Writer(GETGovernorPath(policy1, GOVER_MINCORE, GOVER_C_MINCORE2_PATH), GOVER_C_MINCORE2);
        utils.Writer(GETGovernorPath(policy2, GOVER_MIDCORE, GOVER_C_MIDCORE2_PATH), GOVER_C_MIDCORE2);
        utils.Writer(GETGovernorPath(policy3, GOVER_BIGCORE, GOVER_C_BIGCORE2_PATH), GOVER_C_BIGCORE2);
        utils.Writer(GETGovernorPath(policy4, GOVER_MAXCORE, GOVER_C_MAXCORE2_PATH), GOVER_C_MAXCORE2);

        utils.Writer(GETGovernorPath(policy1, GOVER_MINCORE, GOVER_C_MINCORE3_PATH), GOVER_C_MINCORE3);
        utils.Writer(GETGovernorPath(policy2, GOVER_MIDCORE, GOVER_C_MIDCORE3_PATH), GOVER_C_MIDCORE3);
        utils.Writer(GETGovernorPath(policy3, GOVER_BIGCORE, GOVER_C_BIGCORE3_PATH), GOVER_C_BIGCORE3);
        utils.Writer(GETGovernorPath(policy4, GOVER_MAXCORE, GOVER_C_MAXCORE3_PATH), GOVER_C_MAXCORE3);
    }

    void init(){
        utils.log("人生路漫漫，每个人都有独属于自己的浪漫，多么想让这独属于自己的浪漫，永恒定格！");
        utils.log("SZE_NEXT已加载");
        ReadName();
        utils.log(("******调度配置：" + name).c_str());
        utils.log(("******配置版本：" + lv).c_str());
        utils.log(("******配置作者：" + Out).c_str());


    }

};

#endif
