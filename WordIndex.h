//
// Created by Kylie Jordan on 11/16/20.
//

#ifndef FINALPROJECT_WORDINDEX_H
#define FINALPROJECT_WORDINDEX_H

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <set>
#include "DSAVLTree.h"
#include "Word.h"

using namespace std;

class WordIndex{
    private:
        DSAVLTree<string> words;
    public:
        WordIndex();
        void addWord(Word);
        set<string>& findDocs(Word);
        void print();
};

#endif //FINALPROJECT_WORDINDEX_H
