// Final Project: Search Engine
// Author: Kylie Jordan
//
// Indexer.cpp
//
// This source file defines all the constructors, operators, and functions for the Indexer class

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cstring>
#include <filesystem>
#include <algorithm>
#include <sstream>
#include "Word.h"
#include "Indexer.h"
#include "AuthIDs.h"
#include "include/rapidjson/rapidjson.h"
#include "include/rapidjson/document.h"
#include "include/rapidjson/writer.h"
#include "include/rapidjson/stringbuffer.h"
#include "include/rapidjson/istreamwrapper.h"
#include "stmr.h"
#include "stmr.c"

using namespace std;
namespace fs = __fs::filesystem;
using namespace rapidjson;

string p = "cs2341_data";

Indexer::Indexer(Indexer& i){
    this->words = i.words;
    this->names = i.names;
}

int Indexer::getDir_FileSystem(){
    vector<fs::path> files;
    for (const auto & entry : fs::directory_iterator(p))
        files.emplace_back(entry.path());
    docsParsed = 0;
    numAuth = 0;
    avgNumWrds = 0;

    Document d;         //uses RapidJSON for parsing https://github.com/Tencent/rapidjson/
    for(int i = 0; i<files.size(); i++) {
        docNum = i;
        ifstream fp(files[i]);
        IStreamWrapper isw(fp);
        d.ParseStream(isw);

        StringBuffer buffer;
        Writer<StringBuffer> writer(buffer);
        d.Accept(writer);

        if (!d.HasParseError()) {           //checks if doc is empty
            //id
            Value &id = d["paper_id"];
            string iD = id.GetString();
            //title
            string type = "title";
            Value &s = d["metadata"];
            Value &t = s["title"];
            string z = t.GetString();
            if (z != "") {                  //checks if doc has readable title
                docsParsed++;
                addToIndex(true, z, iD, type);
                //authors
                Value &c = s["authors"];
                type = "authors";
                string first;
                string middle;
                string last;
                for (SizeType i = 0; i < c.Size(); i++) {
                    last = c[i]["last"].GetString();
                    addToIndex(false, last, iD, type);
                }
                //abstract
                Value &l = d["abstract"];
                type = "abstract";
                string p;
                for (SizeType i = 0; i < l.Size(); i++) {
                    p = l[i]["text"].GetString();
                    addToIndex(true, p, iD, type);
                }
                //body text
                Value &g = d["body_text"];
                type = "body_text";
                for (SizeType i = 0; i < g.Size(); i++) {
                    p = g[i]["text"].GetString();
                    addToIndex(true, p, iD, type);
                }
            }
        }
    }
    avgNumWrds /= docsParsed;           //computes average words per article after stop word removal
    return 0;
}
//determines if string arg is a stop word
bool Indexer::isStpWord(string& word){
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    vector<string> stopWrds = {"we", "our", "ours", "ourselves", "you", "your", "yours", "yourself", "yourselves", "he", "him", "his", "himself", "she", "her", "hers", "herself", "it", "its", "itself", "they", "them", "their", "theirs", "themselves", "what", "which", "who", "whom", "this", "that", "these", "those", "am", "is", "are", "was", "were", "be", "been", "being", "have", "has", "had", "having", "do", "does", "did", "doing", "a", "an", "the", "and", "but", "if", "or", "because", "as", "until", "while", "of", "at", "by", "for", "with", "about", "against", "between", "into", "through", "during", "before", "after", "above", "below", "to", "from", "up", "down", "in", "out", "on", "off", "over", "under", "again", "further", "then", "once", "here", "there", "when", "where", "why", "how", "all", "any", "both", "each", "few", "more", "most", "other", "some", "such", "no", "not", "only", "own", "same", "so", "than", "too", "very", "can", "will", "just", "should", "now"};
    for(int i = 0; i<stopWrds.size(); i++){
        if (word == stopWrds[i])
            return true;
    }
    return false;
}
//uses wooorm's stemmer to stem word if not found in the stem table
void Indexer::stemm(string& word){
    if(stemTable.find(word)){
        string& val = stemTable.getFind();
        word = val;
        stemTable.setFound(false);
    }
    else {
        string temp;
        char *test = new char[word.length() + 1];
        strcpy(test, word.c_str());
        int end = stem(test, 0, strlen(test) - 1); //https://github.com/wooorm/stmr.c.git
        test[end + 1] = 0;
        temp = test;
        stemTable.insert(word, temp);
        word = test;
    }
}
//removes any punctuation from the end of the word
void Indexer::remPunc(string& str){
    if(ispunct(str[str.size()-1]))
        str.erase(str.size()-2, str.size()-1);
}
//adds a passage to index by separating words, ignoring stop words, and stemming them
void Indexer::addToIndex(bool type, string& passage, string& id, string& loc){
    string word;
    char delim = ' ';
    istringstream temp(passage);
    if(type) {              //boolean check true = add to WordIndex
        while (getline(temp, word, delim)) {
            if(word.size() > 2) {
                remPunc(word);
                if (!isStpWord(word)) {
                    avgNumWrds++;
                    stemm(word);
                    Word t(word);
                    Word& temp5 = words.find(t);
                    if(words.isFound() && docNum != 0){
                        temp5.addID(id);
                        temp5.addLoc(loc);
                        words.setFound(false);
                    }
                    else {
                        t.addID(id);
                        t.addLoc(loc);
                        words.addWord(t);
                    }
                }

            }
        }
    }
    else{               //boolean check false = add to AuthIndex
        if(passage.size() > 2){
            stemm(passage);
            if(names.find(passage) && docNum != 0){
                AuthIDs& temp6 = names.getFind();
                temp6.push_back(id);
                names.addAuth(passage, temp6);
            }
            else{
                numAuth++;
                AuthIDs t;
                t.push_back(id);
                names.addAuth(passage, t);
            }
        }
    }
}
//function specific to AND to get matches from primary word's top15 and secondary word's docIDs
vector<string>& Indexer::getMatches(vector<string>& top15, string& word){
    char *test = new char[word.length() + 1];
    strcpy(test, word.c_str());
    int end = stem(test, 0, strlen(test) - 1); //https://github.com/wooorm/stmr.c.git
    test[end + 1] = 0;
    word = test;
    Word temp(word);
    Word t = words.find(temp);
    temp1.clear();
    if(words.isFound()) {
        temp1 = words.getMatches(top15, t);
        return temp1;
    }
    else {
        cout << "word not found" << endl;
        return temp1;
    }
}
//function to get top15 ranked docs based on word query
vector<string>& Indexer::getWordDocs(string& word){
    char *test = new char[word.length() + 1];
    strcpy(test, word.c_str());
    int end = stem(test, 0, strlen(test) - 1); //https://github.com/wooorm/stmr.c.git
    test[end + 1] = 0;
    word = test;
    Word temp(word);
    Word t = words.find(temp);
    temp1.clear();
    if(words.isFound()) {
        temp1 = words.findDocs(t);
        return temp1;
    }
    else {
        cout << "word not found" << endl;
        return temp1;
    }
}
//function to get all docs for an authors last name
vector<string>& Indexer::getAuthDocs(string& name){
    char *test = new char[name.length() + 1];
    strcpy(test, name.c_str());
    int end = stem(test, 0, strlen(test) - 1); //https://github.com/wooorm/stmr.c.git
    test[end + 1] = 0;
    name = test;
    if(names.find(name)) {
        temp2 = names.getFind();
        return temp2.getAuthIDs();
    }
    else {
        cout << "author not found" << endl;
        return temp2.getAuthIDs();
    }
}