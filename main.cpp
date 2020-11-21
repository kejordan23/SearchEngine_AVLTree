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

        /*DSAVLTree<Word> a =DSAVLTree<Word>();
        string z = "hello";
        string b = "world";
        string c = "my";
        string d = "name";
        string e = "is";
        string f = "Kylie";
        Word g(z);
        Word h(b);
        Word i(c);
        Word j(d);
        Word k(e);
        Word l(f);
        a.insert(g);
        a.insert(h);
        a.insert(i);
        a.insert(j);
        a.insert(k);
        a.insert(l);

        a.print();

        Word q(f);
        Word t = a.find(q);
        if(a.isFound()) {
            cout << "found" << endl;
            t.print();
        }
        else
            cout<<"not found"<<endl;*/


        Handler();

    }
    return 0;
}