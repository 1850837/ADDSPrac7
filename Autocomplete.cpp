#include "Autocomplete.h"

Autocomplete::Autocomplete(){
    root = new Node;
}

void Autocomplete::insertKey(std::string word){
    //ensuring it's all lowercase
    for (int i = 0; i < word.length(); i++){
        if (word[i] > 96){
            word[i] = word[i] - 32;
        }
    }

    //check if it's empty
    bool empty = true;
    for (int i = 0; i < 26; i++){
        if (root->children[i].empty() == false){
            empty = false;
        }
    }

    //case for it being empty
    if (empty == true){
        Node* current = root;

        for (int i = 0; i < word.length(); i++){

            //checking for end of world
            if (word.back() == word[i]){
                current->isEndOfWord = true;
            }

            else {
                int chara = static_cast<int>(word[i]) - 97; //a = 0, b = 1, ..., z = 25
                current = current->children[chara];
            }
        }
    } 
    
    //case for it not being empty
    else {

    }
}

std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord){

}