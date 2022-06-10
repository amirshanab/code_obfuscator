//
// Created by Amir on 17/12/2021.
//
//
#include "VarObfuscator.h"
#include <vector>

void VarObfuscator::obfuscate(string fileName) {

    string *FileStr = Obfuscator::parseFile(fileName);
    string number = FileStr[0].substr(3,FileStr[0].length()-3);
    int arrLen = stoi(number);
    int amount =0;
    string randomName = generateRandomVar();
    string everyInt[20];
    int i =0;
    int startFrom=0;
    while (i<arrLen) {
        if (FileStr[i].find("main()")!=string::npos) {
            startFrom = i+1;
            break;
        }
        i++;
    }

    i = startFrom;
    while(i < arrLen){
        if(FileStr[i].find(" int ")!=string::npos){
            if(amount < 20){
                if(FileStr[i].find("=")!=string::npos){
                    for(int c = (FileStr[i].find(" int ")+5 ); c < FileStr[i].length(); c++) {
                        if(FileStr[i].at(c) == '=')
                            break;
                        everyInt[amount] += FileStr[i].at(c);
                    }
                    amount++;
                }
                else {
                    for(int c = (FileStr[i].find(" int ")+5 ); c < FileStr[i].length(); c++) {
                        if(FileStr[i].at(c) == ';')
                            break;
                        everyInt[amount] += FileStr[i].at(c);
                    }
                    amount++;
                }
            }
        }
        i++;
    }
    if(amount!=0) {
        string chosen = everyInt[rand() % amount];

        int j = 0;
        while (j < arrLen) {
            if (FileStr[j].find(chosen) != string::npos) {
                FileStr[j].replace(FileStr[j].find(chosen), chosen.length(), randomName);
            }
            j++;
        }
    }

    writeToFile(FileStr);
}



