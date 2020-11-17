//
// Created by Kylie Jordan on 11/13/20.
//
#define CATCH_CONFIG_RUNNER
#include <fstream>
#include <iostream>
#include "catch.hpp"
#include <dirent.h>
#include <filesystem>
#include <string>
#include <vector>
#include "DSAVLTree.h"
#include "Handler.h"

using namespace std;

//main() takes command line arguments argv 1: input01.txt, argv 2: input02.txt, and argv 3: output.txt
int main(int argc, char* argv[]) {
    //conditional to run CATCH tests if there are no command line arguments
    if (argc == 1) {
        return Catch::Session().run();
    }
    else {
        /*ifstream input1;
        ifstream input2;
        input1.open(argv[1]);
        input2.open(argv[2]);
        //opening files with a conditional to check if they open correctly
        if (!input1.is_open() || !input2.is_open())
            cout << "unable to open file" << endl;*/

        DSAVLTree<int> a =DSAVLTree<int>();
        a.print();
        for(int i = 0; i<10; i++)
            a.insert(i);
        a.print();

        //Handler();
    }
    return 0;
}