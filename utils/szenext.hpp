
#ifndef SZENEXT_HPP
#define SZENEXT_HPP

#include "../tool/readconfig.hpp"
#include "../tool/mods.hpp"
#include "utils.hpp"
#include "unistd.h"
#include <fstream>
#include <iostream>
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


    void Readx(){
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
                        ReadConfig(Mods);
                        PDMODS();
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

    void Readv(){
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


    void PDMODS(){
        utils.Writer(GETFreqPath(policy1), FREQ_MINCORE);
        utils.Writer(GETFreqPath(policy2), FREQ_MIDCORE);
        utils.Writer(GETFreqPath(policy3), FREQ_BIGCORE);
        utils.Writer(GETFreqPath(policy4), FREQ_MAXCORE);
        utils.Writer(GETGoverPath(policy1), GOVER_MINCORE);
        utils.Writer(GETGoverPath(policy2), GOVER_MIDCORE);
        utils.Writer(GETGoverPath(policy3), GOVER_BIGCORE);
        utils.Writer(GETGoverPath(policy4), GOVER_MAXCORE);
    }



    void init(){
        ReadName();
        utils.log(("******调度配置：" + name).c_str());
        utils.log(("******配置版本：" + lv).c_str());
        utils.log(("******配置作者：" + Out).c_str());


    }

};

#endif
