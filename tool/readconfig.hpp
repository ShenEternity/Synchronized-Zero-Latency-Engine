#ifndef RCONFIG_HPP
#define RCONFIG_HPP

#include <cstddef>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <unistd.h>
#include <vector>
#include "json.hpp"
#include "../utils/utils.hpp"

using json = nlohmann::json;

using namespace std;


class Rconfig{
public:
    const char* ConfigPath = "/storage/emulated/0/Android/SZE_NEXT/config.json";
    string name, lv, Out;
    bool SetGoverConfig,SetGover,OifaceAndJoyose;
    Utils utils;

    string policy1,policy2,policy3,policy4;
    int FREQ_MINCORE, FREQ_MIDCORE, FREQ_BIGCORE, FREQ_MAXCORE;
    string GOVER_MINCORE, GOVER_MIDCORE, GOVER_BIGCORE, GOVER_MAXCORE;


    int BACK_C_UCLAMP_MAX, BACK_C_UCLAMP_MIN, TOP_APP_C_UCLAMP_MAX, TOP_APP_C_UCLAMP_MIN,
        S_BACK_C_UCLAMP_MAX, S_BACK_C_UCLAMP_MIN, SYS_C_UCLAMP_MAX, SYS_C_UCLAMP_MIN,
        F_C_UCLAMP_MAX, F_C_UCLAMP_MIN;

    
    string CPUSET_Background, CPUSET_Top_app, CPUSET_System_Background, CPUSET_System, CPUSET_Foreground;

    vector<int> GoverConfigMIN;
    vector<int> GoverConfigMID;
    vector<int> GoverConfigBIG;
    vector<int> GoverConfigMAX;
    vector<string> GoverConfigPathMIN;
    vector<string> GoverConfigPathMID;
    vector<string> GoverConfigPathBIG;
    vector<string> GoverConfigPathMAX;

    vector<string> SysConfigPath;
    vector<string> SysConfig;




    bool EAS_Enable;

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
            OifaceAndJoyose = config["SetConfig"]["OifaceAndJoyose"];
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
            EAS_Enable = config[Mode]["EAS"]["EAS_Enable"];
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
            for (int i = 1; config[Mode]["GoverConfig"]["MINCORE"].contains("Config" + to_string(i)) ; i++) {
                GoverConfigMIN.push_back(config[Mode]["GoverConfig"]["MINCORE"]["Config" +  to_string(i)]);
            }
            for (int i = 1; config[Mode]["GoverConfig"]["MIDCORE"].contains("Config" + to_string(i)); i++) {
                GoverConfigMID.push_back(config[Mode]["GoverConfig"]["MIDCORE"]["Config" +  to_string(i)]);
            }
            for (int i = 1; config[Mode]["GoverConfig"]["BIGCORE"].contains("Config" + to_string(i)); i++) {
                GoverConfigBIG.push_back(config[Mode]["GoverConfig"]["BIGCORE"]["Config" +  to_string(i)]);
            }
            for (int i = 1; config[Mode]["GoverConfig"]["MAXCORE"].contains("Config" + to_string(i)); i++) {
                GoverConfigMAX.push_back(config[Mode]["GoverConfig"]["MAXCORE"]["Config" +  to_string(i)]);
            }


            for (int i = 1; config[Mode]["GoverConfig"]["MINCORE"].contains("Path" + to_string(i)); i++) {
                GoverConfigPathMIN.push_back(config[Mode]["GoverConfig"]["MINCORE"]["Path" + to_string(i)]);
            }
            for (int i = 1; config[Mode]["GoverConfig"]["MIDCORE"].contains("Path" + to_string(i)); i++) {
                GoverConfigPathMID.push_back(config[Mode]["GoverConfig"]["MIDCORE"]["Path" + to_string(i)]);
            }
            for (int i = 1; config[Mode]["GoverConfig"]["BIGCORE"].contains("Path" + to_string(i)); i++) {
                GoverConfigPathBIG.push_back(config[Mode]["GoverConfig"]["BIGCORE"]["Path" + to_string(i)]);
                
            }
            for (int i = 1; config[Mode]["GoverConfig"]["MAXCORE"].contains("Path" + to_string(i)); i++) {
                GoverConfigPathMAX.push_back(config[Mode]["GoverConfig"]["MAXCORE"]["Path" + to_string(i)]);
            }
            file.close();
        }
    }

    void ReadSysConfig(string Mode){
        ifstream file(ConfigPath);
        if (file.is_open()) {
            json config;
            file >> config;
            for (int i = 1; config[Mode]["SYS"]["ConfigPath"].contains("path"+to_string(i)); i++) {
                SysConfigPath.push_back(config[Mode]["SYS"]["ConfigPath"]["path"+to_string(i)]);
            }
            for (int i = 1; config[Mode]["SYS"]["Config"].contains("config"+to_string(i));i++) {
                SysConfig.push_back(config[Mode]["SYS"]["Config"]["config"+to_string(i)]);
            }
        }
    }

    void ReadUclamp(string Mode){
        ifstream file (ConfigPath);
        if (file.is_open()) {
            json config;
            file >> config;
            BACK_C_UCLAMP_MAX = config[Mode]["CPU_UCLAMP"]["Background_cpu_uclamp_max"];
            BACK_C_UCLAMP_MIN = config[Mode]["CPU_UCLAMP"]["Background_cpu_uclamp_min"];
            TOP_APP_C_UCLAMP_MAX = config[Mode]["CPU_UCLAMP"]["Top_app_cpu_uclamp_max"];
            TOP_APP_C_UCLAMP_MIN = config[Mode]["CPU_UCLAMP"]["Top_app_cpu_uclamp_min"];
            S_BACK_C_UCLAMP_MAX = config[Mode]["CPU_UCLAMP"]["System-Background_cpu_uclamp_max"];
            S_BACK_C_UCLAMP_MIN = config[Mode]["CPU_UCLAMP"]["System-Background_cpu_uclamp_min"];
            SYS_C_UCLAMP_MAX = config[Mode]["CPU_UCLAMP"]["System_cpu_uclamp_max"];
            SYS_C_UCLAMP_MIN = config[Mode]["CPU_UCLAMP"]["System_cpu_uclamp_min"];
            F_C_UCLAMP_MAX = config[Mode]["CPU_UCLAMP"]["Foreground_cpu_uclamp_max"];
            F_C_UCLAMP_MIN = config[Mode]["CPU_UCLAMP"]["Foreground_cpu_uclamp_min"];
            CPUSET_Background = config[Mode]["CPUSET"]["Background"];
            CPUSET_Top_app = config[Mode]["CPUSET"]["Top_app"];
            CPUSET_System_Background = config[Mode]["CPUSET"]["System-Background"];
            CPUSET_System = config[Mode]["CPUSET"]["System"];
            CPUSET_Foreground = config[Mode]["CPUSET"]["Foreground"];
            file.close();
        }
    }


/*     void printConfig() {
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
        

    } */

    void print(){
        for (size_t a = 0; a < SysConfigPath.size(); a++) {
            cout << SysConfigPath[a] << endl;
            cout << SysConfig[a] << endl;
        }
    }
};

#endif