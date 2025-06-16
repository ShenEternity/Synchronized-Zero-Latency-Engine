<<<<<<< HEAD
#include "utils\szenext.hpp"
#include <thread>
int main(){
    Utils utils;
    SZENEXT sze;
    utils.clearLog();
    sze.iniit();
    std::thread re (&SZENEXT::Read,&sze); 
    sleep(5);
    std::thread oc (&SZENEXT::COC,&sze);
    sleep(5);
    std::thread pd (&SZENEXT::PDMODS,&sze);
    pd.join();
    re.join();
/*     Rconfig config;

    config.ReadConfig();

    config.print(); */
=======
#include "utils\szenext.hpp"
#include <thread>
int main(){
    Utils utils;
    SZENEXT sze;
    utils.clearLog();
    sze.iniit();
    std::thread re (&SZENEXT::Read,&sze); 
    sleep(5);
    std::thread pd (&SZENEXT::PDMODS,&sze);
    pd.join();
    re.join();
>>>>>>> 80eb3b0d70d08b16b33fe6226096c0c8fafeb3e0
}