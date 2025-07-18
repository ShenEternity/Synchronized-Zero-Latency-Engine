#include "tool/mods.hpp"
#include "tool/readconfig.hpp"
#include "utils/szenext.hpp"
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <sys/inotify.h>
#include <thread>
#include <unistd.h>

int main(){
    Rconfig config;
    MODS mods;
    Utils utils;
    SZENEXT sze;
    utils.clearLog();
    sze.init();
    config.ReadSetConfig();
    bool Enadle_n1 = true;
    bool Enadle_n2 = config.SetGover;
    bool Enadle_n3 = config.SetGoverConfig;


    if (Enadle_n2) {
        std::thread(&SZENEXT::GOVER, &sze, Enadle_n1, Enadle_n3).detach();
    }
    if (Enadle_n3) {
        std::thread(&SZENEXT::GOVERCONFIG, &sze, Enadle_n1, Enadle_n2).detach();
    }
    if (config.OifaceAndJoyose) {
        system("pm disable-user com.xiaomi.joyose; pm clear com.xiaomi.joyose");
        system("[ -n \"$(getprop persist.sys.oiface.enable)\" ] && setprop persist.sys.oiface.enable 0");
        utils.log("已禁用Joyose/Oiface");
    }
    sze.FREQ(Enadle_n2, Enadle_n3);
    

/*     config.ReadSysConfig("fast");
    config.print(); */
}


