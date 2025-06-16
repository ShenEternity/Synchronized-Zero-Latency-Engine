#ifndef RCONFIG_HPP
#define RCONFIG_HPP



#include <fstream>
#include <iostream>
#include <memory>
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
    int* BAN_MINCORE = nullptr;
    int* BAN_MIDCORE = nullptr;
    int* BAN_BIGCORE = nullptr;
    int* PER_MINCORE = nullptr;
    int* PER_MIDCORE = nullptr;
    int* PER_BIGCORE = nullptr;
    int* FAS_MINCORE = nullptr;
    int* FAS_MIDCORE = nullptr;
    int* FAS_BIGCORE = nullptr;
    int* POW_BOOST_MINCORE = nullptr;
    int* POW_BOOST_MIDCORE = nullptr;
    int* POW_BOOST_BIGCORE = nullptr;

    int* BAN_BOOST_MINCORE = nullptr;
    int* BAN_BOOST_MIDCORE = nullptr;
    int* BAN_BOOST_BIGCORE = nullptr;

    int* PER_BOOST_MINCORE = nullptr;
    int* PER_BOOST_MIDCORE = nullptr;
    int* PER_BOOST_BIGCORE = nullptr;

    int* FAS_BOOST_MINCORE = nullptr;
    int* FAS_BOOST_MIDCORE = nullptr;
    int* FAS_BOOST_BIGCORE = nullptr;

    int* POW_BOOST_OC = nullptr;
    int* BAN_BOOST_OC = nullptr;
    int* PER_BOOST_OC = nullptr;
    int* FAS_BOOST_OC = nullptr;

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
        delete POW_BOOST_MINCORE;
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
        delete FAS_BOOST_OC;

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

            POW_BOOST_MINCORE = new int(config["powersave"]["BOOST"]["MINCORE"]);
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


        }else{
            utils.log("配置文件不存在！");
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
        cout << *POW_BOOST_MINCORE <<endl;
        cout << *POW_BOOST_MIDCORE <<endl;
        cout << *POW_BOOST_BIGCORE <<endl;
        cout << *BAN_BOOST_MINCORE <<endl;
        cout << *BAN_BOOST_MIDCORE <<endl;
        cout << *BAN_BOOST_BIGCORE <<endl;
        cout << *PER_BOOST_MINCORE <<endl;
        cout << *PER_BOOST_MIDCORE <<endl;
        cout << *PER_BOOST_BIGCORE <<endl;
        cout << *FAS_BOOST_MINCORE <<endl;
        cout << *FAS_BOOST_MIDCORE <<endl;
        cout << *FAS_BOOST_BIGCORE <<endl;
        cout << *POW_BOOST_OC <<endl;
        cout << *BAN_BOOST_OC <<endl;
        cout << *PER_BOOST_OC <<endl;
        cout << *FAS_BOOST_OC <<endl;


    }

};

#endif