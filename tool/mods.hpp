#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class MODS {
private:
    const char* cfile = "/storage/emulated/0/Android/SZE_NEXT/config.txt";
public:  
    ifstream GETC (){
        ifstream file(cfile);
        return file;
    }

};