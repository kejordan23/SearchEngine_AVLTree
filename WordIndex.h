//
// Created by Kylie Jordan on 11/16/20.
//

#ifndef FINALPROJECT_WORDINDEX_H
#define FINALPROJECT_WORDINDEX_H

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
        void addWord(Word& w){
            words.insert(w);
        };
        Word& find(Word& t){ return words.find(t);};
        bool isFound(){ return words.isFound();};
        void setFound(bool r){words.setFound(r);};
        void findDocs(Word& word){
            word.printDocs();
        };
        void print(){
            words.print();
        };
};

#endif //FINALPROJECT_WORDINDEX_H
