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
        WordIndex(WordIndex& w){ this->words = w.words;};
        int getNumEntries(){ return words.getNumEntries();};
        void addWord(Word& w){
            words.insert(w);
        };
        Word& find(Word& t){ return words.find(t);};
        bool isFound(){ return words.isFound();};
        void setFound(bool r){words.setFound(r);};
        vector<string>& findDocs(Word& word){
            return word.getDocs();
        };
        vector<string>& getMatches(vector<string>& top15, Word& word2){
            return word2.getMatches(top15);
        };
        void print(){
            words.print();
        };
};

#endif //FINALPROJECT_WORDINDEX_H
