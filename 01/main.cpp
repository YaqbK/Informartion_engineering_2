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
            cout << "invalid";

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

class Complex {
    float real_;
    float imaginary_;

public:
    Complex(float real, float im){
        real_ = real;
        imaginary_ = im;
    }
    Complex(float real){
        real_ = real;
        imaginary_ = 0.0;
    }
    void set_real(float real){
        real_ = real;
    }
    float real(){
        return real_;
    }
    void set_im(float imaginary){
        imaginary_ = imaginary;
    }
    float imaginary(){
        return imaginary_;
    }
    void add(Complex b){
        real_ += b.real_;
        imaginary_ += b.imaginary_;
    }
    void print(){
        cout << real_ << imaginary_ << endl;
    }
};

int main()
{
    Complex a(1.0, -2.0); // creates 1-2i
    Complex b(3.14); // creates 3.14

    b.set_im(-5);

    Complex c = a.add(b); // I don't really understand the error here

    c.print(); // prints 4.14-7i
    return 0;
}
