//
// Created by Vincent Onggoputra on 2/4/24.
//

#include "movie.h"
#include "util.h"
#include "product.h"
#include <iomanip>
#include <sstream>

Movie::Movie(std::string name, double price, int quantity, std::string cat, std::string genre, std::string rating) : Product(cat, name, price, quantity){
    rating_ = rating;
    genre_ = genre;

}

set<string> Movie :: keywords() const{
    set <string> keys, genre_key, name_key;
    genre_key = parseStringToWords(genre_);
    name_key = parseStringToWords(name_);
    keys = setUnion(name_key, genre_key);
    return keys;

}

string Movie ::displayString() const {
    stringstream ss;
    ss << fixed << std::setprecision(2) << price_;
    string price = ss.str();
    string qty = to_string(qty_);
    string output = name_ + "\n" + "Genre: " + genre_ + " Rating: " + rating_ + "\n" + price + " " + qty + " left.";
    return output;
}

void Movie :: dump(ostream& os) const{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << "\n";
}