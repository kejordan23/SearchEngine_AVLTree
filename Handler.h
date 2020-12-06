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
        Handler(){};
        void makeIndex(){
            index.getDir_FileSystem();
        };
        virtual void startQueryUI() = 0;
        void printStats(){
            cout<<"Index Statistics: "<<endl;
            cout<<"     Number of Individual articles indexed: "<<index.getDocsParsed()<<endl;
            cout<<"     Average Number of Words Indexed Per Article: "<<index.getAvgNumWrds()<<endl;
            cout<<"     Number of Words in Index: "<<index.getTotWrds()<<endl;
            cout<<"     Number of Unique Authors: "<<index.getTotAuth()<<endl;
        };
};

#endif //FINALPROJECT_HANDLER_H
