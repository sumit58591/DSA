#include<iostream>
using namespace std;

void printPermutations(string input, string output) {
    if(input[0] == '\0') {
        cout << output << endl;
        return;
    }

    for(int i = 0; i < input.length(); i++) {
        printPermutations(input.substr(0, i) + input.substr(i + 1), output + input[i]);
    }
    return;
}

void printPermutations(string input) {
    string output = "";
    printPermutations(input, output);
    return;
}

int main () {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}