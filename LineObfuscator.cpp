//
// Created by Amir on 17/12/2021.
//

#include "LineObfuscator.h"
#include <iostream>
#include <fstream>
#include <string>


void LineObfuscator::obfuscate(string fileName) {

    string *FileStr = Obfuscator::parseFile(fileName);
    string number = FileStr[0].substr(3,FileStr[0].length()-3);// to get the array size from the first line of the array.
    int arrLen = stoi(number);
    int i = 0;
    int mainLine;
    while (i < arrLen) {
        if (FileStr[i].find("main()")!=string::npos) {// looking for the main.
            mainLine = i+1;// saving the main line.
        }
        i++;
    }
    int lastLine = (arrLen-2);// last line to put code in
    int ranLine;
    int field = lastLine -(mainLine+1);// the field in which we can add code after the main
    ranLine = rand() % field + (mainLine + 2);// randomly chose a line after the main line
    int randomNum1 = rand() % 1000 + 500;
    int randomNum2 = rand() % 1000 +500;
    string randomName = Obfuscator::generateRandomVar();
    string ranStr = "\t"+randomName +" = "+ to_string(randomNum1) + " + "  + to_string(randomNum2) +";";


    for(int k =0; k < arrLen; k ++){
        if(k == mainLine){// look for the mail line and add the new int one line after
            FileStr[k] += "\n";
            FileStr[k] += "    int " + randomName + ";";
        }
        if(k == ranLine){// randomly chose a line then add the int calculation to it.
            FileStr[k] += "\n";
            FileStr[k] += ranStr;
        }
    }

    writeToFile(FileStr);

}
