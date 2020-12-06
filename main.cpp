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


        /*ifstream input;
        input.open("cs2341_data/0a0cbd4cb08c862deadcb5aaef22a27b770c0791.json");
        if (!input.is_open())
            cout << "unable to open file" << endl;*/
        Handler *h;
        char endProg;
        int option;
        while (endProg != 'n' && endProg != 'N') {
            cout << "User options: " << endl;
            cout << "     1. Enter search query" << endl;
            cout << "     2. Print index stats" << endl;
            cout << "Please enter the option number here ->";
            cin >> option;
            if (option == 1) {
                Query q;
                q.startQueryUI();
            } else if (option == 2) {
                //make stats function
            }
            cout<<"Do you wish to choose another option? (y/n) ->";
            cin>>endProg;
        }

    }
    return 0;
}