#include "Autocomplete.h"
#include <iostream>

Autocomplete::Autocomplete(){
    root = new Node;
}

Node* Autocomplete::getRoot(){
    return root;
}

void Autocomplete::insertKey(std::string word){

    Node* current = root;

    for (int i = 0; i < word.length(); i++){

        if (current->children.find(word[i]) == current->children.end()){   //while it can find the current letter in the map

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
    
    //traversing to the right branch
    for (int i = 0; i < partialWord.length(); i++){
        current = current->children.find(partialWord[i])->second;
    }

}

std::string Autocomplete::searchPrefix(Node* node, std::string prefix, std::vector<std::string>* result){
    if (node->isEndOfWord == true){
        result->push_back(prefix);
    }

    for ();
}