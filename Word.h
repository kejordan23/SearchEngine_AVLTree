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
        Word(string& w): word(w){};
        string& getWord(){ return word;};
        bool operator>(const Word& w){
            if(this->word > w.word)
                return true;
            else
                return false;
        };
        bool operator<(const Word& w){
            if(this->word < w.word)
                return true;
            else
                return false;
        };
        void addID(string& d){
            docIDs.insert(d);
        };
        void addLoc(string& l){
            locations.insert(l);
        };
        set<string>& getIDs(){ return docIDs;};
        set<string>& getLocs(){ return locations;};
        void print(){
            cout<<word<<endl;
            auto z = docIDs.begin();
            auto y = locations.begin();
            while(z != docIDs.end()){
                cout<<"Found in "<<*y<<" in document "<<*z<<endl;
                z++;
                y++;
            }
        };
};

#endif //FINALPROJECT_WORD_H
