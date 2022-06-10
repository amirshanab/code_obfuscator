//
// Created by Amir on 19/12/2021.
//
#include "CommentObfuscator.h"

void CommentObfuscator::obfuscate(string fileName) {

    string randomStrings[6];// random comments
    randomStrings[0] = "// A method to check if number is prime.";
    randomStrings[1] = "// checking the amount of the numbers.";
    randomStrings[2]  = "//write everything to the new file.";
    randomStrings[3] = "//checking if number is odd or even";
    randomStrings[4] = "//going over the array and looking for the right number.";
    randomStrings[5] = "//getting the array size.";
    int ranNum;


    string *FileStr = Obfuscator::parseFile(fileName);
    string number = FileStr[0].substr(3,FileStr[0].length()-3);// to get the array size.
    int arrLen = stoi(number);
    int i = 1;
    while (i < arrLen){
        if(FileStr[i].find("//")!=string::npos){// look for all the comments in the array.
            FileStr[i].replace(FileStr[i].find("//"),FileStr[i].length()," ");// remove all the comments.
        }
        i++;
    }
    int ranLine = rand()%(arrLen-2);
    int commentAmount =7;
    while( commentAmount > 0){
        ranNum = rand()%6;
        ranLine = rand()%(arrLen) ;
        FileStr[ranLine] += "\n" + randomStrings[ranNum];
        commentAmount--;
    }
    writeToFile(FileStr);
}





