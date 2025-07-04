#ifndef RCONFIG_HPP
#define RCONFIG_HPP



#include <cstdint>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include "json.hpp"
#include "../utils/utils.hpp"

using json = nlohmann::json;

using namespace std;


class Rconfig{
public:
    const char* ConfigPath = "/storage/emulated/0/Android/SZE_NEXT/config.json";
    string name, lv, Out; 
    Utils utils;
    int* POW_MINCORE = nullptr;
    int* POW_MIDCORE = nullptr;
    int* POW_BIGCORE = nullptr;
    int* POW_EBIGCORE = nullptr;

    int* BAN_MINCORE = nullptr;
    int* BAN_MIDCORE = nullptr;
    int* BAN_BIGCORE = nullptr;
    int* BAN_EBIGCORE = nullptr;

    int* PER_MINCORE = nullptr;
    int* PER_MIDCORE = nullptr;
    int* PER_BIGCORE = nullptr;
    int* PER_EBIGCORE = nullptr;

    int* FAS_MINCORE = nullptr;
    int* FAS_MIDCORE = nullptr;
    int* FAS_BIGCORE = nullptr;
    int* FAS_EBIGCORE = nullptr;

    int* policynum = nullptr;
    string* MINpolicy = nullptr;
    string* MIDpolicy = nullptr;
    string* BIGpolicy = nullptr;
    string* EBIGpolicy = nullptr;

    int* Setnum = nullptr;
    string* Setname1 = nullptr;
    string* Setname2 = nullptr;
    string* Setname3 = nullptr;


    string* POW_MIN_Gover = nullptr;
    string* BAN_MIN_Gover = nullptr;
    string* PER_MIN_Gover = nullptr;
    string* FAS_MIN_Gover = nullptr;

    string* POW_MID_Gover = nullptr;
    string* BAN_MID_Gover = nullptr;
    string* PER_MID_Gover = nullptr;
    string* FAS_MID_Gover = nullptr;

    string* POW_BIG_Gover = nullptr;
    string* BAN_BIG_Gover = nullptr;
    string* PER_BIG_Gover = nullptr;
    string* FAS_BIG_Gover = nullptr;

    string* POW_EBIG_Gover = nullptr;
    string* BAN_EBIG_Gover = nullptr;
    string* PER_EBIG_Gover = nullptr;
    string* FAS_EBIG_Gover = nullptr;


    int* POW_SetG_MIN_N1 = nullptr;
    int* POW_SetG_MIN_N2 = nullptr;
    int* POW_SetG_MIN_N3 = nullptr;

    int* BAN_SetG_MIN_N1 = nullptr;
    int* BAN_SetG_MIN_N2 = nullptr;
    int* BAN_SetG_MIN_N3 = nullptr;

    int* PER_SetG_MIN_N1 = nullptr;
    int* PER_SetG_MIN_N2 = nullptr;
    int* PER_SetG_MIN_N3 = nullptr;

    int* FAS_SetG_MIN_N1 = nullptr;
    int* FAS_SetG_MIN_N2 = nullptr;
    int* FAS_SetG_MIN_N3 = nullptr;
    


    int* POW_SetG_MID_N1 = nullptr;
    int* POW_SetG_MID_N2 = nullptr;
    int* POW_SetG_MID_N3 = nullptr;

    int* BAN_SetG_MID_N1 = nullptr;
    int* BAN_SetG_MID_N2 = nullptr;
    int* BAN_SetG_MID_N3 = nullptr;

    int* PER_SetG_MID_N1 = nullptr;
    int* PER_SetG_MID_N2 = nullptr;
    int* PER_SetG_MID_N3 = nullptr;

    int* FAS_SetG_MID_N1 = nullptr;
    int* FAS_SetG_MID_N2 = nullptr;
    int* FAS_SetG_MID_N3 = nullptr;

    int* POW_SetG_BIG_N1 = nullptr;
    int* POW_SetG_BIG_N2 = nullptr;
    int* POW_SetG_BIG_N3 = nullptr;

    int* BAN_SetG_BIG_N1 = nullptr;
    int* BAN_SetG_BIG_N2 = nullptr;
    int* BAN_SetG_BIG_N3 = nullptr;

    int* PER_SetG_BIG_N1 = nullptr;
    int* PER_SetG_BIG_N2 = nullptr;
    int* PER_SetG_BIG_N3 = nullptr;

    int* FAS_SetG_BIG_N1 = nullptr;
    int* FAS_SetG_BIG_N2 = nullptr;
    int* FAS_SetG_BIG_N3 = nullptr;


    int* POW_SetG_EBIG_N1 = nullptr;
    int* POW_SetG_EBIG_N2 = nullptr;
    int* POW_SetG_EBIG_N3 = nullptr;

    int* BAN_SetG_EBIG_N1 = nullptr;
    int* BAN_SetG_EBIG_N2 = nullptr;
    int* BAN_SetG_EBIG_N3 = nullptr;

    int* PER_SetG_EBIG_N1 = nullptr;
    int* PER_SetG_EBIG_N2 = nullptr;
    int* PER_SetG_EBIG_N3 = nullptr;

    int* FAS_SetG_EBIG_N1 = nullptr;
    int* FAS_SetG_EBIG_N2 = nullptr;
    int* FAS_SetG_EBIG_N3 = nullptr;

    



