//
// Created by Kylie Jordan on 11/16/20.
//

#ifndef FINALPROJECT_AUTHINDEX_H
#define FINALPROJECT_AUTHINDEX_H

#include <string>
#include <cstdlib>
#include <set>
#include "DSHashTable.h"
#include "Word.h"

using namespace std;

class AuthIndex{
private:
    DSHashTable<string, vector<string>> names;
public:
    AuthIndex(){};
    AuthIndex(AuthIndex& a){this->names = a.names;};
    void addAuth(string& w, vector<string>& ids){
        names.insert(w, ids);
    };
    vector<string>& find(string& t){ return names.find(t);};
    bool isFound(){ return names.isFound();};
    void setFound(bool r){names.setFound(r);};
    vector<string>& findDocs(string& word){
        return names.find(word);
    };
    void print(){
        names.print();
    };
};
#endif //FINALPROJECT_AUTHINDEX_H
