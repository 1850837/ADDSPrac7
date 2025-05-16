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
        } 
        
        else {
            current = current->children[address[i]];
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
    // searchPrefix(current, "", rStr);

    int j = 0;
    while (result.empty()){

        searchPrefix(current, networkAddress.substr(0, j), rStr);

        for (int i = 0; i < result.size(); i++){        //for every word in result
            if(result[i] != networkAddress.substr(0, result[i].size())){
                result.erase(result.begin() + i);
            }
        }

        j++;

        // if (j == networkAddress.length()) {
        //     break;
        // }
    }

    //finding longest match
    int length = 0;
    std::string number = "";
    for (int i = 0; i < result.size(); i++){        //for each router in the trie that matches the prefix
        if (result[i].length() > length){           //if it is longer than the last one
            length = result[i].length();            //save that length
            number = result[i];                     //and save the word
        }
    }

    //finding router number associated
    current = root;

    for (int i = 0; i < length; i++){
        current = current->children[number[i]];
    }

    int num = current->router;

    return num;

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