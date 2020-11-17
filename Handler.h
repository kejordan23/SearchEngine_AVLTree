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
        };
        Handler(string&){

        };
        void makeIndex(){
            index.getDir_FileSystem();
        };
        void startQueryUI();
};

#endif //FINALPROJECT_HANDLER_H
