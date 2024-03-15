#include <iostream>
#include <vector>
#include "header2.h"

using namespace std;

class Item{
    string name;
    float unp;
    char vat_type;
    int amount;
    friend class Invoice;
    friend void print_item_amount(const Item &item, int len);
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

        int j = 1; // counter
        for (auto it : items_){
            cout << j++ << ". " << it.name;
            print_item_amount(it, len);
        }
    }
};

void print_item_amount(const Item &item, int len){
    for (int i = 0; i < (len - item.name.length()+3); ++i) {
        cout << " ";
    } cout << "| " << item.unp << "  " << item.vat_type << " |";
    if (item.amount > 9999)
        cout << item.amount;
    else if (item.amount > 999)
        cout << " " << item.amount;
    else if (item.amount < 10)
        cout << "   " << item.amount << " ";
    else if (item.amount < 100)
        cout << "  " << item.amount << " ";
    else cout << " " << item.amount << " ";
    cout << "| ";
}
