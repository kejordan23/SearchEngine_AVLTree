// Final Project: Search Engine
// Author: Kylie Jordan
//
// Handler.h
//
// This header file declares the Handler constructor and any functions found in the Handler class

#ifndef FINALPROJECT_HANDLER_H
#define FINALPROJECT_HANDLER_H

#include <string>
#include <cstdlib>
#include "Indexer.h"

using namespace std;

class Handler{      //parent to query class
    public:
        Indexer index;
        Handler(){};
        void makeIndex(){
            index.getDir_FileSystem();
        };
        virtual void startQueryUI() = 0;
};

#endif //FINALPROJECT_HANDLER_H
