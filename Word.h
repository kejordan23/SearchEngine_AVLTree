//
// Created by Kylie Jordan on 11/16/20.
//

#ifndef FINALPROJECT_WORD_H
#define FINALPROJECT_WORD_H

#include <string>
#include <cstdlib>
#include <vector>
#include <set>

using namespace std;

class Word{
    private:
        string word;
        vector<string> docIDs;
        vector<string> locations;
        set<string> docsOnly;
        vector<string> final;
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
            docsOnly.insert(d);
        };
        void addLoc(string& l){
            locations.push_back(l);
        };
        vector<string>& getIDs(){ return docIDs;};
        vector<string>& getLocs(){ return locations;};
        vector<string>& getDocs(){
            auto z = docsOnly.begin();
            while(z != docsOnly.end()){
                final.push_back(*z);
                z++;
            }
            return final;
        };
        void printDocs(){
            auto z = docsOnly.begin();
            while(z != docsOnly.end()){
                cout<<*z<<endl;
                z++;
            }
        };
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
