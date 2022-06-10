//
// Created by Amir on 16/12/2021.
//

#include "Obfuscator.h"
#include <fstream>
#include <string>



string Obfuscator :: generateRandomVar(){
    int randi[4];
    int n = rand()%7 +5;// chose a random string size
    int ran;
    string str;
    for (int i = 0; i < n; ++i) {
        randi[0] = rand() %10+ 48;// numbers from 0-9
        randi[1] = rand() %26+ 65;// small letters a-z
        randi[2] = rand() %26+ 97;//big letters from A-Z
        randi[3] =95;// the character _
        if (i == 0){// if its the first letter in the sting
            ran = rand() %3 + 1;// start from one so we dont get numbers as the first letter.
            str = randi[ran];
        }
        ran = rand() %4 + 0;// else randomly chose between all
        str+= randi[ran];
    }
    return str;
}


string* Obfuscator:: parseFile(string filename){

    int counter= 0;
    ifstream infile;
    infile.open (filename);
    string line;
    while (getline(infile, line)){// count how many lines we have in the file
        counter++;
    }

    infile.close();

    string *lines = new string[counter+1];
    infile.open(filename);
    int i =1;
    lines[0] = "// " + to_string(counter+1);// to help get the array size we put it in the first line of the array.
    while (getline(infile, line)){
        lines[i] = line;// else we copy everything to the array
        i++;
    }
    infile.close();

    return lines;
}
void Obfuscator:: writeToFile (string* codeArray){

    string number = codeArray[0].substr(3,codeArray[0].length()-3);// to get the array size from the first line in the array.
    int arrLen = stoi(number);
    ofstream onfile;
    onfile.open (OUT);



    int i =1;

    while(i < arrLen){
        onfile<<codeArray[i]<<endl;// write everything to the new file.
        i++;
    }
    onfile.close();

}