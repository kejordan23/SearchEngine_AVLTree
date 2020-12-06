//
// Created by Kylie Jordan on 11/16/20.
//

#ifndef FINALPROJECT_HANDLER_H
#define FINALPROJECT_HANDLER_H

#include <string>
#include <cstdlib>
#include "Indexer.h"

using namespace std;

class Handler{
    public:
        Indexer index;
        Handler(){
            //makeIndex();
        };
        /*Handler(string& word, string& path){
            makeIndexDemo(path);
            getDocs(word);
        };*/
        void makeIndex(){
            index.getDir_FileSystem();
        };
        /*void makeIndexDemo(string& str){
            index.getDir_FileSystemDemo(str);
        };*/
        virtual void startQueryUI() = 0;
        /*void getDocs(string& word){
            index.getDocs(word);
        };*/
};

#endif //FINALPROJECT_HANDLER_H
