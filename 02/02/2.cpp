#include <iostream>
#include <vector>

using namespace std;

class Item{
    string name;
    float unp;
    char vat_type;
    int amount;
    friend class Invoice;

};

class Invoice{
    vector<int> NIP_buyer_, NIP_seller_;
    vector<Item> items_;

public:

    void add_item(const Item &item){
        items_.emplace_back(item);
    }

    void print_info(){
        cout << "---------------VAT invoice---------------" << endl;
        cout << "=========================================" << endl;
        cout << "Seller: ";
        for(auto digit : NIP_seller_){
            cout << digit;
        } cout << "         ";
        cout << "Buyer: ";
        for (auto digit : NIP_buyer_){
            cout << digit;
        } cout << "\n" << endl;

        int len = 0;
        for (auto item : items_){
            if(item.name.length() > len)
                len = item.name.length();
        }
        for (int i = 0; i <= len+5; i++){
            cout << " ";
        } cout << "c.j. VAT   il.   net   total" << endl;

        cout << "items: " << endl;
        for (auto it : items_){

        }
    }
};


