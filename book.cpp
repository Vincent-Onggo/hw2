//
// Created by Vincent Onggoputra on 2/4/24.
//
#include "book.h"
#include "util.h"
#include "product.h"
#include <sstream>
#include <iomanip>
Book::Book(std::string name, double price, int quantity, std::string cat, std::string isbn, std::string author):Product(cat, name, price, quantity){
    author_ = author;
    isbn_ = isbn;
}

set<string> Book::keywords() const {
    set<string> list, name_keys, author_keys, isbn_keys;
    name_keys = parseStringToWords(name_);
    author_keys = parseStringToWords(author_);
    isbn_keys.insert(isbn_);
    list = setUnion(name_keys, author_keys);
    list = setUnion(list, isbn_keys);
    return list;
}

string Book::displayString() const {
    stringstream ss;
    ss << fixed << std::setprecision(2) << price_;
    string price = ss.str();
    string qty = to_string(qty_);
    string output = name_ + "\n" + "Author: " + author_ + " ISBN: " + isbn_ + "\n" + price + " " + qty + " left.";
    return output;
}

void Book::dump(std::ostream& os) const {
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << isbn_ << "\n" << author_ << "\n";
}