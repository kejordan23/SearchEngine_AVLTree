// Final Project: Search Engine
// Author: Kylie Jordan
//
// DSAVLTree.h
//
// This header file declares and defines the DSAVLTree constructor and any functions found in the DSAVLTree class

#ifndef FINALPROJECT_DSAVLTREE_H
#define FINALPROJECT_DSAVLTREE_H

#include <string>
#include <cmath>

using namespace std;

template <typename T>
class AVLNode{
    public:
        T data;
        AVLNode<T>* left;
        AVLNode<T>* right;
        int height;
        AVLNode(T& d = T(), AVLNode<T>* l = nullptr, AVLNode<T>* r = nullptr): data(d), left(l), right(r), height(0){};
};

template <typename T>
class DSAVLTree{
    private:
        AVLNode<T>* root;
        bool found;
        int numEntries;
        void insert(T&, AVLNode<T>*&);
        T& find(T&, AVLNode<T>*&);
        void remove(T&, AVLNode<T>*&);
    public:
        DSAVLTree(){
            root = nullptr;
            numEntries = 0;
        };
        DSAVLTree(DSAVLTree<T>&);
        ~DSAVLTree(){ clear(root);};
        void copy(AVLNode<T>*&, AVLNode<T>*&);
        void clear(AVLNode<T>*& t){
            if(t == nullptr)
                return;
            clear(t->left);
            clear(t->right);
            delete t;
        };
        int getNumEntries(){ return numEntries;};
        void insert(T& data){
            insert(data, root);
        };
        void rotWLeftCh(AVLNode<T>*&);
        void rotWRightCh(AVLNode<T>*&);
        void doubleWLeftCh(AVLNode<T>*&);
        void doubleWRightCh(AVLNode<T>*&);
        int height(AVLNode<T>*& t){
            return t == nullptr ? -1 : t->height;
        };
        T& find(T& data){
            return find(data, root);
        };
        bool isFound(){return found;};
        void setFound(bool check){found = check;};
        void remove(T& data){ remove(data, root);};
        bool isEmpty(){
            return (root==nullptr);
        };
        void print();
        void inOrder(AVLNode<T>*&);
};

template <typename T>
DSAVLTree<T>::DSAVLTree(DSAVLTree<T>& rhs){
    copy(rhs.root, this->root);
}
template <typename T>
void DSAVLTree<T>::copy(AVLNode<T>*& first, AVLNode<T>*& second){
    if(first != nullptr){
        copy(first->left, second);
        copy(first->right, second);
        insert(first->data, second);
    }
}
template <typename T>
void DSAVLTree<T>::insert(T& val, AVLNode<T>*& t){
    if(t == nullptr) {
        t = new AVLNode(val);
        numEntries++;
    }
    else if(val<(t->data)){
        insert(val, t->left);
        if(height(t->left) - height(t->right) == 2){
            if(val<(t->left->data))         //C1
                rotWLeftCh(t);
            else                            //C2
                doubleWLeftCh(t);
        }
        numEntries++;
    }
    else if(val>(t->data)){
        insert(val, t->right);
        if(height(t->right) - height(t->left) == 2){
            if(val>(t->right->data))        //C4
                rotWRightCh(t);
            else                            //C3
                doubleWRightCh(t);
        }
        numEntries++;
    }
    else;
    t->height = max(height(t->left), height(t->right))+1;
}
template <typename T>
void DSAVLTree<T>::rotWLeftCh(AVLNode<T>*& k2){
    AVLNode<T>* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->left), height(k2->right))+1;
    k1->height = max(height(k1->left), k2->height)+1;
    k2 = k1;
}
template <typename T>
void DSAVLTree<T>::rotWRightCh(AVLNode<T>*& k1){
    AVLNode<T>* k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max(height(k1->left), height(k1->right))+1;
    k2->height = max(height(k2->right), k1->height)+1;
    k1 = k2;
}
template <typename T>
void DSAVLTree<T>::doubleWLeftCh(AVLNode<T>*& k3){
    rotWRightCh(k3->left);
    rotWLeftCh(k3);
}
template <typename T>
void DSAVLTree<T>::doubleWRightCh(AVLNode<T>*& k1){
    rotWLeftCh(k1->right);
    rotWRightCh(k1);
}
template <typename T>
T& DSAVLTree<T>::find(T& data, AVLNode<T>*& t){
    if (t == nullptr) {
        setFound(false);
        return data;
    }
    else if(data<t->data)
        return find(data, t->left);
    else if(data>t->data)
        return find(data, t->right);
    else{
        setFound(true);
        return t->data;
    }
}
template <typename T>
void DSAVLTree<T>::remove(T& data, AVLNode<T>*& t){
    if (t == nullptr)
        clear();
    else if(data< t->data)
        remove(data, t->left);
    else if(data> t->data)
        remove(data, t->right);
    else
        delete t;
}
template <typename T>
void DSAVLTree<T>::print(){
    if(isEmpty())
        cout<<"tree is empty"<<endl;
    else
        inOrder(root);
}
template <typename T>
void DSAVLTree<T>::inOrder(AVLNode<T>*& t){
    if(t!= nullptr){
        inOrder(t->left);
        t->data.print();
        inOrder(t->right);
    }
}

#endif //FINALPROJECT_DSAVLTREE_H
