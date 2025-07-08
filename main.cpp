#include "tool/readconfig.hpp"
#include "utils/szenext.hpp"
#include <iostream>
#include <thread>
int main(){
    Utils utils;
    SZENEXT sze;
    Rconfig config;

    utils.clearLog();
    sze.init();
    std::thread re (&SZENEXT::Readx,&sze);
    re.join();
/*     config.ReadName();
    config.ReadPolicy();
    config.ReadConfig("performace");
    config.printConfig(); */
}


