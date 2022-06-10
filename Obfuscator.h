//
// Created by Amir on 16/12/2021.
//

#ifndef TARGEL_5_OBFUSCATOR_H
#define TARGEL_5_OBFUSCATOR_H
#include <iostream>
#include <string>
using namespace std;


class Obfuscator {

public:

    const string OUT = "newCode.c";
    virtual void obfuscate(string fileName) = 0;
    string generateRandomVar();
    string* parseFile(string filename);
    void writeToFile(string* codeArray);

};



#endif //TARGEL_5_OBFUSCATOR_H
