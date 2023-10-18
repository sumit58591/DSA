#include<iostream>
#include<string>
using namespace std;

int keypad_helper(int num, string output[], string helper[]) {
    if(num <= 1) {
        output[0] = "";
        return 1;
    }
    string smallOutputStrings[10000];
    int smallOutput = keypad_helper(num / 10, smallOutputStrings, helper);
    string tempString = helper[num % 10];
    int i = 0, k = 0;
    for(i = 0; i < tempString.length(); i++) {
        char tempChar = tempString[i];
        for(int j = 0; j < smallOutput; j++) {
            output[k++] = smallOutputStrings[j] + tempChar;
        }
    }
    return k;
}

int keypad(int num, string output[]) {
    string helper[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int finalOutput = keypad_helper(num, output, helper);
    return finalOutput;
}

int main () {
    int num;
    cin >> num;
    string output[10000];
    int count = keypad(num, output);
    cout << count << endl;
    for(int i = 0; i < count and i < 10000; i++) cout << output[i] << endl;
    return 0;
}