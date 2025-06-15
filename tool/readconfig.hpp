#ifndef RCONFIG_HPP
#define RCONFIG_HPP



#include <fstream>
#include <iostream>
#include <memory>
#include "json.hpp"

using json = nlohmann::json;

using namespace std;


class Rconfig{
public:
    const char* ConfigPath = "/storage/emulated/0/Android/SZE_NEXT/config.json";
    string name, lv, Out; 
    int * POW_MINCORE = nullptr;
    int * POW_MIDCORE = nullptr;
    int * POW_BIGCORE = nullptr;
    int * BAN_MINCORE = nullptr;
    int * BAN_MIDCORE = nullptr;
    int * BAN_BIGCORE = nullptr;
    int * PER_MINCORE = nullptr;
    int * PER_MIDCORE = nullptr;
    int * PER_BIGCORE = nullptr;
    int * FAS_MINCORE = nullptr;
    int * FAS_MIDCORE = nullptr;
    int * FAS_BIGCORE = nullptr;

    ~Rconfig(){
        delete POW_MINCORE;
        delete POW_MIDCORE;
        delete POW_BIGCORE;
        delete BAN_MINCORE;
        delete BAN_MIDCORE;
        delete BAN_BIGCORE;
        delete PER_MINCORE;
        delete PER_MIDCORE;
        delete PER_BIGCORE;
        delete FAS_MINCORE;
        delete FAS_MIDCORE;
        delete FAS_BIGCORE;
    }


public:
    void ReadConfig(){
        ifstream file(ConfigPath);
        if (file.is_open()) {
            json config;
            file >> config;
            name = config["Name"]["name"];
            lv = config["Name"]["lv"];
            Out = config["Name"]["aut"];

            POW_MINCORE = new int(config["powersave"]["FREQ"]["MINCORE"]);
            BAN_MINCORE = new int(config["balance"]["FREQ"]["MINCORE"]);
            PER_MINCORE = new int(config["performace"]["FREQ"]["MINCORE"]);
            FAS_MINCORE = new int(config ["fast"]["FREQ"]["MINCORE"]);

            POW_MIDCORE = new int(config["powersave"]["FREQ"]["MIDCORE"]);
            BAN_MIDCORE = new int(config["balance"]["FREQ"]["MIDCORE"]);
            PER_MIDCORE = new int(config["performace"]["FREQ"]["MIDCORE"]);
            FAS_MIDCORE = new int(config ["fast"]["FREQ"]["MIDCORE"]);

            POW_BIGCORE = new int(config["powersave"]["FREQ"]["BIGCORE"]);
            BAN_BIGCORE = new int(config["balance"]["FREQ"]["BIGCORE"]);
            PER_BIGCORE = new int(config["performace"]["FREQ"]["BIGCORE"]);
            FAS_BIGCORE = new int(config ["fast"]["FREQ"]["BIGCORE"]);

        }
    }

    void print (){
        cout << name << endl;
        cout << lv << endl;
        cout << Out << endl;
        cout << *POW_MINCORE <<endl;
        cout << *POW_MIDCORE <<endl;
        cout << *POW_BIGCORE <<endl;
        cout << *BAN_MINCORE <<endl;
        cout << *BAN_MIDCORE <<endl;
        cout << *BAN_BIGCORE <<endl;
        cout << *PER_MINCORE <<endl;
        cout << *PER_MIDCORE <<endl;
        cout << *PER_BIGCORE <<endl;
        cout << *FAS_MINCORE <<endl;
        cout << *FAS_MIDCORE <<endl;
        cout << *FAS_BIGCORE <<endl;

    }

};

#endif