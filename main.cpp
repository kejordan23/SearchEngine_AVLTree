//
// Created by Kylie Jordan on 11/13/20.
//
#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include <string>
#include "Handler.h"
#include "Query.h"

using namespace std;

//main() takes command line arguments argv 1: input01.txt, argv 2: input02.txt, and argv 3: output.txt
int main(int argc, char* argv[]) {
    //conditional to run CATCH tests if there is one command line arguments
    if (argc != 1) {
        return Catch::Session().run();
    }   //conditional to run code if there are no command line arguments
    else if (argc == 1) {
        /*ifstream input1;
        ifstream input2;
        input1.open(argv[1]);
        input2.open(argv[2]);
        //opening files with a conditional to check if they open correctly
        if (!input1.is_open() || !input2.is_open())
            cout << "unable to open file" << endl;*/


        Handler *h;
        Query q;
        q.startQueryUI();

    }
    return 0;
}