    ~Rconfig(){
        delete POW_MINCORE;
        delete POW_MIDCORE;
        delete POW_BIGCORE;
        delete POW_EBIGCORE;
        delete BAN_MINCORE;
        delete BAN_MIDCORE;
        delete BAN_BIGCORE;
        delete BAN_EBIGCORE;
        delete PER_MINCORE;
        delete PER_MIDCORE;
        delete PER_BIGCORE;
        delete PER_EBIGCORE;
        delete FAS_MINCORE;
        delete FAS_MIDCORE;
        delete FAS_BIGCORE;
        delete FAS_EBIGCORE;

        delete MIDpolicy;
        delete MINpolicy;
        delete BIGpolicy;
        delete EBIGpolicy;

        delete policynum;
    
        delete Setnum;
        delete Setname1;
        delete Setname2;
        delete Setname3;


        delete POW_SetG_MIN_N1;
        delete POW_SetG_MIN_N2;
        delete POW_SetG_MIN_N3;

        delete BAN_SetG_MIN_N1;
        delete BAN_SetG_MIN_N2;
        delete BAN_SetG_MIN_N3;

        delete PER_SetG_MIN_N1;
        delete PER_SetG_MIN_N2;
        delete PER_SetG_MIN_N3;

        delete FAS_SetG_MIN_N1;
        delete FAS_SetG_MIN_N2;
        delete FAS_SetG_MIN_N3;

        delete POW_SetG_MID_N1;
        delete POW_SetG_MID_N2;
        delete POW_SetG_MID_N3;

        delete BAN_SetG_MID_N1;
        delete BAN_SetG_MID_N2;
        delete BAN_SetG_MID_N3;

        delete PER_SetG_MID_N1;
        delete PER_SetG_MID_N2;
        delete PER_SetG_MID_N3;

        delete FAS_SetG_MID_N1;
        delete FAS_SetG_MID_N2;
        delete FAS_SetG_MID_N3;

        delete POW_SetG_BIG_N1;
        delete POW_SetG_BIG_N2;
        delete POW_SetG_BIG_N3;

        delete BAN_SetG_BIG_N1;
        delete BAN_SetG_BIG_N2;
        delete BAN_SetG_BIG_N3;

        delete PER_SetG_BIG_N1;
        delete PER_SetG_BIG_N2;
        delete PER_SetG_BIG_N3;

        delete FAS_SetG_BIG_N1;
        delete FAS_SetG_BIG_N2;
        delete FAS_SetG_BIG_N3;

        delete POW_SetG_EBIG_N1;
        delete POW_SetG_EBIG_N2;
        delete POW_SetG_EBIG_N3;

        delete BAN_SetG_EBIG_N1;
        delete BAN_SetG_EBIG_N2;
        delete BAN_SetG_EBIG_N3;

        delete PER_SetG_EBIG_N1;
        delete PER_SetG_EBIG_N2;
        delete PER_SetG_EBIG_N3;

        delete FAS_SetG_EBIG_N1;
        delete FAS_SetG_EBIG_N2;
        delete FAS_SetG_EBIG_N3;

        delete POW_MIN_Gover;
        delete BAN_MIN_Gover;
        delete PER_MIN_Gover;
        delete FAS_MIN_Gover;
        delete POW_MID_Gover;
        delete BAN_MID_Gover;
        delete PER_MID_Gover;
        delete FAS_MID_Gover;
        delete POW_BIG_Gover;
        delete BAN_BIG_Gover;
        delete PER_BIG_Gover;
        delete FAS_BIG_Gover;
        delete POW_EBIG_Gover;
        delete BAN_EBIG_Gover;
        delete PER_EBIG_Gover;
        delete FAS_EBIG_Gover;

        
/*         delete POW_BOOST_MINCORE;
        delete POW_BOOST_MIDCORE;
        delete POW_BOOST_BIGCORE;
        delete BAN_BOOST_MINCORE;
        delete BAN_BOOST_MIDCORE;
        delete BAN_BOOST_BIGCORE;
        delete PER_BOOST_MINCORE;
        delete PER_BOOST_MIDCORE;
        delete PER_BOOST_BIGCORE;
        delete FAS_BOOST_MINCORE;
        delete FAS_BOOST_MIDCORE;
        delete FAS_BOOST_BIGCORE;
        delete POW_BOOST_OC;
        delete BAN_BOOST_OC;
        delete PER_BOOST_OC;
        delete FAS_BOOST_OC; */

    }


public:
    void ReadPnum(){
        ifstream file(ConfigPath);
        if (file.is_open()) {
            json config;
            file >> config;
            policynum = new int(config["Policy"]["policynum"]);
        }
        else{
            utils.log("配置文件不存在！");
        }
    }

    void ReadSnum(){
        ifstream file(ConfigPath);
        if (file.is_open()) {
            json config;
            file >> config;
            Setnum = new int(config["GoverPath"]["SetNum"]);
        }
        else{
            utils.log("配置文件不存在！");
        }
    }

