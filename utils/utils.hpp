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
        int fd = open(path.c_str(), O_WRONLY);
        if (fd < 0) {
            chmod(path.c_str(), 0666);
            fd = open(path.c_str(), O_WRONLY);
        }
        char temp[15];
        auto len = snprintf(temp, sizeof(temp), "%d", con);
        write(fd, temp, len);
        chmod(path.c_str(), 0444);
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
        int fd = open(path.c_str(), O_WRONLY);
        if (fd < 0) {
            chmod(path.c_str(), 0666);
            fd = open(path.c_str(), O_WRONLY);
        }
        write(fd, str.c_str(), str.size());
        chmod(path.c_str(), 0444);
    }

};

#endif