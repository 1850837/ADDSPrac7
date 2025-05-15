#include <vector>
#include <iostream>
#include "Autocomplete.h"
#include "PrefixMatcher.h"

int main(){

    PrefixMatcher a;

    a.insert("11001100110", 4);

    a.insert("101", 6);

    a.selectRouter("1");

    return 0;

}