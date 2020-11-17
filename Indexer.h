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
#include "rapidjson/include/rapidjson/rapidjson.h"
#include "rapidjson/include/rapidjson/document.h"
#include "rapidjson/include/rapidjson/writer.h"
#include "rapidjson/include/rapidjson/stringbuffer.h"
#include "rapidjson/include/rapidjson/istreamwrapper.h"

using namespace std;
namespace fs = __fs::filesystem;
using namespace rapidjson;

class Indexer{
    private:
        //WordIndex words;
        //AuthIndex authors;
    public:
    Indexer(){};
    int getDir_FileSystem();
    void remStpWords(string&);
    void stem(string&);
    void addToIndex(bool, string&, string&, string&);
    //AuthIndex getAuthIndex();
    WordIndex& getWordIndex();
    void print();
};

#endif //FINALPROJECT_INDEXER_H
