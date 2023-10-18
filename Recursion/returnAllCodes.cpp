#include<iostream>
using namespace std;

int getInteger(char val) {
    return val - '0';
}

char getChar(int num) {
    return 'a' - 1 + num;
}

int getCodes(string input, string output[1000]) {
    if(input[0] == '\0') {
        output[0] = "";
        return 1;
    }

    string smallOutput1[1000];
    string smallOutput2[1000];
    int smallOutputSize1 = getCodes(input.substr(1), smallOutput1);
    int getIntegerVal = getInteger(input[0]);
    char getCharVal = getChar(getIntegerVal);
    int k = 0;
    for(int i = 0; i < smallOutputSize1; i++) {
        output[k++] = getCharVal + smallOutput1[i];
    }

    if(input[1] != '\0') {
        int secondIntegerVal = getInteger(input[1]);
        int finalNumber = 10 * getIntegerVal + secondIntegerVal;
        int smallOutputSize2 = 0;
        if(finalNumber >= 10 and finalNumber <= 26) {
            smallOutputSize2 = getCodes(input.substr(2), smallOutput2);
        }

        for(int i = 0; i < smallOutputSize2; i++) {
            output[k++] = getChar(finalNumber) + smallOutput2[i];
        }
        return k;
    }

    return k;
}

int main () {
    string input;
    cin >> input;
    string output[1000];
    int outputSize = getCodes(input, output);
    for(int i = 0; i < outputSize; i++) cout << output[i] << endl;
    return 0;   
}