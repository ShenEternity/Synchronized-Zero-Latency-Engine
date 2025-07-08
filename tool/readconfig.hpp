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
    bool SetGoverConfig;
    Utils utils;

    string policy1,policy2,policy3,policy4;
    int FREQ_MINCORE, FREQ_MIDCORE, FREQ_BIGCORE, FREQ_MAXCORE;
    string GOVER_MINCORE, GOVER_MIDCORE, GOVER_BIGCORE, GOVER_MAXCORE;



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


    void ReadConfig(string Mode){
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
    }
};

#endif