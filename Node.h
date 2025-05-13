#ifndef NODE_H
#define NODE_H

#include <vector>
#include <unordered_map>

//key value pair of "a":Node*()

class Node {
    friend class Autocomplete;
    
    public:
    bool isEndOfWord;
    std::unordered_map<char, Node*> children;

    public:
    Node();
};

#endif