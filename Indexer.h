//
// Created by Kylie Jordan on 11/16/20.
//

#ifndef FINALPROJECT_INDEXER_H
#define FINALPROJECT_INDEXER_H

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "DSAVLTree.h"
#include "Word.h"
#include "WordIndex.h"
#include "AuthIndex.h"
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
        //AuthIndex authors;
        int docNum;
    public:
    Indexer(){};
    int getDir_FileSystem();
    bool isStpWord(string&);
    void stemm(string&);
    void remPunc(string&);
    void addToIndex(bool, string&, string&, string&);
    //AuthIndex getAuthIndex();
    WordIndex& getWordIndex();
    void print();
};

#endif //FINALPROJECT_INDEXER_H
