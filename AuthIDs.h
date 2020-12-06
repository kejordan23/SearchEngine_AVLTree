// Final Project: Search Engine
// Author: Kylie Jordan
//
// AuthIDs.h
//
// This header file declares and defines the AuthIDs constructor and any functions found in the AuthIDs class

#ifndef FINALPROJECT_AUTHIDS_H
#define FINALPROJECT_AUTHIDS_H

#include <string>
#include <cstdlib>
#include <vector>
#include <set>
#include "DSHashTable.h"

using namespace std;

class AuthIDs{
    private:
        vector<string> ids;
    public:
        AuthIDs(){};
        string& operator[](const int k){
            return ids[k];
        }
        void push_back(string& str){
            ids.push_back(str);
        };
        vector<string>& getAuthIDs(){ return ids;};
        int size(){ return ids.size();};
};

#endif //FINALPROJECT_AUTHIDS_H
