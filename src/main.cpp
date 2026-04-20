#include <iostream>
#include "SearchEngine.h"

using namespace std;

int main(){

    SearchEngine engine;

    cout << "Loading index . . .\n";
    engine.loadIndex("../storage/index.dat");

    if(engine.isEmpty()){

        cout << "No index found. Indexing files . . .\n";

        engine.indexFile("../data/file1.txt");
        engine.indexFile("../data/file2.txt");
        engine.saveIndex("../storage/index.dat");
    } else {
        cout << "Index loaded successfully.\n";
    }

    string searchWord;
    cout << "--- SEARCH ENGINE ---" << endl;


    while(true){
        cout << "\nWhat do you want to search for? (or type 'exit' to quit): ";
        getline(cin, searchWord);

        if(searchWord == "reindex"){ // Command to update the index; the new index will be used for the next search.
            engine.indexFile("../data/file1.txt");
            engine.indexFile("../data/file2.txt");
            engine.saveIndex("../storage/index.dat");
            continue;
        }

        if(searchWord == "exit"){
            cout << "Closing program. . ." << endl;
            break;
        }

        engine.search(searchWord);

        cout << "---------------------------------------" << endl;

    }

    return 0;
}