<<<<<<< HEAD
#include "utils\szenext.hpp"
=======
#include "utils/szenext.hpp"
>>>>>>> 8fe1e18 (Update)
#include <thread>
int main(){
    Utils utils;
    SZENEXT sze;
    utils.clearLog();
    sze.iniit();
<<<<<<< HEAD
    std::thread re (&SZENEXT::Read,&sze); 
    sleep(5);
    std::thread oc (&SZENEXT::COC,&sze);
    sleep(5);
    std::thread pd (&SZENEXT::PDMODS,&sze);
    pd.join();
=======
    std::thread re (&SZENEXT::Readx,&sze); 
>>>>>>> 8fe1e18 (Update)
    re.join();
/*     Rconfig config;

    config.ReadConfig();

    config.print(); */
<<<<<<< HEAD
}
=======
}

>>>>>>> 8fe1e18 (Update)
