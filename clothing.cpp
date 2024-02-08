//
// Created by Vincent Onggoputra on 2/4/24.
//

#include "clothing.h"
#include "util.h"
#include <sstream>
Clothing ::Clothing(std::string name, double price, double quantity, std::string cat, std::string size,
                    std::string brand): Product(cat, name, price, quantity ) {
    size_ = size;
    brand_ = brand;
}

set<string> Clothing :: keywords() const{
    set<string> name_key, brand_key;
    name_key = parseStringToWords(name_);
    brand_key = parseStringToWords(brand_);

    return setUnion(name_key, brand_key);
}

string Clothing ::displayString() const {
    string price = to_string(price_);
    string qty = to_string(qty_);

    string output = name_ + "\n" + "Size: " + size_ + " Brand: " + brand_ + "\n" + price + " " + qty + " left.";
    return output;
}

void Clothing :: dump(ostream& os) const{
    cout << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << size_ << "\n" << brand_ << "\n";
}