
#ifndef SZENEXT_HPP
#define SZENEXT_HPP

#include "../tool/readconfig.hpp"
#include "../tool/mods.hpp"
#include "utils.hpp"
#include "unistd.h"
<<<<<<< HEAD
=======
#include <sys/inotify.h>
>>>>>>> 8fe1e18 (Update)
using namespace std;
class SZENEXT {
public:
    string Mods,Mtemp;
    Utils utils;
    Rconfig config;
    MODS mods;
<<<<<<< HEAD

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
=======
    int OC;
    const char * configfile = "/storage/emulated/0/Android/SZE_NEXT/config.txt";

    int fd = inotify_init();
    int wd = inotify_add_watch(fd, configfile, IN_MODIFY);
    char buff[1024];


    void Readx(){
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

    void PDMODS(){
>>>>>>> 8fe1e18 (Update)
        {
            
            if (Mods == "powersave")
            {

<<<<<<< HEAD
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
=======
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy0/scaling_max_freq",*config.POW_MINCORE);
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy4/scaling_max_freq",*config.POW_MIDCORE);
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy7/scaling_max_freq",*config.POW_BIGCORE);
>>>>>>> 8fe1e18 (Update)
                
                if (Mods != Mtemp)
                {
                    
                    utils.log(("INFO:"+Mods+"模式启动").c_str());
                    cout << "pow" << endl;
                    Mtemp = Mods;
                }
            
            }

            else if(Mods == "balance")
            {
<<<<<<< HEAD
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
=======

                
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy0/scaling_max_freq",*config.BAN_MINCORE);
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy4/scaling_max_freq",*config.BAN_MIDCORE);
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy7/scaling_max_freq",*config.BAN_BIGCORE);
                
>>>>>>> 8fe1e18 (Update)
                

                if (Mods != Mtemp)
                {
                    
                    cout << "ban" << endl;
                    utils.log(("INFO:"+Mods+"模式启动").c_str());
                    Mtemp = Mods;
                }

            }

            else if (Mods == "performace")
            {
<<<<<<< HEAD
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
=======
                
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy0/scaling_max_freq",*config.PER_MINCORE);
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy4/scaling_max_freq",*config.PER_MIDCORE);
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy7/scaling_max_freq",*config.PER_BIGCORE);
                
>>>>>>> 8fe1e18 (Update)

                if (Mods != Mtemp)
                {
                    
                    cout << "ban" << endl;
                    utils.log(("INFO:"+Mods+"模式启动").c_str());
                    Mtemp = Mods;
                }
            }

            else if (Mods == "fast")
            {
<<<<<<< HEAD
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
=======
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy0/scaling_max_freq",*config.FAS_MINCORE);
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy4/scaling_max_freq",*config.FAS_MIDCORE);
                    utils.Writer("/sys/devices/system/cpu/cpufreq/policy7/scaling_max_freq",*config.FAS_BIGCORE);
>>>>>>> 8fe1e18 (Update)
            
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
<<<<<<< HEAD
        
        
=======
>>>>>>> 8fe1e18 (Update)
    }


    void iniit(){
        config.Readname();
        utils.log(("******调度配置：" + config.name).c_str());
        utils.log(("******配置版本：" + config.lv).c_str());
        utils.log(("******配置作者：" + config.Out).c_str());


    }

};

#endif
