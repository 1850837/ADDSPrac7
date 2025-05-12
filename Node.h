#ifndef NODE_H
#define NODE_H

#include <vector>

class Node {
    friend class Autocomplete;
    
    private:
    bool isEndOfWord;
    std::vector<Node*> children[26];

    public:
    Node();
};

#endif