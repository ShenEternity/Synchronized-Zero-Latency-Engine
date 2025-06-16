<<<<<<< HEAD
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

=======
#pragma one
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

>>>>>>> 80eb3b0d70d08b16b33fe6226096c0c8fafeb3e0
};