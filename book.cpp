//
// Created by Vincent Onggoputra on 2/4/24.
//
#include "book.h"
#include "util.h"
#include "product.h"
#include <sstream>
Book::Book(std::string name, double price, int quantity, std::string cat, std::string isbn, std::string author):Product(cat, name, price, quantity){
    author_ = author;
    isbn_ = isbn;
}

set<string> Book::keywords() const {
    set<string> list, name_keys, author_keys, isbn_keys;
    name_keys = parseStringToWords(name_);
    author_keys = parseStringToWords(author_);
    list = setUnion(name_keys, author_keys);
    list = setUnion(list, isbn_keys);
    return list;
}

string Book::displayString() const {
    string price = to_string(price_);
    string qty = to_string(qty_);
    string output = name_ + "\n" + "Author: " + author_ + " ISBN: " + isbn_ + "\n" + price + " " + qty + " left.";
    return output;
}

void Book::dump(std::ostream& os) const {
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << isbn_ << "\n" << author_ << "\n";
}