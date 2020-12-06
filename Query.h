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
#include <unordered_set>
#include "Handler.h"
#include "include/rapidjson/rapidjson.h"
#include "include/rapidjson/document.h"
#include "include/rapidjson/writer.h"
#include "include/rapidjson/stringbuffer.h"
#include "include/rapidjson/istreamwrapper.h"

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
                cin.ignore();
                cout << "Please enter search terms-> ";
                getline(cin, temp);
                cout<<"Documents that include these/this word(s)/author are:"<<endl;
                processWrds(temp);
                cout<<"Would you like to continue searching with this index? (y/n) ->";
                cin>>check;
                words.clear();
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
            vector<string> f;
            if(andBool){
                vector<string> temp1;
                temp1 = index.getWordDocs(words[0]);
                vector<string>& temp2 = index.getWordDocs(words[1]);
                if(temp1.size() > 0 && temp2.size() > 0) {
                    auto z = temp1.begin();
                    while (z != temp1.end()) {
                        auto it = find(temp2.begin(), temp2.end(), *z);
                        if (it != temp2.end())
                            f.push_back(*z);
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
                        f.push_back(*z);
                        z++;
                    }
                }
                if(temp2.size()>0){
                    auto y = temp2.begin();
                    while (y != temp2.end()) {
                        auto it = find(temp1.begin(), temp1.end(), *y);
                        if(it == temp1.end())
                            f.push_back(*y);
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
                        f.push_back(*z);
                        //cout<<*z<<endl;
                        z++;
                    }
                }
            }
            vector<string> final;//remember this is backwards
            if(authBool){
                vector<string>& temp4 = index.getAuthDocs(words[words.size()-1]);
                if(temp4.size() > 0) {
                    auto d = temp4.begin();
                    while (d != temp4.end()) {
                        auto it = find(f.begin(), f.end(), *d);
                        if (it != f.end()) {
                            final.push_back(*d);
                        }
                        d++;
                    }
                    printDocs(final);
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
                            final.push_back(*d);
                        }
                        d++;
                    }
                    printDocs(final);
                }
                notBool = false;
            }
            else{
                final = f;
                printDocs(final);
            }
            char sum = ' ';
            int num;
            while (sum!= 'n' && sum != 'N') {
                cout << "Would you like a summary of an article? (y/n) ->";
                cin >> sum;
                if (sum == 'y' || sum == 'Y') {
                    printDocs(final);
                    cout << "Input the number of the article you wish to explore ->";
                    cin >> num;
                    if (num <= final.size())
                        printSummary(final[num - 1]);
                    else {
                        while (num > final.size()) {
                            cout << "Please input a valid article number ->" << endl;
                            cin >> num;
                        }
                        printSummary(final[num - 1]);
                    }
                }
            }

            f.clear();
            final.clear();
        };
        void printDocs(vector<string>& final){
            string temp;
            Document d;
            for (int i = 0; i<final.size(); i++){
                temp = "cs2341_data/"+ final[i]+".json";
                ifstream fp(temp);
                IStreamWrapper isw(fp);
                d.ParseStream(isw);

                StringBuffer buffer;
                Writer<StringBuffer> writer(buffer);
                d.Accept(writer);

                if (d.HasParseError()) {
                    std::cout << "Error  : " << d.GetParseError() << '\n'
                              << "Offset : " << d.GetErrorOffset() << '\n';
                }
                else {
                    Value &s = d["metadata"];
                    Value &t = s["title"];
                    Value &c = s["authors"];
                    string title = t.GetString();
                    string first = c[0]["first"].GetString();
                    string last = c[0]["last"].GetString();
                    cout<<i+1<<". "<<title<<endl;
                    cout<<"     Author: "<<first<<" "<<last<<endl;
                }
            }
        };
        void printSummary(string& id){
            string temp = "cs2341_data/"+ id+".json";
            Document d;
            ifstream fp(temp);
            IStreamWrapper isw(fp);
            d.ParseStream(isw);

            StringBuffer buffer;
            Writer<StringBuffer> writer(buffer);
            d.Accept(writer);

            if (d.HasParseError()) {
                std::cout << "Error  : " << d.GetParseError() << '\n'
                          << "Offset : " << d.GetErrorOffset() << '\n';
            }
            Value &s = d["metadata"];
            Value &t = s["title"];
            string title = t.GetString();
            cout<<title<<endl;
            cout<<endl;
            Value &l = d["abstract"];
            if(l.Size() == 0){
                Value &g = d["body_text"];
                string f = g[0]["text"].GetString();
                cout<<f<<endl;
            }
            string p;
            for (SizeType i = 0; i < l.Size(); i++) {
                p = l[i]["text"].GetString();
                cout<<"     "<<p<<endl;
            }
        };
};

#endif //FINALPROJECT_QUERY_H
