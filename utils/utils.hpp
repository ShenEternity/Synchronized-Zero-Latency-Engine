#ifndef UTILS_HPP
#define UTILS_HPP


#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <cstdio>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/inotify.h>



using namespace std;

class Utils{
protected:
    const char * logpath = "/storage/emulated/0/Android/SZE_NEXT/log.txt";
    
public:
    bool Debug = true;
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

    int Writer(const string path, int con) {
        int fd = open(path.c_str(), O_WRONLY);
        if (fd < 0) {
            chmod(path.c_str(), 0666);
            fd = open(path.c_str(), O_WRONLY);
        }
        char temp[15];
        auto len = snprintf(temp, sizeof(temp), "%d", con);
        int de = write(fd, temp, len);
        if (de < 0) {
            return -1;
        }
        if (Debug) {
            log(("DEBUG: 写入" + to_string(con) + "到文件: " + path).c_str());
            if (de < 0) {
                log(("ERROR: 无法写入" + to_string(con) + "到文件: " + path).c_str());
            }else {
                log(("INFO: 成功写入" + to_string(con) + "到文件: " + path).c_str());
            }
        }
        chmod(path.c_str(), 0444);
        return 1;
    }

    void clearLog() {
        ofstream file(logpath, ios::trunc);
        if (file.is_open()) {
            file.close();
        } else {
            log("无法清空日志文件");
        }
    }

    int Writer(const string path, const string str) {
        int fd = open(path.c_str(), O_WRONLY);
        if (fd < 0) {
            chmod(path.c_str(), 0666);
            fd = open(path.c_str(), O_WRONLY);
        }
        int de = write(fd, str.c_str(), str.size());
        if (de < 0) {
            return -1;
        }
        if (Debug) {
            log(("DEBUG: 写入" + str + "到文件: " + path).c_str());
            if (de < 0) {
                log(("ERROR: 无法写入" + str + "到文件: " + path).c_str());
            }else {
                log(("INFO: 成功写入" + str + "到文件: " + path).c_str());
            }
        }
        chmod(path.c_str(), 0444);
        return 1;
    }

};

#endif