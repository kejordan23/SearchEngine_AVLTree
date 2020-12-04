//
// Created by Kylie Jordan on 11/16/20.
//

#ifndef FINALPROJECT_DSHASHTABLE_H
#define FINALPROJECT_DSHASHTABLE_H

#include <string>
#include <cmath>

using namespace std;

const int TABLE_SIZE = 1000;

template <typename K, typename V>
class HTEntry{
    public:
        K key;
        V val;
        HTEntry* next;
        HTEntry(K& k = K(), V& v = V()): key(k), val(v), next(nullptr){};
        HTEntry*& getNext(){return next;};
        K& getKey(){return key;};
        V& getVal(){return val;};
        void setVal(V& v){ val = v;};
        void setNext(HTEntry*& n){next = n;};

};
template <typename K, typename V>
class DSHashTable{
    private:
        HTEntry<K, V> **t;
        bool found;
        V objFound;
        int numEntries;
    public:
        DSHashTable(){
            t = new HTEntry<K, V> * [TABLE_SIZE];
            for (int i = 0; i< TABLE_SIZE; i++) {
                t[i] = NULL;
            }
        };
        DSHashTable(DSHashTable&);
        ~DSHashTable(){clear();};
        bool isEmpty() { return (numEntries == 0);};
        int Hash(K& data);
        void insert(K&, V&);
        bool find(K&);
        V& getFind(){ return objFound;};
        void setFound(bool check){found = check;};
        bool isFound(){ return found;};
        void remove(K&);
        void clear();
        void print();
};
template <typename K, typename V>
DSHashTable<K, V>::DSHashTable(DSHashTable<K, V>& other){
    t = new HTEntry<K, V> * [TABLE_SIZE];
    HTEntry<K, V>* first;
    for(int i = 0; i<TABLE_SIZE; i++){
        first = other.t[i];
        if (first != nullptr)
            break;
    }
    while(first){
        insert(first->key, first->val);
        first = other.first->getNext();
    }
}
template <typename K, typename V>
int DSHashTable<K, V>::Hash(K& data){        //https://stackoverflow.com/questions/8317508/hash-function-for-a-string
    int seed = 131;
    unsigned long hash = 0;
    for(int i = 0; i < data.length(); i++)
    {
        hash = (hash * seed) + data[i];
    }
    return hash % TABLE_SIZE;
}
template <typename K, typename V>
void DSHashTable<K, V>::insert(K& key, V& val){ //adapted from https://aozturk.medium.com/simple-hash-map-hash-table-implementation-in-c-931965904250
    int hashVal = Hash(key);
    HTEntry<K, V> *prev = nullptr;
    HTEntry<K, V> *entry = t[hashVal];
    while(entry != nullptr && entry->key != key){
        prev = entry;
        entry = entry->getNext();
    }
    if(entry == nullptr) {
        numEntries++;
        entry = new HTEntry<K, V>(key, val);
        if(prev == nullptr)
            t[hashVal] = entry;
        else
            prev->setNext(entry);
    }
    else
        entry->setVal(val);
}
template <typename K, typename V>
bool DSHashTable<K, V>::find(K& key){
    int hashVal = Hash(key);
    HTEntry<K, V> *entry = t[hashVal];
    if(entry == nullptr){
        setFound(false);
        return false;
    }
    while(entry != nullptr){
        if(entry->getKey() == key) {
            setFound(true);
            objFound = entry->getVal();
            return true;
        }
        entry = entry->getNext();
    }
    setFound(false);
    return false;
}
template <typename K, typename V>
void DSHashTable<K, V>::remove(K& key){ //adapted from https://aozturk.medium.com/simple-hash-map-hash-table-implementation-in-c-931965904250
    int hashVal = Hash(key);
    HTEntry<K, V> *prev = nullptr;
    HTEntry<K, V> *entry = t[hashVal];
    while(entry != nullptr && entry->key != key){
        prev = entry;
        entry = entry->getNext();
    }
    if(entry == nullptr)
        return;
    else{
        if(prev == nullptr)
            t[hashVal] = entry->getNext();
        else
            prev->setNext(entry->getNext());
        delete entry;
    }
}
template <typename K, typename V>
void DSHashTable<K, V>::clear(){
    for(int i = 0; i<TABLE_SIZE; i++){
        if(t[i] != nullptr)
            delete t[i];
    }
    delete [] t;
}
template <typename K, typename V>
void DSHashTable<K, V>::print(){
    HTEntry<K, V>* temp;
    for(int i = 0; i< TABLE_SIZE; i++){
        temp = t[i];
        if(temp != nullptr){
            cout<<temp->getKey()<<", ";
            for(int j = 0; j<temp->getVal().size(); j++)
                cout<<temp->getVal()[j]<<endl;
        }
    }
}
#endif //FINALPROJECT_DSHASHTABLE_H
