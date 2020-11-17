//
// Created by Kylie Jordan on 11/16/20.
//
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <dirent.h>
#include <filesystem>
#include <sstream>
#include "DSAVLTree.h"
#include "Word.h"
#include "WordIndex.h"
#include "AuthIndex.h"
#include "Indexer.h"
#include "rapidjson/include/rapidjson/rapidjson.h"
#include "rapidjson/include/rapidjson/document.h"
#include "rapidjson/include/rapidjson/writer.h"
#include "rapidjson/include/rapidjson/stringbuffer.h"
#include "rapidjson/include/rapidjson/istreamwrapper.h"

using namespace std;
namespace fs = __fs::filesystem;
using namespace rapidjson;

const char * p = "cs2341_data";

int Indexer::getDir_FileSystem(){
    vector<fs::path> files;
    for (auto & entry : fs::directory_iterator(p))
        files.emplace_back(entry.path());


    Document d;
    ifstream fp(files[0]);
    IStreamWrapper isw(fp);
    d.ParseStream(isw);
    /*for (auto each:files) {
        cout << each << endl;
    }*/
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);

    if ( d.HasParseError() )
    {
        std::cout << "Error  : " << d.GetParseError()  << '\n'
                  << "Offset : " << d.GetErrorOffset() << '\n';
        return EXIT_FAILURE;
    }
    Value& s = d["body_text"];
    //Value& t = s["text"];
    for(SizeType i = 0; i<s.Size(); i++)
        cout << s[i]["text"].GetString() << endl;
    //std::cout << buffer.GetString() << std::endl;
    return 0;
}
void Indexer::remStpWords(string&){

}
void Indexer::stem(string&){

}
void Indexer::addToIndex(bool type, string& passage, string& id, string& loc){
    remStpWords(passage);
    string word;
    char delim = ' ';
    istringstream temp(passage);
    if(type) {
        while (getline(temp, word, delim)) {
            //Word t(word, id, loc);
            //words.addWord(t);
        }
    }
    //add algo to add authors
}
//AuthIndex getAuthIndex();
WordIndex& Indexer::getWordIndex(){
    //return words;
}
void Indexer::print(){

}