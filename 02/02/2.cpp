#include <iostream>
#include <vector>

using namespace std;

class Invoice{
    vector<int> NIP_;
    vector<string> items_;

public:

    void add_item(const string item){
        items_.emplace_back(item);
    }

    void print_info(){
        cout << "NIP: ";
        for(auto digit : NIP_){
            cout << digit;
        } cout << endl;
        cout << "items: " << endl;
        for (auto item : items_){
            cout << item << endl;
        }
    }
};
