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
#include <condition_variable>
#include <cstdio>
#include <memory> 
#include <unistd.h>
#include <fcntl.h>
#include <mutex>
#include <sys/stat.h>
#include <sys/inotify.h> 
using namespace std;

class Utils{
protected:
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

    void my_log(const char* messsge){
        FILE* file = fopen(logpath, "a");
        if (file != nullptr) {
            fprintf(file,"%s\n", messsge);
            fclose(file);
        }
    }

    void Writer(const string path, int con){
        struct stat info;
        if (stat(path.c_str(), &info) != 0 || S_ISDIR(info.st_mode)) {
            return;
        }
        FILE* file = fopen(path.c_str(), "w");
        if (!file)
        {
            chmod(path.c_str(),0666);
            file = fopen(path.c_str(), "w");
        }
        
        fprintf(file, "%d", con);
        fclose(file);
        chmod(path.c_str(),0444);
    }

    void clearLog() {
        ofstream file(logpath, ios::trunc);
        if (file.is_open()) {
            file.close();
        } else {
            log("无法清空日志文件");
        }
    }

    void Writer(const string path, const string str) {
        struct stat info;
        if (stat(path.c_str(), &info) != 0 || S_ISDIR(info.st_mode)) {
            return;
        }
        FILE* file = fopen(path.c_str(), "w");
        if (!file) {
            chmod(path.c_str(), 0666);
            file = fopen(path.c_str(), "w");
        }
        fprintf(file, "%s", str.c_str());
        fclose(file);
        chmod(path.c_str(), 0444);
    }

};

#endif