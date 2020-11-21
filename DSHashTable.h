//
// Created by Kylie Jordan on 11/16/20.
//

#ifndef FINALPROJECT_DSHASHTABLE_H
#define FINALPROJECT_DSHASHTABLE_H

#include <fstream>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

template <typename T>
class HTEntry{
    public:
        T key;
        T val;
        HTEntry(T k, T v): key(k), val(v){};
};
template <typename T>
class DSHashTable{
    private:
        HTEntry<T> **t;
    public:
        DSHashTable();
        DSHashTable(DSHashTable&);
        ~DSHashTable(){clear();};
        int Hash(T);
        void insert(T, T);
        T find(T);
        void remove(T);
        void clear();
        void print();
};
#endif //FINALPROJECT_DSHASHTABLE_H
