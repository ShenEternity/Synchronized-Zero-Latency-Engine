#ifndef UTILS_HPP
#define UTILS_HPP


#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <cstdio>
#include <memory> 
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
using namespace std;

class Utils{
public:
    const char * logpath = "/storage/emulated/0/Android/SZE_NEXT/log.txt";

public:
    void log(const char* message){
        time_t now = time(nullptr);
        tm* localtm = localtime(&now);
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtm);
        FILE* file = fopen(logpath, "a");
        if (file != nullptr) {
            fprintf(file, "[%s] %s\n", buffer, message);
            fclose(file);
        }
    }

    void Writer(const char* path, int con){
        FILE* file = fopen(path, "w");
        if (!file)
        {
            chmod(path,0666);
            file = fopen(path, "w");
        }
        
        int ce = fprintf(file, "%d", con);
        
        if (ce < 0)
        {
            log("Writer函数无法正常写入");
        }
        fclose(file);
        chmod(path,0444);
    }

    void clearLog() {
        ofstream file(logpath, ios::trunc);
        if (file.is_open()) {
            file.close();
        } else {
            log("无法清空日志文件");
        }
    }

    void Writer(const char* path, const char* str) {
        FILE* file = fopen(path, "w");
        if (!file) {
            chmod(path, 0666);
            file = fopen(path, "w");
        }
        int result = fprintf(file, "%s", str);
    
        if (result < 0) {
            log("Writer函数无法正常写入");
        }
    
        fclose(file);
        chmod(path, 0444);
    }

};

#endif