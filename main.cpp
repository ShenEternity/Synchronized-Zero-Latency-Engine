#include "tool/readconfig.hpp"
#include "utils/szenext.hpp"
#include <iostream>
#include <thread>
#include <unistd.h>
int main(){
    Utils utils;
    SZENEXT sze;
    Rconfig config;

    utils.clearLog();
    sze.init();
    std::thread re (&SZENEXT::FREEQ,&sze);
    sleep(3);
    std::thread rg (&SZENEXT::GOVER,&sze);
    sleep(3);
    std::thread rgc (&SZENEXT::GOVERCONFIG,&sze);
    rg.join();
    rgc.join();
    re.join();
/*     config.ReadName();
    config.ReadPolicy();
    config.ReadFreqConfig("performance");
    config.ReadGoverConfig("performance");
    config.ReadSetConfig();
    config.ReadGoverConfigConfig("performance");
    config.printConfig(); */
}


