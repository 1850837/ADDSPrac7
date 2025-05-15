#include "PrefixMatcher.h"
#include "Node.h"
#include <iostream>

PrefixMatcher::PrefixMatcher(){
    root = new Node;
}

void PrefixMatcher::insert(std::string address, int routerNumber){

    Node* current = root;

    std::string fullAddress = address + std::to_string(routerNumber);       //so now router 2 would be 2110011011 or whatever

    for (int i = 0; i < fullAddress.length(); i++){

        if (current->children.find(fullAddress[i]) == current->children.end()){   //while it can't find the current letter in the map
            current->children.insert({fullAddress[i], new Node()});
            current = current->children[fullAddress[i]];
        } 
        
        else {
            current = current->children[fullAddress[i]];
        }
    }

    current->isEndOfWord = true;

    return;

}

int PrefixMatcher::selectRouter(std::string networkAddress){
    Node* current = root;
    std::vector<std::string> result = {};
    std::vector<std::string>* rStr = &result;
    
    //traversing to the right branch
    for (int i = 0; i < networkAddress.length(); i++){
        current = current->children.find(networkAddress[i])->second;
    }

    searchPrefix(current, networkAddress, rStr);

    //find the longest one
    int length = 0;
    std::string word = "";
    for (int i = 0; i < result.size(); i++){
        if (result[i].length() > length){
            length = result[i].length();
            word = result[i];
        }
    }

    char num = word[word.length() - 1];
    int number = num - '0';

    return number;

}

void PrefixMatcher::searchPrefix(Node* node, std::string prefix, std::vector<std::string>* result){
    std::string numberbet = "0123456789";

    if (node->isEndOfWord){
        result->push_back(prefix);
    }

    if (node->children.size() == 0){
        return;
    }
    
    for (char c : numberbet){
        if (node->children.find(c) != node->children.end()){
            searchPrefix(node->children[c], prefix + c, result);
        }
    }

    return;
}