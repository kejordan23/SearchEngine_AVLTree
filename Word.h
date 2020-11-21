//
// Created by Kylie Jordan on 11/16/20.
//

#ifndef FINALPROJECT_WORD_H
#define FINALPROJECT_WORD_H

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

class Word{
    private:
        string word;
        vector<string> docIDs;
        vector<string> locations;
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
            docIDs.push_back(d);
        };
        void addLoc(string& l){
            locations.push_back(l);
        };
        vector<string>& getIDs(){ return docIDs;};
        vector<string>& getLocs(){ return locations;};
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
