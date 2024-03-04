#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
public:
    void set_index(int index) {
        index_ = index;
    }
    int index() {
        return index_;
    }
    void set_name(string name){
        name_ = name;
    }
    string name(){
        return name_;
    }
    void set_surname(string surname){
        surname_ = surname;
    }
    string surname(){
        return surname_;
    }
    void set_album_num(int album_num) {
        album_num_ = album_num;
    }
    int album_num() {
        return album_num_;
    }
    void add_grade(float grade){
        if (grade >= 2.0){
            if (grade <= 5.0)
                grades_.emplace_back(grade);
        }
        else
            cout << "invalid"

    }
    vector<float> grades(){
        return grades_;
    }
private:
    int index_;
    string name_;
    string surname_;
    int album_num_;
    vector<float> grades_;
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
