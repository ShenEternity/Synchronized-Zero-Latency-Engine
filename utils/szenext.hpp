
#ifndef SZENEXT_HPP
#define SZENEXT_HPP

#include "../tool/readconfig.hpp"
#include "../tool/mods.hpp"
#include "utils.hpp"
#include "unistd.h"
#include <iostream>
#include <string>
#include <sys/inotify.h>
using namespace std;
class SZENEXT {
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
        config.ReadPnum();
        config.ReadConfig();
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
                    PDMODS();
                }
                i += sizeof(inotify_event) + eve->len;
            }
        }
    }

    string GETFreqPath(string* policy){
        return "/sys/devices/system/cpu/cpufreq/policy" + *policy + "/scaling_max_freq";
    }

    string GETGoverPath(string* policy){
        return "/sys/devices/system/cpu/cpufreq/policy/" + *policy + "/Governor";
    }

    string GETGovernorPath(string* policy, string* gover, string* path){
        return "/sys/devices/system/cpu/cpufreq/policy/" + *policy + *gover + "/" + *path;
    }


    void PDMODS(){
            if (Mods == "powersave")
            {
                    utils.Writer(GETFreqPath(config.MINpolicy),*config.POW_MINCORE);
                    utils.Writer(GETFreqPath(config.MIDpolicy),*config.POW_MIDCORE);
                    if (*config.policynum == 3) {
                        utils.Writer(GETFreqPath(config.BIGpolicy),*config.POW_BIGCORE);
                    }
                    else if (*config.policynum == 4) {
                        utils.Writer(GETFreqPath(config.BIGpolicy),*config.POW_BIGCORE);
                        utils.Writer(GETFreqPath( config.EBIGpolicy),*config.POW_EBIGCORE);
                    }
                if (Mods != Mtemp)
                { 
                    utils.log(("INFO:"+Mods+"模式启动").c_str());
                    Mtemp = Mods;
                }
            
            }

            else if(Mods == "balance")
            {

                    utils.Writer(GETFreqPath(config.MINpolicy),*config.BAN_MINCORE);
                    utils.Writer(GETFreqPath(config.MIDpolicy),*config.BAN_MIDCORE);
                    if (*config.policynum == 3) {
                        utils.Writer(GETFreqPath(config.BIGpolicy),*config.BAN_BIGCORE);
                    }
                    else if (*config.policynum == 4) {
                        utils.Writer(GETFreqPath(config.BIGpolicy),*config.BAN_BIGCORE);
                        utils.Writer(GETFreqPath(config.EBIGpolicy),*config.BAN_EBIGCORE);
                    }

                if (Mods != Mtemp)
                {
                    utils.log(("INFO:"+Mods+"模式启动").c_str());
                    Mtemp = Mods;
                }

            }

            else if (Mods == "performance")
            {
                    utils.Writer(GETFreqPath(config.MINpolicy),*config.PER_MINCORE);
                    utils.Writer(GETFreqPath(config.MIDpolicy),*config.PER_MIDCORE);
                    if (*config.policynum == 3) {
                        utils.Writer(GETFreqPath(config.BIGpolicy),*config.PER_BIGCORE);
                    }
                    else if (*config.policynum == 4) {
                        utils.Writer(GETFreqPath(config.BIGpolicy),*config.PER_BIGCORE);
                        utils.Writer(GETFreqPath(config.EBIGpolicy),*config.PER_EBIGCORE);
                    }

                if (Mods != Mtemp)
                {
                    utils.log(("INFO:"+Mods+"模式启动").c_str());
                    Mtemp = Mods;
                }
            }

            else if (Mods == "fast")
            {
                    utils.Writer(GETFreqPath(config.MINpolicy),*config.FAS_MINCORE);
                    utils.Writer(GETFreqPath(config.MIDpolicy),*config.FAS_MIDCORE);
                    if (*config.policynum == 3) {
                        utils.Writer(GETFreqPath(config.BIGpolicy),*config.FAS_BIGCORE);
                    }
                    else if (*config.policynum == 4) {
                        utils.Writer(GETFreqPath(config.BIGpolicy),*config.FAS_BIGCORE);
                        utils.Writer(GETFreqPath(config.EBIGpolicy),*config.FAS_EBIGCORE);
                    
                    }

                if (Mods != Mtemp)
                {
                    utils.log(("INFO:"+Mods+"模式启动").c_str());
                    Mtemp = Mods;
                }
            }
    }


    void COC (){
        while (1)
        {
            auto c1 = utils.readCpuStats();
            sleep(2);
            auto c2 = utils.readCpuStats();
            OC = utils.calculateTotalCpuLoad(c1,c2);
        }
    }


    void init(){
        config.Readname();
        utils.log(("******调度配置：" + config.name).c_str());
        utils.log(("******配置版本：" + config.lv).c_str());
        utils.log(("******配置作者：" + config.Out).c_str());


    }

};

#endif
