#ifndef RCONFIG_HPP
#define RCONFIG_HPP

#include <cstdint>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <unistd.h>
#include "json.hpp"
#include "../utils/utils.hpp"

using json = nlohmann::json;

using namespace std;


class Rconfig{
public:
    const char* ConfigPath = "/storage/emulated/0/Android/SZE_NEXT/config.json";
    string name, lv, Out;
    bool SetGoverConfig,SetGover;
    Utils utils;

    string policy1,policy2,policy3,policy4;
    int FREQ_MINCORE, FREQ_MIDCORE, FREQ_BIGCORE, FREQ_MAXCORE;
    string GOVER_MINCORE, GOVER_MIDCORE, GOVER_BIGCORE, GOVER_MAXCORE;
    int GOVER_C_MINCORE1, GOVER_C_MIDCORE1, GOVER_C_BIGCORE1, GOVER_C_MAXCORE1,
        GOVER_C_MINCORE2, GOVER_C_MIDCORE2, GOVER_C_BIGCORE2, GOVER_C_MAXCORE2,
        GOVER_C_MINCORE3, GOVER_C_MIDCORE3, GOVER_C_BIGCORE3, GOVER_C_MAXCORE3;

    string GOVER_C_MINCORE1_PATH, GOVER_C_MIDCORE1_PATH, GOVER_C_BIGCORE1_PATH, GOVER_C_MAXCORE1_PATH,
           GOVER_C_MINCORE2_PATH, GOVER_C_MIDCORE2_PATH, GOVER_C_BIGCORE2_PATH, GOVER_C_MAXCORE2_PATH,
           GOVER_C_MINCORE3_PATH, GOVER_C_MIDCORE3_PATH, GOVER_C_BIGCORE3_PATH, GOVER_C_MAXCORE3_PATH;



    void ReadName(){
        ifstream file(ConfigPath);
        if(file.is_open()){
            json config;
            file >> config;
            name = config["Name"]["name"];
            lv = config["Name"]["lv"];
            Out = config["Name"]["Out"];
            file.close();
        }
        else {
            utils.log("配置文件无法打开");
            return;
        }
    }

    void ReadSetConfig(){
        ifstream file(ConfigPath);
        if(file.is_open()){
            json config;
            file >> config;
            SetGoverConfig = config["SetConfig"]["SetGoverConfig"];
            SetGover = config["SetConfig"]["SetGover"];
            file.close();
        }
        else {
            utils.log("配置文件无法打开");
        }
    }


    void ReadPolicy(){
        ifstream file(ConfigPath);
        if(file.is_open()){
            json config;
            file >> config;
            policy1 = config["Policy"]["policy1"];
            policy2 = config["Policy"]["policy2"];
            if (config["Policy"].contains("policy3")) {
                policy3 = config["Policy"]["policy3"];
            }
            if (config["Policy"].contains("policy4")) {
                policy4 = config["Policy"]["policy4"];
            }
            file.close();
        }
        else {
            utils.log("配置文件无法打开");
        }
    }


    void ReadFreqConfig(string Mode){
        ifstream file(ConfigPath);
        if(file.is_open()){
            json config;
            file >> config;
            FREQ_MINCORE = config[Mode]["FREQ"]["MINCORE"];
            FREQ_MIDCORE = config[Mode]["FREQ"]["MIDCORE"];
            if (config[Mode]["FREQ"].contains("BIGCORE")) {
                FREQ_BIGCORE = config[Mode]["FREQ"]["BIGCORE"];
            }
            if (config[Mode]["FREQ"].contains("MAXCORE")) {
                FREQ_MAXCORE = config[Mode]["FREQ"]["MAXCORE"];
            }
            file.close();
        }
        else {
            utils.log("配置文件无法打开");
        }
    }


    void ReadGoverConfig(string Mode){
        ifstream file(ConfigPath);
        if(file.is_open()){
            json config;
            file >>  config;
            GOVER_MINCORE = config[Mode]["Governor"]["MINCORE"];
            GOVER_MIDCORE = config[Mode]["Governor"]["MIDCORE"];
            if (config[Mode]["Governor"].contains("BIGCORE")) {
                GOVER_BIGCORE = config[Mode]["Governor"]["BIGCORE"];
            }
            if (config[Mode]["Governor"].contains("MAXCORE")) {
                GOVER_MAXCORE = config[Mode]["Governor"]["MAXCORE"];
            }
            file.close();
        }
        else {
            utils.log("配置文件无法打开");
        }
    }


