//
// Created by Vincent Onggoputra on 2/4/24.
//

#ifndef CS104_BOOK_H
#define CS104_BOOK_H
#include "product.h"
#include <iostream>
using namespace std;

class Book : public Product{
public:
    Book(string name, float price, int quantity, string cat, string isbn, string author);

    set<string> keywords() const;
    string displayString() const;
    void dump(ostream& data) const;

private:
    string isbn_, author_;
};

#endif //CS104_BOOK_H
