#include <iostream>
#include <vector>
#include <map>
#include "header2.h"

using namespace std;

map<char, float> vat{{'A', 1.23}, {'B', 1.08}, {'C', 1}};

class Item{
    string name;
    float unp;
    char vat_type;
    int amount;
    friend class Invoice;
    friend void print_item_amount(const Item &item);
    friend void print_item_net(const Item &item);
    friend void print_item_total(const Item &item);
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
        float net_total = 0, total_total = 0;
        for (auto it : items_){
            cout << j++ << ". " << it.name;
            fill(len, it.name);
            cout << "| " << it.unp << "  " << it.vat_type << " |";
            print_item_amount(it);
            print_item_net(it);
            print_item_total(it);
            net_total += it.amount*it.unp;
            total_total += net_total*vat[it.vat_type];
        }
        cout << "\n\n------------------------------- TOTAL ----" << endl;
        cout << "                             " << net_total << " | " << total_total << endl;
    }
};

void fill(const int &len, const string &name){
    for (int i = 0; i < (len - name.length()+3); ++i) {
        cout << " ";
    }
}

void print_item_amount(const Item &item){
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

void print_item_net(const Item &item){
    float net = item.amount*item.unp;
    string snet = to_string(net);
    if (snet.length() > 4)
        cout << net;
    else if (snet.length() > 3)
        cout << " " << net;
    else if (snet.length() < 2)
        cout << "   " << net << " ";
    else if (snet.length() < 3)
        cout << "  " << net << " ";
    else cout << " " << net << " ";
    cout << "| ";
}

void print_item_total(const Item &item){

    float total = item.amount*item.unp*vat[item.vat_type];
    string stotal = to_string(total);
    if (stotal.length() > 4)
        cout << total;
    else if (stotal.length() > 3)
        cout << " " << total;
    else if (stotal.length() < 2)
        cout << "    " << total;
    else if (stotal.length() < 3)
        cout << "   " << total;
    else cout << "  " << total;
}
