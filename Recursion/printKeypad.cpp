#include<iostream>
using namespace std;

void printKeypad(int num, string output, string helper[]) {
    if(num == 0 or num == 1) {
        cout << output << endl;
        return;
    }

    int tempNum = num % 10;
    string tempString = helper[tempNum];
    for(int i = 0; i < tempString.length(); i++) {
        char tempChar = tempString[i];
        printKeypad(num / 10, tempChar + output, helper);
    }
}

void printKeypad(int num) {
    string helper[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string output = "";
    printKeypad(num, output, helper);
}

int main () {
    int num;
    cin >> num;
    printKeypad(num);
    return 0;
}