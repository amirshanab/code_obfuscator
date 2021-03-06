#include <iostream>
#include "Obfuscator.h"
#include "LineObfuscator.h"
#include "CommentObfuscator.h"
#include "VarObfuscator.h"



int main() {

    Obfuscator* obfs[3];
    obfs[0] = new VarObfuscator();
    obfs[1] = new LineObfuscator();
    obfs[2] = new CommentObfuscator();
    obfs[0]->obfuscate("amir.txt");
    for(int i = 1; i < 3; i++)
        obfs[i]->obfuscate(obfs[i-1]->OUT);
    for(int i = 0; i < 3; i++){
        delete obfs[i];
    }
    // delete obfs[0];

    return 0;
}