    void ReadGoverConfigConfig(string Mode) {
        ifstream file(ConfigPath);
        if (file.is_open()) {
            json config;
            file >> config;
            if (config[Mode]["GoverConfig"]["MINCORE"].contains("Config1")) {
                GOVER_C_MINCORE1 = config[Mode]["GoverConfig"]["MINCORE"]["Config1"];
            }
            if (config[Mode]["GoverConfig"]["MIDCORE"].contains("Config1")) {
                GOVER_C_MIDCORE1 = config[Mode]["GoverConfig"]["MIDCORE"]["Config1"];
            }
            if (config[Mode]["GoverConfig"]["BIGCORE"].contains("Config1")) {
                GOVER_C_BIGCORE1 = config[Mode]["GoverConfig"]["BIGCORE"]["Config1"];
            }
            if (config[Mode]["GoverConfig"]["MAXCORE"].contains("Config1")) {
                GOVER_C_MAXCORE1 = config[Mode]["GoverConfig"]["MAXCORE"]["Config1"];
            }
            if (config[Mode]["GoverConfig"]["MINCORE"].contains("Config2")) {
                GOVER_C_MINCORE2 = config[Mode]["GoverConfig"]["MINCORE"]["Config2"];
            }
            if (config[Mode]["GoverConfig"]["MIDCORE"].contains("Config2")) {
                GOVER_C_MIDCORE2 = config[Mode]["GoverConfig"]["MIDCORE"]["Config2"];
            }
            if (config[Mode]["GoverConfig"]["BIGCORE"].contains("Config2")) {
                GOVER_C_BIGCORE2 = config[Mode]["GoverConfig"]["BIGCORE"]["Config2"];
            }
            if (config[Mode]["GoverConfig"]["MAXCORE"].contains("Config2")) {
                GOVER_C_MAXCORE2 = config[Mode]["GoverConfig"]["MAXCORE"]["Config2"];
            }
            if (config[Mode]["GoverConfig"]["MINCORE"].contains("Config3")) {
                GOVER_C_MINCORE3 = config[Mode]["GoverConfig"]["MINCORE"]["Config3"];
            }
            if (config[Mode]["GoverConfig"]["MIDCORE"].contains("Config3")) {
                GOVER_C_MIDCORE3 = config[Mode]["GoverConfig"]["MIDCORE"]["Config3"];
            }
            if (config[Mode]["GoverConfig"]["BIGCORE"].contains("Config3")) {
                GOVER_C_BIGCORE3 = config[Mode]["GoverConfig"]["BIGCORE"]["Config3"];
            }
            if (config[Mode]["GoverConfig"]["MAXCORE"].contains("Config3")) {
                GOVER_C_MAXCORE3 = config[Mode]["GoverConfig"]["MAXCORE"]["Config3"];
            }

            if (config[Mode]["GoverConfig"]["MINCORE"].contains("Path1")) {
                GOVER_C_MINCORE1_PATH = config[Mode]["GoverConfig"]["MINCORE"]["Path1"];
            }
            if (config[Mode]["GoverConfig"]["MIDCORE"].contains("Path1")) {
                GOVER_C_MIDCORE1_PATH = config[Mode]["GoverConfig"]["MIDCORE"]["Path1"];
            }
            if (config[Mode]["GoverConfig"]["BIGCORE"].contains("Path1")) {
                GOVER_C_BIGCORE1_PATH = config[Mode]["GoverConfig"]["BIGCORE"]["Path1"];
            }
            if (config[Mode]["GoverConfig"]["MAXCORE"].contains("Path1")) {
                GOVER_C_MAXCORE1_PATH = config[Mode]["GoverConfig"]["MAXCORE"]["Path1"];
            }
            if (config[Mode]["GoverConfig"]["MINCORE"].contains("Path2")) {
                GOVER_C_MINCORE2_PATH = config[Mode]["GoverConfig"]["MINCORE"]["Path2"];
            }
            if (config[Mode]["GoverConfig"]["MIDCORE"].contains("Path2")) {
                GOVER_C_MIDCORE2_PATH = config[Mode]["GoverConfig"]["MIDCORE"]["Path2"];
            }
            if (config[Mode]["GoverConfig"]["BIGCORE"].contains("Path2")) {
                GOVER_C_BIGCORE2_PATH = config[Mode]["GoverConfig"]["BIGCORE"]["Path2"];
            }
            if (config[Mode]["GoverConfig"]["MAXCORE"].contains("Path2")) {
                GOVER_C_MAXCORE2_PATH = config[Mode]["GoverConfig"]["MAXCORE"]["Path2"];
            }
            if (config[Mode]["GoverConfig"]["MINCORE"].contains("Path3")) {
                GOVER_C_MINCORE3_PATH = config[Mode]["GoverConfig"]["MINCORE"]["Path3"];
            }
            if (config[Mode]["GoverConfig"]["MIDCORE"].contains("Path3")) {
                GOVER_C_MIDCORE3_PATH = config[Mode]["GoverConfig"]["MIDCORE"]["Path3"];
            }
            if (config[Mode]["GoverConfig"]["BIGCORE"].contains("Path3")) {
                GOVER_C_BIGCORE3_PATH = config[Mode]["GoverConfig"]["BIGCORE"]["Path3"];
            }
            if (config[Mode]["GoverConfig"]["MAXCORE"].contains("Path3")) {
                GOVER_C_MAXCORE3_PATH = config[Mode]["GoverConfig"]["MAXCORE"]["Path3"];
            }
            file.close();
        }
        else {
            utils.log("配置文件无法打开");
        }
    }


