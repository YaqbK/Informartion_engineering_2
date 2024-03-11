#include <iostream>
#include <vector>
#include <string>
#include <cmath>


using namespace std;

class Time {
public:
    Time() : hours_(0), minutes_(0), seconds_(0) {}

    Time(int hours, int minutes, double seconds) {
        if (hours < 0 || minutes < 0 || seconds < 0 || seconds >= 60) {
            cout << "Time components cannot be negative or have seconds exceeding 60" << endl;
        }
        hours_ = hours;
        minutes_ = minutes;
        seconds_ = seconds;
    }

    void read_from_user(){
        int hours = 0, minutes = 0;
        int seconds = 0;
        vector<char> vec;
        string str, temp;
        cout << "Enter time (either seconds or in given format 'hh:mm:ss'" << endl;
        cin >> str;

        if (str.find(":") != string::npos){
            for (auto c : str){
                vec.emplace_back(c);
            }
            temp = vec[0] + vec[1];
            hours = stoi(temp);
            temp = vec[3] + vec[4];
            minutes = stoi(temp);
            temp = vec[6] + vec[7];
            seconds = stoi(temp);
        }
        else {
            minutes += stoi(str) / 60;
            seconds = fmod(stoi(str), 60);
            hours += minutes / 60;
            minutes %= 6;
        }
        hours_ = hours;
        minutes_ = minutes;
        seconds_ = seconds;
    }

    double seconds(){
        return hours_*60*60 + minutes_*60 + seconds_;
    }

private:
    int hours_;
    int minutes_;
    double seconds_;
};

int main()
{
    return 0;
}