    void ReadConfig(){
        ReadPnum();
        ifstream file(ConfigPath);
        if (file.is_open()) {
            json config;
            file >> config;

            POW_MINCORE = new int(config["powersave"]["FREQ"]["MINCORE"]);
            BAN_MINCORE = new int(config["balance"]["FREQ"]["MINCORE"]);
            PER_MINCORE = new int(config["performace"]["FREQ"]["MINCORE"]);
            FAS_MINCORE = new int(config ["fast"]["FREQ"]["MINCORE"]);

            POW_MIDCORE = new int(config["powersave"]["FREQ"]["MIDCORE"]);
            BAN_MIDCORE = new int(config["balance"]["FREQ"]["MIDCORE"]);
            PER_MIDCORE = new int(config["performace"]["FREQ"]["MIDCORE"]);
            FAS_MIDCORE = new int(config ["fast"]["FREQ"]["MIDCORE"]);

            MINpolicy = new string(config["Policy"]["policy"]["policy1"]);
            MIDpolicy = new string(config["Policy"]["policy"]["policy2"]);

            POW_MIN_Gover = new string(config["powersave"]["Governor"]["MINCORE"]);
            BAN_MIN_Gover = new string(config["balance"]["Governor"]["MINCORE"]);
            PER_MIN_Gover = new string(config["performace"]["Governor"]["MINCORE"]);
            FAS_MIN_Gover = new string(config["fast"]["Governor"]["MINCORE"]);

            POW_MID_Gover = new string(config["powersave"]["Governor"]["MIDCORE"]);
            BAN_MID_Gover = new string(config["balance"]["Governor"]["MIDCORE"]);
            PER_MID_Gover = new string(config["performace"]["Governor"]["MIDCORE"]);
            FAS_MID_Gover = new string(config["fast"]["Governor"]["MIDCORE"]);

            if (*policynum == 3) {

                BIGpolicy = new string(config["Policy"]["policy"]["policy3"]);
                POW_BIGCORE = new int(config["powersave"]["FREQ"]["BIGCORE"]);
                BAN_BIGCORE = new int(config["balance"]["FREQ"]["BIGCORE"]);
                PER_BIGCORE = new int(config["performace"]["FREQ"]["BIGCORE"]);
                FAS_BIGCORE = new int(config ["fast"]["FREQ"]["BIGCORE"]);
                POW_BIG_Gover = new string(config["powersave"]["Governor"]["BIGCORE"]);
                BAN_BIG_Gover = new string(config["balance"]["Governor"]["BIGCORE"]);
                PER_BIG_Gover = new string(config["performace"]["Governor"]["BIGCORE"]);
                FAS_BIG_Gover = new string(config["fast"]["Governor"]["BIGCORE"]);
            }

            else if (*policynum == 4) {
                BIGpolicy = new string(config["Policy"]["policy"]["policy3"]);
                EBIGpolicy = new string(config["Policy"]["policy"]["policy4"]);
                POW_BIGCORE = new int(config["powersave"]["FREQ"]["BIGCORE"]);
                BAN_BIGCORE = new int(config["balance"]["FREQ"]["BIGCORE"]);
                PER_BIGCORE = new int(config["performace"]["FREQ"]["BIGCORE"]);
                FAS_BIGCORE = new int(config ["fast"]["FREQ"]["BIGCORE"]);
                
                POW_EBIGCORE = new int(config["powersave"]["FREQ"]["EBIGCORE"]);
                BAN_EBIGCORE = new int(config["balance"]["FREQ"]["EBIGCORE"]);
                PER_EBIGCORE = new int(config["performace"]["FREQ"]["EBIGCORE"]);
                FAS_EBIGCORE = new int(config ["fast"]["FREQ"]["EBIGCORE"]);
                POW_BIG_Gover = new string(config["powersave"]["Governor"]["BIGCORE"]);
                BAN_BIG_Gover = new string(config["balance"]["Governor"]["BIGCORE"]);
                PER_BIG_Gover = new string(config["performace"]["Governor"]["BIGCORE"]);
                FAS_BIG_Gover = new string(config["fast"]["Governor"]["BIGCORE"]);
                POW_EBIG_Gover = new string(config["powersave"]["Governor"]["EBIGCORE"]);
                BAN_EBIG_Gover = new string(config["balance"]["Governor"]["EBIGCORE"]);
                PER_EBIG_Gover = new string(config["performace"]["Governor"]["EBIGCORE"]);
                FAS_EBIG_Gover = new string(config["fast"]["Governor"]["EBIGCORE"]);

            
            }
/*             POW_BOOST_MINCORE = new int(config["powersave"]["BOOST"]["MINCORE"]);
            POW_BOOST_MIDCORE = new int(config["powersave"]["BOOST"]["MIDCORE"]);
            POW_BOOST_BIGCORE = new int(config["powersave"]["BOOST"]["BIGCORE"]);

            BAN_BOOST_MINCORE = new int(config["balance"]["BOOST"]["MINCORE"]);
            BAN_BOOST_MIDCORE = new int(config["balance"]["BOOST"]["MIDCORE"]);
            BAN_BOOST_BIGCORE = new int(config["balance"]["BOOST"]["BIGCORE"]);

            PER_BOOST_MINCORE = new int(config["performace"]["BOOST"]["MINCORE"]);
            PER_BOOST_MIDCORE = new int(config["performace"]["BOOST"]["MIDCORE"]);
            PER_BOOST_BIGCORE = new int(config["performace"]["BOOST"]["BIGCORE"]);

            FAS_BOOST_MINCORE = new int(config["fast"]["BOOST"]["MINCORE"]);
            FAS_BOOST_MIDCORE = new int(config["fast"]["BOOST"]["MIDCORE"]);
            FAS_BOOST_BIGCORE = new int(config["fast"]["BOOST"]["BIGCORE"]);

            POW_BOOST_OC = new int(config["powersave"]["BOOST"]["OC"]);
            BAN_BOOST_OC = new int(config["balance"]["BOOST"]["OC"]);
            PER_BOOST_OC = new int(config["performace"]["BOOST"]["OC"]);
            FAS_BOOST_OC = new int(config["fast"]["BOOST"]["OC"]);
 */

        }else{
            utils.log("配置文件不存在！");
        }
    }

