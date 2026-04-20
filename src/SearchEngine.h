#pragma once
#include <map>
#include <set>
#include <string>

class SearchEngine{
    private:
         // The Inverted Index: Word -> File Set
        std::map<std::string, std::map<std::string, int>> index;
        std::set<std::string> documents;

    public:
        std::string normalize(std::string word);

        void indexFile(const std::string& filename);
        void search(const std::string& query);

        void saveIndex(const std::string& filename);
        void loadIndex(const std::string& filename);

        bool isEmpty() const;
};