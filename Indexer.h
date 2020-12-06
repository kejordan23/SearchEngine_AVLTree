//
// Created by Kylie Jordan on 11/16/20.
//

#ifndef FINALPROJECT_INDEXER_H
#define FINALPROJECT_INDEXER_H


#include <string>
#include <cstdlib>
#include <vector>
#include "DSAVLTree.h"
#include "Word.h"
#include "WordIndex.h"
#include "AuthIndex.h"
#include "DSHashTable.h"
#include "AuthIDs.h"
#include "include/rapidjson/rapidjson.h"
#include "include/rapidjson/document.h"
#include "include/rapidjson/writer.h"
#include "include/rapidjson/stringbuffer.h"
#include "include/rapidjson/istreamwrapper.h"

using namespace std;
namespace fs = __fs::filesystem;
using namespace rapidjson;

class Indexer{
    private:
        WordIndex words;
        AuthIndex names;
        vector<string> temp1;
        AuthIDs temp2;
        DSHashTable<string, string> stemTable = DSHashTable<string, string>();
        int docNum;
    public:
    Indexer(){};
    Indexer(Indexer&);
    int getDir_FileSystem();
    //int getDir_FileSystemDemo(string&);
    bool isStpWord(string&);
    void stemm(string&);
    void remPunc(string&);
    void addToIndex(bool, string&, string&, string&);
    AuthIndex& getAuthIndex();
    WordIndex& getWordIndex();
    vector<string>& getMatches(vector<string>&, string& word);
    vector<string>& getWordDocs(string&);
    vector<string>& getAuthDocs(string&);
    void print();
};

#endif //FINALPROJECT_INDEXER_H
