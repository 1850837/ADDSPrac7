#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <vector>
#include <string>

class Autocomplete {
    private:
    struct TrieNode {
        bool isEndOfWord;
        std::vector<TrieNode *> children;
    };

    TrieNode* root;

    public:
    Autocomplete();     //constructor
    void insertKey(std::string word);
    std::vector<std::string> getSuggestions(std::string partialWord);

};

#endif