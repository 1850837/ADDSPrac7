#include <vector>
#include <iostream>
#include "Autocomplete.h"

int main(){

    Autocomplete a;

    a.insertKey("ad");

    a.insertKey("advert");

    a.insertKey("advise");


    a.getSuggestions("a");

    return 0;

}