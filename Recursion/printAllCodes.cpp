#include<iostream>
using namespace std;

int getInteger(char val) {
    return val - '0';
}

char getChar(int num) {
    return 'a' - 1 + num;
}

void printAllCodes(string input, string output) {
    if(input[0] == '\0') {
        cout << output << endl;
        return;
    }

    int getIntegerVal = getInteger(input[0]);
    char getCharVal = getChar(getIntegerVal);
    printAllCodes(input.substr(1), output + getCharVal);
    if(input[1] != '\0') {
        int secondInteger = getInteger(input[1]);
        int finalNumber = 10 * getIntegerVal + secondInteger;
        if(finalNumber >= 10 and finalNumber <= 26) {
            char secondChar = getChar(finalNumber);
            printAllCodes(input.substr(2), output + secondChar);
            return;
        }
    }
    return;
}

int main () {
    string input;
    cin >> input;
    string output = "";
    printAllCodes(input, output);
    return 0;
}