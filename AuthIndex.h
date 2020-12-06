// Final Project: Search Engine
// Author: Kylie Jordan
//
// AuthIndex.h
//
// This header file declares and defines the AuthIndex constructor and any functions found in the AuthIndex class

#ifndef FINALPROJECT_AUTHINDEX_H
#define FINALPROJECT_AUTHINDEX_H

#include <string>
#include <cstdlib>
#include <set>
#include "DSHashTable.h"
#include "Word.h"
#include "AuthIDs.h"

using namespace std;

class AuthIndex{
private:
    DSHashTable<string, AuthIDs> names;
public:
    AuthIndex(){};
    AuthIndex(AuthIndex& a){this->names = a.names;};
    void addAuth(string& w, AuthIDs& ids){
        names.insert(w, ids);
    };
    bool find(string& t){ return names.find(t);};
    AuthIDs& getFind(){ return names.getFind();};
    bool isFound(){ return names.isFound();};
    void setFound(bool r){names.setFound(r);};
    bool findDocs(string& word){
        return names.find(word);
    };
    void print(){
        names.print();
    };
};
#endif //FINALPROJECT_AUTHINDEX_H
