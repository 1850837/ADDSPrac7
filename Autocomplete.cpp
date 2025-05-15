#include "Autocomplete.h"
#include <iostream>

Autocomplete::Autocomplete(){
    root = new Node;
}

Node* Autocomplete::getRoot(){
    return root;
}

void Autocomplete::insert(std::string word){

    Node* current = root;

    for (int i = 0; i < word.length(); i++){

        if (current->children.find(word[i]) == current->children.end()){   //while it can't find the current letter in the map
            current->children.insert({word[i], new Node()});
            current = current->children[word[i]];
        } 
        
        else {
            current = current->children[word[i]];
        }
    }

    current->isEndOfWord = true;

    return;

}

std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord){
    Node* current = root;
    std::vector<std::string> result = {};
    std::vector<std::string>* rStr = &result;
    
    //traversing to the right branch
    for (int i = 0; i < partialWord.length(); i++){
        current = current->children.find(partialWord[i])->second;
    }

    searchPrefix(current, partialWord, rStr);

    return result;

}

void Autocomplete::searchPrefix(Node* node, std::string prefix, std::vector<std::string>* result){
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

    if (node->isEndOfWord){
        result->push_back(prefix);
    }

    if (node->children.size() == 0){
        return;
    }
    
    for (char c : alphabet){
        if (node->children.find(c) != node->children.end()){
            searchPrefix(node->children[c], prefix + c, result);
        }
    }

    return;
}