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
        DSAVLTree<Word> words;
    public:
        WordIndex(){};
        void addWord(Word w){
            words.insert(w);
        };
        set<string>& findDocs(Word);
        void print(){
            words.print();
        };
};

#endif //FINALPROJECT_WORDINDEX_H
