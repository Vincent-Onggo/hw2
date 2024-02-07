//
// Created by Vincent Onggoputra on 2/4/24.
//

#include "clothing.h"
#include "util.h"
#include <sstream>
Clothing ::Clothing(std::string name, float price, double quantity, std::string cat, std::string size,
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
    stringstream ss;
    ss << price_ << qty_ << " is left.";
    string output = name_ + "\n" + "Size: " + size_ + " Brand: " + brand_ + "\n" + ss.str();
    return output;
}

void Clothing :: dump(ostream& os) const{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << size_ << "\n" << brand_ << "\n";
}