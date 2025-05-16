#include <vector>
#include <iostream>
#include "Autocomplete.h"
#include "PrefixMatcher.h"

int main(){

    PrefixMatcher b;

    b.insert("1100", 4);

    b.insert("101", 6);

    std::cout << b.selectRouter("110010") << "\n";

    return 0;

}