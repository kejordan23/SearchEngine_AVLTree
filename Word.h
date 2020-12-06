// Final Project: Search Engine
// Author: Kylie Jordan
//
// Word.h
//
// This header file declares and defines the Word constructor and any functions found in the Word class

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
        vector<string> top15;
        vector<string> docIDs;
        vector<string> locations;
        unordered_set<string> docsOnly;
        vector<string> andFinal;
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
            return top15;
        };
        vector<string>& getMatches(vector<string>& top){
            auto z = top.begin();
            while(z != top.end() && andFinal.size()<= 15){
                auto it = docsOnly.find(*z);
                if(it != docsOnly.end())
                    andFinal.push_back(*z);
                z++;
            }
            return andFinal;
        };
        void popWordFreq(){
            //counts occurrences of same docID in docIDS and adds to wordFreq list
            for(int i = 1; i<=docIDs.size(); i++){
                if(docIDs[i] != docIDs[i-1]){
                    wordFreq.insert(wordFreq.end(), count);
                    count = 1;
                }
                else
                    count++;
            }
            vector<string> temp3;
            auto z = docsOnly.begin();
            while(z != docsOnly.end()){
                temp3.push_back(*z);
                z++;
            }
            int temp = 0;
            int temp2 = 1000000;
            int index = 0;
            int index2 = 0;
            int size = 15;
            bool inserted = false;
            if(docsOnly.size()<15)
                size = docsOnly.size();
            for(int j = 0; j<size && top15.size() <size; j++) {     //populates top15
                for (int i = 0; i < wordFreq.size(); i++) {
                    if (wordFreq[i] > temp && wordFreq[i] <temp2) {
                        temp = wordFreq[i];
                        index = i;
                    }
                    else if(wordFreq[i] == temp2 && i != index2){
                        top15.push_back(temp3[i]);
                        inserted = true;
                    }
                }
                temp2 = temp;
                index2 = index;
                temp = 0;
                if(!inserted)
                    top15.push_back(temp3[index]);
                inserted = false;
            }
        };
};

#endif //FINALPROJECT_WORD_H
