//
// Created by Vincent Onggoputra on 2/4/24.
//
#include "util.h"
#include <iostream>
#include <cctype>

using namespace std;

int main(){
    set<string> keyWords;
    keyWords = parseStringToWords("MeN's");
    for(auto i : keyWords){
        cout << i << endl;
    }
}
