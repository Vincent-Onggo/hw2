//
// Created by Vincent Onggoputra on 2/4/24.
//

#ifndef CS104_CLOTHING_H
#define CS104_CLOTHING_H
#include "product.h"
#include <iostream>
using namespace std;

class Clothing : public Product{

    set<string> keywords() const;
    string displayString() const;
    void dump(ostream& data) const;

public:
    Clothing(string name, float price, double quantity, string cat, string size, string brand);

private:
    string size_, brand_;

};


#endif //CS104_CLOTHING_H
