//
// Created by Vincent Onggoputra on 2/4/24.
//

#include "movie.h"
#include "util.h"
#include "product.h"
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
    ss << price_ << qty_ << " left.";
    string output = name_ + "\n" + "Genre: " + genre_ + " Rating: " + rating_ + "\n" + ss.str();
    return output;
}

void Movie :: dump(ostream& os) const{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << "\n";
}