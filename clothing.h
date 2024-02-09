//
// Created by Vincent Onggoputra on 2/4/24.
//

#ifndef CS104_CLOTHING_H
#define CS104_CLOTHING_H
#include "product.h"
#include <iostream>
using namespace std;

class Clothing : public Product{
public:
    Clothing(string name, double price, int quantity, string cat, string size, string brand);
    set<string> keywords() const;
    string displayString() const;
    void dump(ostream& data) const;


private:
    string size_, brand_;

};


#endif //CS104_CLOTHING_H
