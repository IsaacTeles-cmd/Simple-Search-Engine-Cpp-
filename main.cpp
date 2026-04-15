#include <iostream>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

class searchEngine{
    private:
        // The Inverted Index: Word -> File Set
        std::map<std::string, std::set<std::string>> index; 

    public:

        string normalize(string word){
            string cleanWord = "";

            for(char c : word){
                // Punctuation check
                if(!ispunct(c)){
                    cleanWord += tolower(c);
                }
            }
            return cleanWord;
        }

        void indexFile(string filename){
            ifstream file(filename);

            if(!file.is_open()){
                cout << "Error opening file: " << filename << endl;
                return; // Exit the function if the file does not exist.
            }

            string word;

            while(file >> word){
                string cleanWord = normalize(word);

                // If the word is not empty, add it to the map.
                if(!cleanWord.empty()){
                    index[cleanWord].insert(filename);
                }
            }
            file.close();
        }
        void search(string query){
            // Normalize the search to match the index.
            string cleanQuery = normalize(query);

            // The iterator points to the word's position on the map.
            auto it = index.find(cleanQuery);

            if(it != index.end()){
                cout << "The word '" << query << "' it was found in the following files.:" << endl;

                for(const string& filename: it->second){
                    cout << "- " << filename <<endl;
                }
            } else {
                cout << "The word '" << query << "' it was not found in any document." << endl;
            }
        }
};


int main(){

    searchEngine engine;

    cout << "Indexing files... Please wait." << endl;
    engine.indexFile("file1.txt");
    engine.indexFile("file2.txt");

    string searchWord;
    cout << "--- SEARCH ENGINE ---" << endl;


    while(true){
        cout << "\nWhat do you want to search for? (or type 'exit' to quit): ";
        getline(cin, searchWord);

        if(searchWord == "exit"){
            cout << "Closing program. . ." << endl;
            break;
        }

        engine.search(searchWord);

        cout << "---------------------------------------" << endl;

    }

    return 0;
}