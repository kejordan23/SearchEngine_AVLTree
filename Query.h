//
// Created by Kylie Jordan on 11/16/20.
//

#ifndef FINALPROJECT_QUERY_H
#define FINALPROJECT_QUERY_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Handler.h"

using namespace std;

class Query: public Handler{
    private:
        bool authBool;
        bool andBool;
        bool orBool;
        bool notBool;
        vector<string> words;
    public:
        Query(){
            authBool = false;
            andBool = false;
            orBool = false;
            notBool = false;
        };
        void startQueryUI(){
            string temp;
            char check = 'y';
            while ( check != 'n' && check != 'N') {
                cout << "Please enter search terms-> ";
                getline(cin, temp);
                cout<<"Documents that include these/this word(s)/author are:"<<endl;
                processWrds(temp);
                cout<<"Would you like search again? (y/n) ->";
                cin>>check;
                words.clear();
                cin.ignore();
            }
        };
        void processWrds(string& t){
            string word;
            char delim = ' ';
            istringstream temp(t);
            while(getline(temp, word, delim)){
                if(word == "AND")
                    andBool = true;
                else if (word == "OR")
                    orBool = true;
                else if (word == "AUTHOR")
                    authBool = true;
                else if (word == "NOT")
                    notBool = true;
                else
                    words.push_back(word);
            }
            set<string> f;
            if(andBool){
                vector<string> temp1;
                temp1 = index.getWordDocs(words[0]);
                vector<string>& temp2 = index.getWordDocs(words[1]);
                if(temp1.size() > 0 && temp2.size() > 0) {
                    auto z = temp1.begin();
                    while (z != temp1.end()) {
                        auto it = find(temp2.begin(), temp2.end(), *z);
                        if (it != temp2.end())
                            f.insert(*z);
                        z++;
                    }
                }
                andBool = false;
            }
            else if(orBool){
                vector<string> temp1;
                temp1 = index.getWordDocs(words[0]);
                vector<string>& temp2 = index.getWordDocs(words[1]);
                if(temp1.size() > 0) {
                    auto z = temp1.begin();
                    while (z != temp1.end()) {
                        f.insert(*z);
                        z++;
                    }
                }
                if(temp2.size()>0){
                    auto y = temp2.begin();
                    while (y != temp2.end()) {
                        f.insert(*y);
                        y++;
                    }
                }
                orBool = false;
            }
            else{
                vector<string>& temp1 = index.getWordDocs(words[0]);
                if(temp1.size() > 0) {
                    auto z = temp1.begin();
                    while (z != temp1.end()) {
                        f.insert(*z);
                        //cout<<*z<<endl;
                        z++;
                    }
                }
            }
            set<string> final;
            if(authBool){
                vector<string>& temp4 = index.getAuthDocs(words[words.size()-1]);
                if(temp4.size() > 0) {
                    auto d = temp4.begin();
                    while (d != temp4.end()) {
                        auto it = f.find(*d);
                        if (it != f.end()) {
                            final.insert(*d);
                            cout<<*d<<endl;
                        }
                        d++;
                    }
                }
                authBool = false;
            }
            else if (notBool){
                vector<string>& temp3 = index.getWordDocs(words[words.size()-1]);
                if(temp3.size()>0) {
                    auto d = f.begin();
                    while (d != f.end()) {
                        auto it = find(temp3.begin(), temp3.end(), *d);
                        if (it == temp3.end()) {
                            final.insert(*d);
                            cout<<*d<<endl;
                        }
                        d++;
                    }
                }
                notBool = false;
            }
            else{
                auto z = f.begin();
                while (z != f.end()) {
                    cout<<*z<<endl;
                    z++;
                }
            }
            f.clear();
            final.clear();
        };
};

#endif //FINALPROJECT_QUERY_H
