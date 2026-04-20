#include "SearchEngine.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cmath>

using namespace std;

string SearchEngine::normalize(string word){
    string cleanWord = "";

    for(char c : word){
        // Punctuation check
        if(!ispunct((unsigned char)c)){
            cleanWord += tolower((unsigned char)c); // Enable special characters.
        }
    }
    return cleanWord;
}

void SearchEngine::indexFile(const string& filename){
    ifstream file(filename);

    if(!file.is_open()){
        cout << "Error opening file: " << filename << endl;
        return; // Exit the function if the file does not exist.
    }

    documents.insert(filename);

    string word;

    while(file >> word){
        string cleanWord = normalize(word);

        // If the word is not empty, add it to the map.
        if(!cleanWord.empty()){
            index[cleanWord][filename]++;
        }
    }
}

void SearchEngine::search(const string& query){
    stringstream ss(query);
    string word;
    vector<string> words;

    // Separate and normalize.
    while(ss >> word){
        string cleanWord = normalize(word);
        if(!cleanWord.empty()){
            words.push_back(cleanWord);
        }
    }

    if(words.empty()){
        cout << "Invalid search." << endl;
        return;
    }

    if(documents.empty()){
        cout << "No documents indexed." << endl;
        return;
    }

    map<string, double> scores;
    double N = (double)documents.size();

    // Calculate score for each document based on term relevance
    for(const string& w : words){
        auto it = index.find(w);
        if(it == index.end()) continue;

        double df = (double)it->second.size();
        if(df == 0) continue;

        // Inverse Document Frequency (IDF)
        double idf = log(N / df + 1) + 1;

        for(const auto& pair : it->second){
            const string& file = pair.first;
            int tf = pair.second; // Term Frequency (TF)

            scores[file] += tf * idf;
        }
    }

    if(scores.empty()){
        cout << "No results found." << endl;
        return;
    }

    // Sort documents by their calculated score (descending)
    vector<pair<string, double>> ranked(scores.begin(), scores.end());

    sort(ranked.begin(), ranked.end(), [](const auto& a, const auto& b){
        return a.second > b.second;
    });

    cout << "Results for '" << query << "':\n";

    for(const auto& pair : ranked){
        cout << "- " << pair.first << " (score: " << pair.second << ")\n";
    }
}

// Export index.dat
void SearchEngine::saveIndex(const string& filename){
    ofstream out(filename);

    if(!out.is_open()){
        cout << "Error saving index.\n";
        return;
    }

    for(const auto& [word, files] : index){
        out << word;

        for(const auto& [file, count] : files){
            out << " " << file << " " << count;
        }

        out << "\n";
    }

    cout << "Index saved successfully.\n";
}

// Import index.dat
void SearchEngine::loadIndex(const string& filename){
    ifstream in(filename);

    if(!in.is_open()){
        cout << "No saved index found.\n";
        return;
    }

    index.clear();
    documents.clear();

    string line;

    // Parse each line: word followed by file-count pairs
    while(getline(in, line)){
        stringstream ss(line);
        string word;
        ss >> word;

        string file;
        int count;

        while(ss >> file >> count){
            index[word][file] = count;
            documents.insert(file);
        }
    }

    cout << "Index loaded successfully.\n";
}

// Returns true if the index is currently empty
bool SearchEngine::isEmpty() const {
    return index.empty();
}