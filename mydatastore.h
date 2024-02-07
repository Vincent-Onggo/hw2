//
// Created by Vincent Onggoputra on 2/5/24.
//

#ifndef CS104_MYDATASTORE_H
#define CS104_MYDATASTORE_H
#include "datastore.h"
#include <iostream>
#include <map>
#include <queue>

using namespace std;

class MyDataStore : public DataStore{
public:
    void addProduct(Product *p); // add a product to the data store

    void addUser(User *u); // add a user to the data store
    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    std::vector<Product*> search(std::vector<std::string>& terms, int type); // search keywords

    void dump(std::ostream& ofile); // reproduce data base file from current prodcuts and user values
    bool checkUser(string username); // check if username exist in the database
    void addToCart(std::string username, Product* item);
    vector<Product*> getCart(string username);
    void buyCart(string username);
private:
    vector<Product*> products;
    vector<User*> users;

    map<string, set<Product*> > productKeys;
    map<string, vector<Product*>> carts; // key is username, queue is for the product
};


#endif //CS104_MYDATASTORE_H
