//
// Created by Kylie Jordan on 11/16/20.
//

#ifndef FINALPROJECT_WORD_H
#define FINALPROJECT_WORD_H

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <set>

using namespace std;

class Word{
    private:
        string word;
        set<string> docIDs;
        set<string> locations;
    public:
        Word(string, string, string);
        void addID(string);
        void addLoc(string);
        set<string>& getIDs();
        set<string>& getLocs();
        void print();
};

#endif //FINALPROJECT_WORD_H
