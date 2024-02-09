//
// Created by Vincent Onggoputra on 2/5/24.
//

#include "mydatastore.h"
#include "util.h"

MyDataStore::MyDataStore(): DataStore() {

}

MyDataStore::~MyDataStore() {
    // Delete products
    for (size_t i = 0; i < products.size(); ++i) {
        delete products[i];
    }


    // Delete users
    for (size_t i = 0; i < users.size(); ++i) {
        delete users[i];
    }


    // Delete products in productKeys
    for (unordered_map<string, set<Product*>>::iterator it=productKeys.begin(); it != productKeys.end(); ++it) {
        it->second.clear();
    }


    // Delete products in carts
    for (unordered_map<string, vector<Product*>>::iterator it=carts.begin(); it != carts.end(); ++it) {
        it->second.clear();
    }

}

void MyDataStore::addProduct(Product *p) {

    std::cout << "[addProduct()] starting\n";

    products.push_back(p);
    
    set<string> keyWords = p->keywords();
    // entering the product and keyword pair into the hash map
    for(set<string>::iterator it = keyWords.begin(); it != keyWords.end(); ++it){
        if(productKeys.find(*it) == productKeys.end()){ // if the key does not exist yet
            // add key into productKeys
            set<Product*> newProduct;
            newProduct.insert(p);
            productKeys.insert(make_pair(*it, newProduct));
        }else{
            // if key already exist, attach the product to the associated key
            productKeys.find(*it)->second.insert(p);
        }

    }
    std::cout << "[addProduct()] added product\n";
}

void MyDataStore::addUser(User *u) {

    std::cout << "[addUser()] starting fn\n";

    // check if user exist already
    bool exist = false;
    for(size_t i=0; i<users.size(); i++){
        if(u->getName() == users[i]->getName()){
            exist = true;
        }
    }
    if(!exist){
        users.push_back(u);
    }
}

std::vector<Product*> MyDataStore::search(std::vector<std::string> &terms, int type) {
    vector<Product*> hits;
    set<Product*> temp1, temp2;
    if(terms.size() == 0){
        return hits; // return empty vector in case that no terms searched
    }
    // search the first term
    if(productKeys.find(terms[0]) != productKeys.end()){ // if first term found in key list
        temp1 = productKeys.find(terms[0])->second;
    }

    for(vector<string>::iterator it=terms.begin(); it != terms.end(); ++it){
        unordered_map<string, set<Product*>>::iterator results = productKeys.find(*it);
        if(results != productKeys.end()){
            temp2 = results->second;
        }
        if(type == 0){
            temp1 = setIntersection(temp1, temp2);
        }else{
            temp1 = setUnion(temp1, temp2);
        }
    }
    for(set<Product*>::iterator it = temp1.begin(); it!=temp1.end(); ++it){
        hits.push_back(*it);
    }
    return hits;

}

void MyDataStore::dump(std::ostream &ofile) {
    ofile << "<products>" << "\n";
    for(int i=0; i<products.size(); i++){
        products[i]->dump(ofile);
    }
    ofile << "</products>" << "\n";

    ofile << "<users>" << "\n";
    for(int i=0; i<users.size(); i++){
        users[i]->dump(ofile);
    }
    ofile << "</users>";
}

bool MyDataStore::checkUser(std::string username) {

    for(vector<User*>::iterator it = users.begin(); it != users.end(); ++it){
        if((*it)->getName() == username){
            return true;
        }
    }
    return false;
}

void MyDataStore::addToCart(std::string username, Product* item){
    if(carts.find(username) == carts.end()){ // if user does not have a cart - make one
        vector<Product*> temp;
        temp.push_back(item);
        carts.insert(make_pair(username, temp));
    }else{
        carts.find(username)->second.push_back(item);
        for(auto i : carts.find(username)->second){
            cerr << i->getName() << endl;
        }
    }
}

vector<Product*> MyDataStore::getCart(std::string username) {
    vector<Product*> cart = carts.find(username)->second;
    return cart;
}
void MyDataStore::buyCart(std::string username) {
    auto cart_iter = carts.find(username);

    if (cart_iter != carts.end()) {
        vector<Product*>& cart = cart_iter->second;
        User* buyer = nullptr;

        for (User* user : users) {
            if (user->getName() == username) {
                buyer = user;
                break;
            }
        }

        if (buyer) {
            auto it = cart.begin();
            while (it != cart.end()) {
                Product* product = *it;
                if (product->getQty() > 0 && buyer->getBalance() >= product->getPrice()) {
                    buyer->deductAmount(product->getPrice());
                    product->subtractQty(1);
                    it = cart.erase(it);  // erase returns the next iterator
                } else {
                    ++it;
                }
            }
        }
    }
}

