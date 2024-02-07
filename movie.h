//
// Created by Vincent Onggoputra on 2/4/24.
//

#ifndef CS104_MOVIE_H
#define CS104_MOVIE_H

#include "product.h"
#include <iostream>
using namespace std;

class Movie : public Product {
public:
    Movie(string name, float price, int quantity, string cat, string genre, string rating);

    set<string> keywords() const;
    string displayString() const;
    void dump(ostream& data) const;
private:
    string genre_, rating_;
};


#endif //CS104_MOVIE_H
