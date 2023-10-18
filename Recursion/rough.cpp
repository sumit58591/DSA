#include<iostream>
using namespace std;

int getInteger(char val) {
    return val - '0';
}

char getChar(int num) {
    return 'a' - 1 + num;
}

int main () {
    string input = "abc";
    for(int i = 0; i < input.length(); i++) {
        string temp = input.substr(0, i) + input.substr(i + 1);
        cout << temp << endl;
    }
}