    void printConfig() {
        cout << "Name: " << name << endl;
        cout << "Level: " << lv << endl;
        cout << "Output: " << Out << endl;
        cout << "Policy1: " << policy1 << endl;
        cout << "Policy2: " << policy2 << endl;
        cout << "Policy3: " << policy3 << endl;
        cout << "Policy4: " << policy4 << endl;
        cout << "FREQ_MINCORE: " << FREQ_MINCORE << endl;
        cout << "FREQ_MIDCORE: " << FREQ_MIDCORE << endl;
        cout << "FREQ_BIGCORE: " << FREQ_BIGCORE << endl;
        cout << "FREQ_MAXCORE: " << FREQ_MAXCORE << endl;
        cout << "GOVER_MINCORE: " << GOVER_MINCORE << endl;
        cout << "GOVER_MIDCORE: " << GOVER_MIDCORE << endl;
        cout << "GOVER_BIGCORE: " << GOVER_BIGCORE << endl;
        cout << "GOVER_MAXCORE: " << GOVER_MAXCORE << endl;

        cout << "************************************" << endl;
        
        cout << "GOVER_C_MINCORE1: " << GOVER_C_MINCORE1 << endl;
        cout << "GOVER_C_MIDCORE1: " << GOVER_C_MIDCORE1 << endl;
        cout << "GOVER_C_BIGCORE1: " << GOVER_C_BIGCORE1 << endl;
        cout << "GOVER_C_MAXCORE1: " << GOVER_C_MAXCORE1 << endl;
        cout << "GOVER_C_MINCORE2: " << GOVER_C_MINCORE2 << endl;
        cout << "GOVER_C_MIDCORE2: " << GOVER_C_MIDCORE2 << endl;
        cout << "GOVER_C_BIGCORE2: " << GOVER_C_BIGCORE2 << endl;
        cout << "GOVER_C_MAXCORE2: " << GOVER_C_MAXCORE2 << endl;
        cout << "GOVER_C_MINCORE3: " << GOVER_C_MINCORE3 << endl;
        cout << "GOVER_C_MIDCORE3: " << GOVER_C_MIDCORE3 << endl;
        cout << "GOVER_C_BIGCORE3: " << GOVER_C_BIGCORE3 << endl;
        cout << "GOVER_C_MAXCORE3: " << GOVER_C_MAXCORE3 << endl;
        cout << "GOVER_C_MINCORE1_PATH: " << GOVER_C_MINCORE1_PATH << endl;
        cout << "GOVER_C_MIDCORE1_PATH: " << GOVER_C_MIDCORE1_PATH << endl;
        cout << "GOVER_C_BIGCORE1_PATH: " << GOVER_C_BIGCORE1_PATH << endl;
        cout << "GOVER_C_MAXCORE1_PATH: " << GOVER_C_MAXCORE1_PATH << endl;
        cout << "GOVER_C_MINCORE2_PATH: " << GOVER_C_MINCORE2_PATH << endl;
        cout << "GOVER_C_MIDCORE2_PATH: " << GOVER_C_MIDCORE2_PATH << endl;
        cout << "GOVER_C_BIGCORE2_PATH: " << GOVER_C_BIGCORE2_PATH << endl;
        cout << "GOVER_C_MAXCORE2_PATH: " << GOVER_C_MAXCORE2_PATH << endl;
        cout << "GOVER_C_MINCORE3_PATH: " << GOVER_C_MINCORE3_PATH << endl;
        cout << "GOVER_C_MIDCORE3_PATH: " << GOVER_C_MIDCORE3_PATH << endl;
        cout << "GOVER_C_BIGCORE3_PATH: " << GOVER_C_BIGCORE3_PATH << endl;
        cout << "GOVER_C_MAXCORE3_PATH: " << GOVER_C_MAXCORE3_PATH << endl;

    }
};

#endif