#include <vector>
#include <iostream>
#include "Autocomplete.h"
#include "PrefixMatcher.h"

int main(){

    PrefixMatcher b;

    b.insert("01", 1);

    b.insert("0101", 2);

    std::cout << b.selectRouter("010100110") << "\n";

    return 0;

}