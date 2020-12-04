//
// Created by Kylie Jordan on 11/16/20.
//

#ifndef FINALPROJECT_WORD_H
#define FINALPROJECT_WORD_H

#include <string>
#include <cstdlib>
#include <vector>
#include <unordered_set>

using namespace std;

class Word{
    private:
        string word;
        int count;
        vector<int> wordFreq;
        vector<string> docIDs;
        vector<string> locations;
        unordered_set<string> docsOnly;
        vector<string> final;
    public:
        Word(string& w): word(w), count(1){};
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
            popWordFreq();
            auto z = docsOnly.begin();
            while(z != docsOnly.end()){
                final.push_back(*z);
                z++;
            }
            for(int i = 0; i<wordFreq.size(); i++){
                cout<<wordFreq[i]<<endl;
            }
            return final;
        };
        void popWordFreq(){
            int count = 1;
            for(int i = 1; i<=docIDs.size(); i++){
                if(docIDs[i] != docIDs[i-1]){
                    wordFreq.push_back(count);
                    count = 1;
                }
                else
                    count++;
            }
        };
        void printDocs(){
            popWordFreq();
            auto z = docsOnly.begin();
            while(z != docsOnly.end()){
                cout<<*z<<endl;
                z++;
            }
            for(int i = 0; i<wordFreq.size(); i++){
                cout<<wordFreq[i]<<endl;
            }
        };
        void print(){
            popWordFreq();
            cout<<word<<endl;
            /*auto z = docsOnly.begin();
            auto y = wordFreq.begin();
            while(z != docsOnly.end()){
                cout<<"Found "<<*y<<" times in document "<<*z<<endl;
                z++;
                y++;
            }*/
            for(int i = 0; i<wordFreq.size(); i++){
                cout<<wordFreq[i]<<endl;
            }
        };
};

#endif //FINALPROJECT_WORD_H
