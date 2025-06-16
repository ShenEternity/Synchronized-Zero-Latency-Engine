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

#define CORE_COUNT 8

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

    std::vector<std::vector<long>> readCpuStats() {
        std::ifstream file("/proc/stat");
        std::string line;
        std::vector<std::vector<long>> cpuStats(CORE_COUNT, std::vector<long>(4));

        int core = 0;
        while (std::getline(file, line)) {
            if (line.find("cpu") == 0 && line.find("cpu ") != 0) { 
                std::istringstream iss(line);
                std::string cpu;
                iss >> cpu;
                for (int i = 0; i < 4; ++i) {
                    iss >> cpuStats[core][i];
                }
                core++;
                if (core >= CORE_COUNT) break;
            }
        }
        return cpuStats;
    }

    int calculateTotalCpuLoad(const std::vector<std::vector<long>>& stats1, const std::vector<std::vector<long>>& stats2) {
        long total1 = 0, idle1 = 0;
        long total2 = 0, idle2 = 0;

        for (size_t i = 0; i < stats1.size(); ++i) {
            const long* coreStats1 = stats1[i].data(); 
            const long* coreStats2 = stats2[i].data(); 
            total1 += *(coreStats1) + *(coreStats1 + 1) + *(coreStats1 + 2) + *(coreStats1 + 3);
            idle1 += *(coreStats1 + 3);

            total2 += *(coreStats2) + *(coreStats2 + 1) + *(coreStats2 + 2) + *(coreStats2 + 3);
            idle2 += *(coreStats2 + 3);
        }

        long totalDiff = total2 - total1;
        long idleDiff = idle2 - idle1;

        if (totalDiff == 0) {
            return 0;
        }

        return static_cast<int>(((totalDiff - idleDiff) * 10) >> 1) / 50;
    }

};

#endif