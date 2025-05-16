#include "PrefixMatcher.h"
#include "Node.h"
#include <iostream>

PrefixMatcher::PrefixMatcher(){
    root = new Node;
}

void PrefixMatcher::insert(std::string address, int routerNumber){

    Node* current = root;

    for (int i = 0; i < address.length(); i++){

        if (current->children.find(address[i]) == current->children.end()){   //while it can't find the current letter in the map
            current->children.insert({address[i], new Node()});
            current = current->children[address[i]];

            std::cout << "Inserted " << address[i] << "\n";
        } 
        
        else {
            current = current->children[address[i]];
            
            std::cout << "Found " << address[i] << "\n";
        }
    }

    current->router = routerNumber;
    current->isEndOfWord = true;

    return;

}

int PrefixMatcher::selectRouter(std::string networkAddress){
    Node* current = root;
    std::vector<std::string> result = {};
    std::vector<std::string>* rStr = &result;
    
    //getting array of matches
    searchPrefix(current, networkAddress, rStr);

    //finding longest match
    int length = 0;
    int wordPos = 0;
    for (int i = 0; i < result.size(); i++){
        if (result[i].length() > length){
            length = result[i].length();
            wordPos = i;
        }
    }

    for (int i = 0; i < result.size(); i++){
        std::cout << result[i] << "\n";
    }

    //finding router number associated
    current = root;

    std::cout << "match = " << result[wordPos] << "\n";
    std::cout << result[wordPos][0] << "\n";

    for (int i = 0; i < length; i++){
        current = current->children[result[wordPos][i]];
        std::cout << "Num currently is " << result[wordPos][i] << "\n";
        std::cout << "Router currently is " << current->router << "\n";
    }

    //int number = current->router;

    return 0;

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