// Final Project: Search Engine
// Author: Kylie Jordan
// Class: CS 2341 section 801
// Lab section: N14
//
// This program implements a search engine with an inverse file index populated with words from a corpus of
// 12,000 articles in JSON format. The query processor handles boolean queries prefixed with AND and OR,
// or including AUTHOR or NOT. The user can also enter a simple word. After the query is entered, the search
// engine will output the top 15 articles and their first author featuring the/these words based on the
// boolean value. The ranking of the top 15 is determined by word frequency within the article; the first
// article printed has the highest frequency followed by the next highest and so on. When prompted, the user
// can ask for a ~300 word excerpt from an article from the top 15 list printed. The search engine can also
// print statistics on the index when prompted. Stats include: number of articles indexed, average number
// of indexed words per article, total number of words in index, and total number of unique authors.
//
#include "Handler.h"
#include "Query.h"

using namespace std;

//main()
int main(int argc, char* argv[]) {
    Handler *h;
    Query q;
    q.makeIndex();      //populates the index with 12,000 articles
    char endProg = 'y';
    int option;
    while (endProg != 'n' && endProg != 'N') {  //loop to keep program running until user termination
        cout << "User options: " << endl;
        cout << "     1. Enter search query" << endl;
        cout << "     2. Print index stats" << endl;
        cout << "Please enter the option number here ->";
        cin >> option;
        if (option == 1) {
            q.startQueryUI();           //query for search terms
        } else if (option == 2) {
            q.printStats();             //index statistics
        }
        cout<<"Do you wish to choose another option? (y/n) ->";
        cin>>endProg;
    }
    return 0;
}