
#ifndef SZENEXT_HPP
#define SZENEXT_HPP

#include "../tool/readconfig.hpp"
#include "../tool/mods.hpp"
#include "utils.hpp"
#include "unistd.h"
using namespace std;
class SZENEXT {
public:
    string Mods,Mtemp;
    Utils utils;
    Rconfig config;
    MODS mods;

    void Read(){
        while (1)
        {
            sleep(1);
            ifstream file = mods.GETC();
            string modss;
            while (getline(file,modss))
            {
                Mods = move(modss);
            }
            cout << "READMODS" << endl;
        }
        
        
    }

    void PDMODS(){
        config.ReadConfig();
        while (1)
        {
            sleep(2);
            if (Mods == "powersave")
            {
                utils.Writer("/sys/devices/system/cpu/cpufreq/policy0/scaling_max_freq",*config.POW_MINCORE);
                utils.Writer("/sys/devices/system/cpu/cpufreq/policy4/scaling_max_freq",*config.POW_MIDCORE);
                utils.Writer("/sys/devices/system/cpu/cpufreq/policy7/scaling_max_freq",*config.POW_BIGCORE);

                if (Mods != Mtemp)
                {
                    
                    utils.log(("INFO:"+Mods+"模式启动").c_str());
                    cout << "pow" << endl;
                    Mtemp = Mods;
                }
            
            }

            else if(Mods == "balance")
            {
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy0/scaling_max_freq",*config.BAN_MINCORE);
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy4/scaling_max_freq",*config.BAN_MIDCORE);
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy7/scaling_max_freq",*config.BAN_BIGCORE);
                if (Mods != Mtemp)
                {
                    
                    cout << "ban" << endl;
                    utils.log(("INFO:"+Mods+"模式启动").c_str());
                    Mtemp = Mods;
                }

            }

            else if (Mods == "performace")
            {
                utils.Writer("/sys/devices/system/cpu/cpufreq/policy0/scaling_max_freq",*config.PER_MINCORE);
                utils.Writer("/sys/devices/system/cpu/cpufreq/policy4/scaling_max_freq",*config.PER_MIDCORE);
                utils.Writer("/sys/devices/system/cpu/cpufreq/policy7/scaling_max_freq",*config.PER_BIGCORE);

                if (Mods != Mtemp)
                {
                    
                    cout << "ban" << endl;
                    utils.log(("INFO:"+Mods+"模式启动").c_str());
                    Mtemp = Mods;
                }
            }

            else if (Mods == "fast")
            {
                utils.Writer("/sys/devices/system/cpu/cpufreq/policy0/scaling_max_freq",*config.FAS_MINCORE);
                utils.Writer("/sys/devices/system/cpu/cpufreq/policy4/scaling_max_freq",*config.FAS_MIDCORE);
                utils.Writer("/sys/devices/system/cpu/cpufreq/policy7/scaling_max_freq",*config.FAS_BIGCORE);
            
                if (Mods != Mtemp)
                {
                    
                    cout << "ban" << endl;
                    utils.log(("INFO:"+Mods+"模式启动").c_str());
                    Mtemp = Mods;
                }
            }
        }
    }

    void iniit(){
        config.ReadConfig();
        utils.log(("******调度配置：" + config.name).c_str());
        utils.log(("******配置版本：" + config.lv).c_str());
        utils.log(("******配置作者：" + config.Out).c_str());


    }

};

#endif
