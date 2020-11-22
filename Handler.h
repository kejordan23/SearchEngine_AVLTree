//
// Created by Kylie Jordan on 11/16/20.
//

#ifndef FINALPROJECT_HANDLER_H
#define FINALPROJECT_HANDLER_H

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "Query.h"
#include "Indexer.h"

using namespace std;

class Handler{
    private:
        Indexer index;
        //Query input;
    public:
        Handler(){
            makeIndex();
            //startQueryUI();
        };
        Handler(string& word, string& path){
            makeIndexDemo(path);
            getDocs(word);
        };
        void makeIndex(){
            index.getDir_FileSystem();
        };
        void makeIndexDemo(string& str){
            index.getDir_FileSystemDemo(str);
        };
        void startQueryUI();
        void getDocs(string& word){
            index.getDocs(word);
        };
};

#endif //FINALPROJECT_HANDLER_H
