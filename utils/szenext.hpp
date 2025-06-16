
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

    int OC;

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
            
            if (Mods == "powersave")
            {

                if (OC >= *config.POW_BOOST_OC)
                {
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy0/scaling_max_freq",*config.POW_BOOST_MINCORE);
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy4/scaling_max_freq",*config.POW_BOOST_MIDCORE);
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy7/scaling_max_freq",*config.POW_BOOST_BIGCORE);
                    utils.log(("CPU占用超" + to_string(*config.POW_BOOST_OC) + "  BOOST").c_str());
                }
                else
                {
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy0/scaling_max_freq",*config.POW_MINCORE);
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy4/scaling_max_freq",*config.POW_MIDCORE);
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy7/scaling_max_freq",*config.POW_BIGCORE);
                }
                
                if (Mods != Mtemp)
                {
                    
                    utils.log(("INFO:"+Mods+"模式启动").c_str());
                    cout << "pow" << endl;
                    Mtemp = Mods;
                }
            
            }

            else if(Mods == "balance")
            {
                if (OC >= *config.BAN_BOOST_OC)
                {
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy0/scaling_max_freq",*config.BAN_BOOST_MINCORE);
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy4/scaling_max_freq",*config.BAN_BOOST_MIDCORE);
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy7/scaling_max_freq",*config.BAN_BOOST_BIGCORE);
                    utils.log(("CPU占用超" + to_string(*config.BAN_BOOST_OC) + "  BOOST").c_str());
                }
                else
                {
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy0/scaling_max_freq",*config.BAN_MINCORE);
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy4/scaling_max_freq",*config.BAN_MIDCORE);
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy7/scaling_max_freq",*config.BAN_BIGCORE);
                }
                

                if (Mods != Mtemp)
                {
                    
                    cout << "ban" << endl;
                    utils.log(("INFO:"+Mods+"模式启动").c_str());
                    Mtemp = Mods;
                }

            }

            else if (Mods == "performace")
            {
                if (OC >= *config.PER_BOOST_OC)
                {
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy0/scaling_max_freq",*config.PER_BOOST_MINCORE);
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy4/scaling_max_freq",*config.PER_BOOST_MIDCORE);
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy7/scaling_max_freq",*config.PER_BOOST_BIGCORE);
                    utils.log(("CPU占用超" + to_string(*config.PER_BOOST_OC) + "  BOOST").c_str());
                }
                else
                {
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy0/scaling_max_freq",*config.PER_MINCORE);
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy4/scaling_max_freq",*config.PER_MIDCORE);
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy7/scaling_max_freq",*config.PER_BIGCORE);
                }

                if (Mods != Mtemp)
                {
                    
                    cout << "ban" << endl;
                    utils.log(("INFO:"+Mods+"模式启动").c_str());
                    Mtemp = Mods;
                }
            }

            else if (Mods == "fast")
            {
                if (OC >= *config.FAS_BOOST_OC)
                {
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy0/scaling_max_freq",*config.FAS_BOOST_MINCORE);
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy4/scaling_max_freq",*config.FAS_BOOST_MIDCORE);
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy7/scaling_max_freq",*config.FAS_BOOST_BIGCORE);
                    utils.log(("CPU占用超" + to_string(*config.FAS_BOOST_OC) + "  BOOST").c_str());
                }
                else
                {
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy0/scaling_max_freq",*config.FAS_MINCORE);
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy4/scaling_max_freq",*config.FAS_MIDCORE);
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy7/scaling_max_freq",*config.FAS_BIGCORE);
                }
            
                if (Mods != Mtemp)
                {
                    
                    cout << "ban" << endl;
                    utils.log(("INFO:"+Mods+"模式启动").c_str());
                    Mtemp = Mods;
                }
            }
            sleep(2);
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


    void iniit(){
        config.Readname();
        utils.log(("******调度配置：" + config.name).c_str());
        utils.log(("******配置版本：" + config.lv).c_str());
        utils.log(("******配置作者：" + config.Out).c_str());


    }

};

#endif
