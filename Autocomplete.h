#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <vector>
#include <string>

#include "Node.h"

class Autocomplete {
    private:
    Node* root;

    public:
    Autocomplete();     //constructor
    Node* getRoot();
    void insertKey(std::string word);
    std::vector<std::string> getSuggestions(std::string partialWord);
    std::string searchPrefix(Node* node, std::string prefix, std::vector<std::string>* result);
};

#endif