#include "utils/szenext.hpp"
#include <thread>
int main(){
    Utils utils;
    SZENEXT sze;
    utils.clearLog();
    sze.iniit();
    std::thread re (&SZENEXT::Readx,&sze); 
    re.join();
/*     Rconfig config;

    config.ReadConfig();

    config.print(); */
}