    void ReadSetConfig(){
        ReadSnum();
        ifstream file (ConfigPath);
        if (file.is_open()) {
            json config; 
            file >> config;
            if (*Setnum == 1) {
                Setname1 = new string(config["GoverPath"]["Setname1"]);
                POW_SetG_MIN_N1 = new int(config["powersave"]["SetGover"]["MINCORE"][*Setname1]);
                BAN_SetG_MIN_N1 = new int(config["balance"]["SetGover"]["MINCORE"][*Setname1]);
                PER_SetG_MIN_N1 = new int(config["performace"]["SetGover"]["MINCORE"][*Setname1]);
                FAS_SetG_MIN_N1 = new int(config["fast"]["SetGover"]["MINCORE"][*Setname1]);

                POW_SetG_MID_N1 = new int(config["powersave"]["SetGover"]["MIDCORE"][*Setname1]);
                BAN_SetG_MID_N1 = new int(config["balance"]["SetGover"]["MIDCORE"][*Setname1]);
                PER_SetG_MID_N1 = new int(config["performace"]["SetGover"]["MIDCORE"][*Setname1]);
                FAS_SetG_MID_N1 = new int(config["fast"]["SetGover"]["MIDCORE"][*Setname1]);

                if (*policynum == 3) {
                    POW_SetG_BIG_N1 = new int(config["powersave"]["SetGover"]["BIGCORE"][*Setname1]);
                    BAN_SetG_BIG_N1 = new int(config["balance"]["SetGover"]["BIGCORE"][*Setname1]);
                    PER_SetG_BIG_N1 = new int(config["performace"]["SetGover"]["BIGCORE"][*Setname1]);
                    FAS_SetG_BIG_N1 = new int(config["fast"]["SetGover"]["BIGCORE"][*Setname1]);
                }

                else if (*policynum == 4) {
                    POW_SetG_BIG_N1 = new int(config["powersave"]["SetGover"]["BIGCORE"][*Setname1]);
                    BAN_SetG_BIG_N1 = new int(config["balance"]["SetGover"]["BIGCORE"][*Setname1]);
                    PER_SetG_BIG_N1 = new int(config["performace"]["SetGover"]["BIGCORE"][*Setname1]);
                    FAS_SetG_BIG_N1 = new int(config["fast"]["SetGover"]["BIGCORE"][*Setname1]);

                    POW_SetG_EBIG_N1 = new int(config["powersave"]["SetGover"]["EBIGCORE"][*Setname1]);
                    BAN_SetG_EBIG_N1 = new int(config["balance"]["SetGover"]["EBIGCORE"][*Setname1]);
                    PER_SetG_EBIG_N1 = new int(config["performace"]["SetGover"]["EBIGCORE"][*Setname1]);
                    FAS_SetG_EBIG_N1 = new int(config["fast"]["SetGover"]["EBIGCORE"][*Setname1]);
                
                }



            }
            else if (*Setnum == 2) {
                Setname1 = new string(config["GoverPath"]["SetName1"]);
                Setname2 = new string(config["GoverPath"]["Setname2"]);
                POW_SetG_MIN_N1 = new int(config["powersave"]["SetGover"]["MINCORE"][*Setname1]);
                POW_SetG_MIN_N2 = new int(config["powersave"]["SetGover"]["MINCORE"][*Setname2]);
                BAN_SetG_MIN_N1 = new int(config["balance"]["SetGover"]["MINCORE"][*Setname1]);
                BAN_SetG_MIN_N2 = new int(config["balance"]["SetGover"]["MINCORE"][*Setname2]);
                PER_SetG_MIN_N1 = new int(config["performace"]["SetGover"]["MINCORE"][*Setname1]);
                PER_SetG_MIN_N2 = new int(config["performace"]["SetGover"]["MINCORE"][*Setname2]);
                FAS_SetG_MIN_N1 = new int(config["fast"]["SetGover"]["MINCORE"][*Setname1]);
                FAS_SetG_MIN_N2 = new int(config["fast"]["SetGover"]["MINCORE"][*Setname2]);

                POW_SetG_MID_N1 = new int(config["powersave"]["SetGover"]["MIDCORE"][*Setname1]);
                POW_SetG_MID_N2 = new int(config["powersave"]["SetGover"]["MIDCORE"][*Setname2]);
                BAN_SetG_MID_N1 = new int(config["balance"]["SetGover"]["MIDCORE"][*Setname1]);
                BAN_SetG_MID_N2 = new int(config["balance"]["SetGover"]["MIDCORE"][*Setname2]);
                PER_SetG_MID_N1 = new int(config["performace"]["SetGover"]["MIDCORE"][*Setname1]);
                PER_SetG_MID_N2 = new int(config["performace"]["SetGover"]["MIDCORE"][*Setname2]);
                FAS_SetG_MID_N1 = new int(config["fast"]["SetGover"]["MIDCORE"][*Setname1]);
                FAS_SetG_MID_N2 = new int(config["fast"]["SetGover"]["MIDCORE"][*Setname2]);

                if (*policynum == 3) {
                    POW_SetG_BIG_N1 = new int(config["powersave"]["SetGover"]["BIGCORE"][*Setname1]);
                    POW_SetG_BIG_N2 = new int(config["powersave"]["SetGover"]["BIGCORE"][*Setname2]);
                    BAN_SetG_BIG_N1 = new int(config["balance"]["SetGover"]["BIGCORE"][*Setname1]);
                    BAN_SetG_BIG_N2 = new int(config["balance"]["SetGover"]["BIGCORE"][*Setname2]);
                    PER_SetG_BIG_N1 = new int(config["performace"]["SetGover"]["BIGCORE"][*Setname1]);
                    PER_SetG_BIG_N2 = new int(config["performace"]["SetGover"]["BIGCORE"][*Setname2]);
                    FAS_SetG_BIG_N1 = new int(config["fast"]["SetGover"]["BIGCORE"][*Setname1]);
                    FAS_SetG_BIG_N2 = new int(config["fast"]["SetGover"]["BIGCORE"][*Setname2]);
                }

                else if (*policynum == 4) {
                    POW_SetG_BIG_N1 = new int(config["powersave"]["SetGover"]["BIGCORE"][*Setname1]);
                    POW_SetG_BIG_N2 = new int(config["powersave"]["SetGover"]["BIGCORE"][*Setname2]);
                    BAN_SetG_BIG_N1 = new int(config["balance"]["SetGover"]["BIGCORE"][*Setname1]);
                    BAN_SetG_BIG_N2 = new int(config["balance"]["SetGover"]["BIGCORE"][*Setname2]);
                    PER_SetG_BIG_N1 = new int(config["performace"]["SetGover"]["BIGCORE"][*Setname1]);
                    PER_SetG_BIG_N2 = new int(config["performace"]["SetGover"]["BIGCORE"][*Setname2]);
                    FAS_SetG_BIG_N1 = new int(config["fast"]["SetGover"]["BIGCORE"][*Setname1]);
                    FAS_SetG_BIG_N2 = new int(config["fast"]["SetGover"]["BIGCORE"][*Setname2]);

                    POW_SetG_EBIG_N1 = new int(config["powersave"]["SetGover"]["EBIGCORE"][*Setname1]);
                    POW_SetG_EBIG_N2 = new int(config["powersave"]["SetGover"]["EBIGCORE"][*Setname2]);
                    BAN_SetG_EBIG_N1 = new int(config["balance"]["SetGover"]["EBIGCORE"][*Setname1]);
                    BAN_SetG_EBIG_N2 = new int(config["balance"]["SetGover"]["EBIGCORE"][*Setname2]);
                    PER_SetG_EBIG_N1 = new int(config["performace"]["SetGover"]["EBIGCORE"][*Setname1]);
                    PER_SetG_EBIG_N2 = new int(config["performace"]["SetGover"]["EBIGCORE"][*Setname2]);
                    FAS_SetG_EBIG_N1 = new int(config["fast"]["SetGover"]["EBIGCORE"][*Setname1]);
                    FAS_SetG_EBIG_N2 = new int(config["fast"]["SetGover"]["EBIGCORE"][*Setname2]);
                }
            }
            
            else if (*Setnum == 3) {
                Setname1 = new string(config["GoverPath"]["SetName1"]);
                Setname2 = new string(config["GoverPath"]["SetName2"]);
                Setname3 = new string(config["GoverPath"]["SetName3"]);
                POW_SetG_MIN_N1 = new int(config["powersave"]["SetGover"]["MINCORE"][*Setname1]);
                POW_SetG_MIN_N2 = new int(config["powersave"]["SetGover"]["MINCORE"][*Setname2]);
                POW_SetG_MIN_N3 = new int(config["powersave"]["SetGover"]["MINCORE"][*Setname3]);
                BAN_SetG_MIN_N1 = new int(config["balance"]["SetGover"]["MINCORE"][*Setname1]);
                BAN_SetG_MIN_N2 = new int(config["balance"]["SetGover"]["MINCORE"][*Setname2]);
                BAN_SetG_MIN_N3 = new int(config["balance"]["SetGover"]["MINCORE"][*Setname3]);
                PER_SetG_MIN_N1 = new int(config["performace"]["SetGover"]["MINCORE"][*Setname1]);
                PER_SetG_MIN_N2 = new int(config["performace"]["SetGover"]["MINCORE"][*Setname2]);
                PER_SetG_MIN_N3 = new int(config["performace"]["SetGover"]["MINCORE"][*Setname3]);
                FAS_SetG_MIN_N1 = new int(config["fast"]["SetGover"]["MINCORE"][*Setname1]);
                FAS_SetG_MIN_N2 = new int(config["fast"]["SetGover"]["MINCORE"][*Setname2]);
                FAS_SetG_MIN_N3 = new int(config["fast"]["SetGover"]["MINCORE"][*Setname3]);

                POW_SetG_MID_N1 = new int(config["powersave"]["SetGover"]["MIDCORE"][*Setname1]);
                POW_SetG_MID_N2 = new int(config["powersave"]["SetGover"]["MIDCORE"][*Setname2]);
                POW_SetG_MID_N3 = new int(config["powersave"]["SetGover"]["MIDCORE"][*Setname3]);
                BAN_SetG_MID_N1 = new int(config["balance"]["SetGover"]["MIDCORE"][*Setname1]);
                BAN_SetG_MID_N2 = new int(config["balance"]["SetGover"]["MIDCORE"][*Setname2]);
                BAN_SetG_MID_N3 = new int(config["balance"]["SetGover"]["MIDCORE"][*Setname3]);
                PER_SetG_MID_N1 = new int(config["performace"]["SetGover"]["MIDCORE"][*Setname1]);
                PER_SetG_MID_N2 = new int(config["performace"]["SetGover"]["MIDCORE"][*Setname2]);
                PER_SetG_MID_N3 = new int(config["performace"]["SetGover"]["MIDCORE"][*Setname3]);
                FAS_SetG_MID_N1 = new int(config["fast"]["SetGover"]["MIDCORE"][*Setname1]);
                FAS_SetG_MID_N2 = new int(config["fast"]["SetGover"]["MIDCORE"][*Setname2]);
                FAS_SetG_MID_N3 = new int(config["fast"]["SetGover"]["MIDCORE"][*Setname3]);

                if (*policynum == 3) {
                    POW_SetG_BIG_N1 = new int(config["powersave"]["SetGover"]["BIGCORE"][*Setname1]);
                    POW_SetG_BIG_N2 = new int(config["powersave"]["SetGover"]["BIGCORE"][*Setname2]);
                    POW_SetG_BIG_N3 = new int(config["powersave"]["SetGover"]["BIGCORE"][*Setname3]);
                    BAN_SetG_BIG_N1 = new int(config["balance"]["SetGover"]["BIGCORE"][*Setname1]);
                    BAN_SetG_BIG_N2 = new int(config["balance"]["SetGover"]["BIGCORE"][*Setname2]);
                    BAN_SetG_BIG_N3 = new int(config["balance"]["SetGover"]["BIGCORE"][*Setname3]);
                    PER_SetG_BIG_N1 = new int(config["performace"]["SetGover"]["BIGCORE"][*Setname1]);
                    PER_SetG_BIG_N2 = new int(config["performace"]["SetGover"]["BIGCORE"][*Setname2]);
                    PER_SetG_BIG_N3 = new int(config["performace"]["SetGover"]["BIGCORE"][*Setname3]);
                    FAS_SetG_BIG_N1 = new int(config["fast"]["SetGover"]["BIGCORE"][*Setname1]);
                    FAS_SetG_BIG_N2 = new int(config["fast"]["SetGover"]["BIGCORE"][*Setname2]);
                    FAS_SetG_BIG_N3 = new int(config["fast"]["SetGover"]["BIGCORE"][*Setname3]);
                }

                
                if (*policynum == 4) {
                    POW_SetG_EBIG_N1 = new int(config["powersave"]["SetGover"]["EBIGCORE"][*Setname1]);
                    POW_SetG_EBIG_N2 = new int(config["powersave"]["SetGover"]["EBIGCORE"][*Setname2]);
                    POW_SetG_EBIG_N3 = new int(config["powersave"]["SetGover"]["EBIGCORE"][*Setname3]);
                    BAN_SetG_EBIG_N1 = new int(config["balance"]["SetGover"]["EBIGCORE"][*Setname1]);
                    BAN_SetG_EBIG_N2 = new int(config["balance"]["SetGover"]["EBIGCORE"][*Setname2]);
                    BAN_SetG_EBIG_N3 = new int(config["balance"]["SetGover"]["EBIGCORE"][*Setname3]);
                    PER_SetG_EBIG_N1 = new int(config["performace"]["SetGover"]["EBIGCORE"][*Setname1]);
                    PER_SetG_EBIG_N2 = new int(config["performace"]["SetGover"]["EBIGCORE"][*Setname2]);
                    PER_SetG_EBIG_N3 = new int(config["performace"]["SetGover"]["EBIGCORE"][*Setname3]);
                    FAS_SetG_EBIG_N1 = new int(config["fast"]["SetGover"]["EBIGCORE"][*Setname1]);
                    FAS_SetG_EBIG_N2 = new int(config["fast"]["SetGover"]["EBIGCORE"][*Setname2]);
                    FAS_SetG_EBIG_N3 = new int(config["fast"]["SetGover"]["EBIGCORE"][*Setname3]);
                }
                    
            }
        }
        

    }

    void Readname(){
        ifstream file(ConfigPath);
        if (file.is_open()) {
            json config;
            file >> config;
            name = config["Name"]["name"];
            lv = config["Name"]["lv"];
            Out = config["Name"]["aut"];
        }
    }

    void print (){
        cout << "name=" << name << endl;
        cout << "lv=" << lv << endl;
        cout << "aut=" << Out << endl;
        cout << "POW_MINCORE=" << *POW_MINCORE <<endl;
        cout << "POW_MIDCORE=" << *POW_MIDCORE <<endl;

        cout << "BAN_MINCORE=" << *BAN_MINCORE <<endl;
        cout << "BAN_MIDCORE=" << *BAN_MIDCORE <<endl;

        cout << "PER_MINCORE=" << *PER_MINCORE <<endl;
        cout << "PER_MIDCORE=" << *PER_MIDCORE <<endl;

        cout << "FAS_MINCORE=" << *FAS_MINCORE <<endl;
        cout << "FAS_MIDCORE=" << *FAS_MIDCORE <<endl;

        if (*policynum == 3) {
            cout << "POW_BIGCORE=" << *POW_BIGCORE << endl;
            cout << "BAN_BIGCORE=" << *BAN_BIGCORE << endl;
            cout << "PER_BIGCORE=" << *PER_BIGCORE << endl;
            cout << "FAS_BIGCORE=" << *FAS_BIGCORE << endl;

            cout << "BIGpolicy=" << *BIGpolicy << endl;
        }
        else if (*policynum == 4) {
            cout << "POW_BIGCORE=" << *POW_BIGCORE << endl;
            cout << "BAN_BIGCORE=" << *BAN_BIGCORE << endl;
            cout << "PER_BIGCORE=" << *PER_BIGCORE << endl;
            cout << "FAS_BIGCORE=" << *FAS_BIGCORE << endl;

            cout << "POW_EBIGCORE=" << *POW_EBIGCORE << endl;
            cout << "BAN_EBIGCORE=" << *BAN_EBIGCORE << endl;
            cout << "PER_EBIGCORE=" << *PER_EBIGCORE << endl;
            cout << "FAS_EBIGCORE=" << *FAS_EBIGCORE << endl;

            cout << "BIGpolicy=" << *BIGpolicy << endl;
            cout << "EBIGpolicy=" << *EBIGpolicy << endl;

        }

        if (*Setnum == 1) {
            cout << "Setname1=" << *Setname1 << endl;
            cout << "POW_SetG_MIN_N1=" << *POW_SetG_MIN_N1 << endl;
            cout << "BAN_SetG_MIN_N1=" << *BAN_SetG_MIN_N1 << endl;
            cout << "PER_SetG_MIN_N1=" << *PER_SetG_MIN_N1 << endl;
            cout << "FAS_SetG_MIN_N1=" << *FAS_SetG_MIN_N1 << endl;

            cout << "POW_SetG_MID_N1=" << *POW_SetG_MID_N1 << endl;
            cout << "BAN_SetG_MID_N1=" << *BAN_SetG_MID_N1 << endl;
            cout << "PER_SetG_MID_N1=" << *PER_SetG_MID_N1 << endl;
            cout << "FAS_SetG_MID_N1=" << *FAS_SetG_MID_N1 << endl;

            if (*policynum == 3) {
                cout << "POW_SetG_BIG_N1=" << *POW_SetG_BIG_N1 << endl;
                cout << "BAN_SetG_BIG_N1=" << *BAN_SetG_BIG_N1 << endl;
                cout << "PER_SetG_BIG_N1=" << *PER_SetG_BIG_N1 << endl;
                cout << "FAS_SetG_BIG_N1=" << *FAS_SetG_BIG_N1 << endl;
            }
            else if (*policynum == 4) {
                cout << "POW_SetG_BIG_N1=" << *POW_SetG_BIG_N1 << endl;
                cout << "BAN_SetG_BIG_N1=" << *BAN_SetG_BIG_N1 << endl;
                cout << "PER_SetG_BIG_N1=" << *PER_SetG_BIG_N1 << endl;
                cout << "FAS_SetG_BIG_N1=" << *FAS_SetG_BIG_N1 << endl;

                cout << "POW_SetG_EBIG_N1=" << *POW_SetG_EBIG_N1  << endl;
                cout << "BAN_SetG_EBIG_N1="  << *BAN_SetG_EBIG_N1  << endl;
                cout << "PER_SetG_EBIG_N1="  << *PER_SetG_EBIG_N1  << endl;
                cout << "FAS_SetG_EBIG_N1="  << *FAS_SetG_EBIG_N1  << endl;
            
            }


        }
        else if (*Setnum == 2) {
            cout <<"Setname1="<<*Setname1<<endl;
            cout <<"Setname2="<<*Setname2<<endl;
            cout <<"POW_SetG_MIN_N1="<<*POW_SetG_MIN_N1<<endl;
            cout <<"POW_SetG_MIN_N2="<<*POW_SetG_MIN_N2<<endl;
            cout <<"BAN_SetG_MIN_N1="<<*BAN_SetG_MIN_N1<<endl;
            cout <<"BAN_SetG_MIN_N2="<<*BAN_SetG_MIN_N2<<endl;
            cout <<"PER_SetG_MIN_N1="<<*PER_SetG_MIN_N1<<endl;
            cout <<"PER_SetG_MIN_N2="<<*PER_SetG_MIN_N2<<endl;
            cout <<"FAS_SetG_MIN_N1="<<*FAS_SetG_MIN_N1<<endl;
            cout <<"FAS_SetG_MIN_N2="<<*FAS_SetG_MIN_N2<<endl;
            cout <<"POW_SetG_MID_N1="<<*POW_SetG_MID_N1<<endl;
            cout <<"POW_SetG_MID_N2="<<*POW_SetG_MID_N2<<endl;
            cout <<"BAN_SetG_MID_N1="<<*BAN_SetG_MID_N1<<endl;
            cout <<"BAN_SetG_MID_N2="<<*BAN_SetG_MID_N2<<endl;
            cout <<"PER_SetG_MID_N1="<<*PER_SetG_MID_N1<<endl;
            cout <<"PER_SetG_MID_N2="<<*PER_SetG_MID_N2<<endl;
            cout <<"FAS_SetG_MID_N1="<<*FAS_SetG_MID_N1<<endl;
            cout <<"FAS_SetG_MID_N2="<<*FAS_SetG_MID_N2<<endl;
            if (*policynum == 3) {
                cout <<"POW_SetG_BIG_N1="<<*POW_SetG_BIG_N1<<endl;
                cout <<"POW_SetG_BIG_N2="<<*POW_SetG_BIG_N2<<endl;
                cout <<"BAN_SetG_BIG_N1="<<*BAN_SetG_BIG_N1<<endl;
                cout <<"BAN_SetG_BIG_N2="<<*BAN_SetG_BIG_N2<<endl;
                cout <<"PER_SetG_BIG_N1="<<*PER_SetG_BIG_N1<<endl;
                cout <<"PER_SetG_BIG_N2="<<*PER_SetG_BIG_N2<<endl;
                cout <<"FAS_SetG_BIG_N1="<<*FAS_SetG_BIG_N1<<endl;
                cout <<"FAS_SetG_BIG_N2="<<*FAS_SetG_BIG_N2<<endl;
            }
            else if (*policynum == 4) {
                cout <<"POW_SetG_BIG_N1="<<*POW_SetG_BIG_N1<<endl;
                cout <<"POW_SetG_BIG_N2="<<*POW_SetG_BIG_N2<<endl;
                cout <<"BAN_SetG_BIG_N1="<<*BAN_SetG_BIG_N1<<endl;
                cout <<"BAN_SetG_BIG_N2="<<*BAN_SetG_BIG_N2<<endl;
                cout <<"PER_SetG_BIG_N1="<<*PER_SetG_BIG_N1<<endl;
                cout <<"PER_SetG_BIG_N2="<<*PER_SetG_BIG_N2<<endl;
                cout <<"FAS_SetG_BIG_N1="<<*FAS_SetG_BIG_N1<<endl;
                cout <<"FAS_SetG_BIG_N2="<<*FAS_SetG_BIG_N2<<endl;

                cout <<"POW_SetG_EBIG_N1=" << *POW_SetG_EBIG_N1 << endl;
                cout <<"POW_SetG_EBIG_N2=" << *POW_SetG_EBIG_N2 << endl;
                cout <<"BAN_SetG_EBIG_N1=" << *BAN_SetG_EBIG_N1 << endl;
                cout <<"BAN_SetG_EBIG_N2=" << *BAN_SetG_EBIG_N2 << endl;
                cout <<"PER_SetG_EBIG_N1=" << *PER_SetG_EBIG_N1 << endl;
                cout <<"PER_SetG_EBIG_N2=" << *PER_SetG_EBIG_N2 << endl;
                cout <<"FAS_SetG_EBIG_N1=" << *FAS_SetG_EBIG_N1 << endl;
                cout <<"FAS_SetG_EBIG_N2=" << *FAS_SetG_EBIG_N2 << endl;
            
            }


        }
        else if (*Setnum == 3) {
            cout <<"Setname1="<<*Setname1<<endl;
            cout <<"Setname2="<<*Setname2<<endl;
            cout <<"Setname3="<<*Setname3<<endl;
            cout <<"POW_SetG_MIN_N1="<<*POW_SetG_MIN_N1<<endl;
            cout <<"POW_SetG_MIN_N2="<<*POW_SetG_MIN_N2<<endl;
            cout <<"POW_SetG_MIN_N3="<<*POW_SetG_MIN_N3<<endl;
            cout <<"BAN_SetG_MIN_N1="<<*BAN_SetG_MIN_N1<<endl;
            cout <<"BAN_SetG_MIN_N2="<<*BAN_SetG_MIN_N2<<endl;
            cout <<"BAN_SetG_MIN_N3="<<*BAN_SetG_MIN_N3<<endl;
            cout <<"PER_SetG_MIN_N1="<<*PER_SetG_MIN_N1<<endl;
            cout <<"PER_SetG_MIN_N2="<<*PER_SetG_MIN_N2<<endl;
            cout <<"PER_SetG_MIN_N3="<<*PER_SetG_MIN_N3<<endl;
            cout <<"FAS_SetG_MIN_N1="<<*FAS_SetG_MIN_N1<<endl;
            cout <<"FAS_SetG_MIN_N2="<<*FAS_SetG_MIN_N2<<endl;
            cout <<"FAS_SetG_MIN_N3="<<*FAS_SetG_MIN_N3<<endl;
            cout <<"POW_SetG_MID_N1="<<*POW_SetG_MID_N1<<endl;
            cout <<"POW_SetG_MID_N2="<<*POW_SetG_MID_N2<<endl;
            cout <<"POW_SetG_MID_N3="<<*POW_SetG_MID_N3<<endl;
            cout <<"BAN_SetG_MID_N1="<<*BAN_SetG_MID_N1<<endl;
            cout <<"BAN_SetG_MID_N2="<<*BAN_SetG_MID_N2<<endl;
            cout <<"BAN_SetG_MID_N3="<<*BAN_SetG_MID_N3<<endl;  
            cout <<"PER_SetG_MID_N1="<<*PER_SetG_MID_N1<<endl;
            cout <<"PER_SetG_MID_N2="<<*PER_SetG_MID_N2<<endl;
            cout <<"PER_SetG_MID_N3="<<*PER_SetG_MID_N3<<endl;
            cout <<"FAS_SetG_MID_N1="<<*FAS_SetG_MID_N1<<endl;
            cout <<"FAS_SetG_MID_N2="<<*FAS_SetG_MID_N2<<endl;
            cout <<"FAS_SetG_MID_N3="<<*FAS_SetG_MID_N3<<endl;
            if (*policynum == 3) {
                cout <<"POW_SetG_BIG_N1="<<*POW_SetG_BIG_N1<<endl;
                cout <<"POW_SetG_BIG_N2="<<*POW_SetG_BIG_N2<<endl;
                cout <<"POW_SetG_BIG_N3="<<*POW_SetG_BIG_N3<<endl;
                cout <<"BAN_SetG_BIG_N1="<<*BAN_SetG_BIG_N1<<endl;
                cout <<"BAN_SetG_BIG_N2="<<*BAN_SetG_BIG_N2<<endl;
                cout <<"BAN_SetG_BIG_N3="<<*BAN_SetG_BIG_N3<<endl;
                cout <<"PER_SetG_BIG_N1="<<*PER_SetG_BIG_N1<<endl;
                cout <<"PER_SetG_BIG_N2="<<*PER_SetG_BIG_N2<<endl;
                cout <<"PER_SetG_BIG_N3="<<*PER_SetG_BIG_N3<<endl;
                cout <<"FAS_SetG_BIG_N1="<<*FAS_SetG_BIG_N1<<endl;
                cout <<"FAS_SetG_BIG_N2="<<*FAS_SetG_BIG_N2<<endl;
                cout <<"FAS_SetG_BIG_N3="<<*FAS_SetG_BIG_N3<<endl;

            }
            else if (*policynum == 4) {
                cout <<"POW_SetG_BIG_N1="<<*POW_SetG_BIG_N1<<endl;
                cout <<"POW_SetG_BIG_N2="<<*POW_SetG_BIG_N2<<endl;
                cout <<"POW_SetG_BIG_N3="<<*POW_SetG_BIG_N3<<endl;
                cout <<"BAN_SetG_BIG_N1="<<*BAN_SetG_BIG_N1 << endl;
                cout <<"BAN_SetG_BIG_N2=" << *BAN_SetG_BIG_N2 << endl;
                cout <<"BAN_SetG_BIG_N3=" << *BAN_SetG_BIG_N3 << endl;
                cout <<"PER_SetG_BIG_N1=" << *PER_SetG_BIG_N1 << endl;
                cout <<"PER_SetG_BIG_N2=" << *PER_SetG_BIG_N2 << endl;
                cout <<"PER_SetG_BIG_N3=" << *PER_SetG_BIG_N3 << endl;
                cout <<"FAS_SetG_BIG_N1=" << *FAS_SetG_BIG_N1 << endl;
                cout <<"FAS_SetG_BIG_N2=" << *FAS_SetG_BIG_N2 << endl;
                cout <<"FAS_SetG_BIG_N3=" << *FAS_SetG_BIG_N3 << endl;
            
            }
        
        }


    }

};

#endif