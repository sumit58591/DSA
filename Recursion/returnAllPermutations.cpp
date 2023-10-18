#include<iostream>
using namespace std;

int returnAllPermutations(string input, string output[1000]) {
    if(input[0] == '\0') {
        output[0] = "";
        return 1;
    }
    int k = 0;
    for(int i = 0; i < input.length(); i++) {
        string smallOutput[1000];
        string temp = input.substr(0, i) + input.substr(i + 1); 
        int smallOutputSize = returnAllPermutations(temp, smallOutput);
        for(int j = 0; j < smallOutputSize; j++) {
            output[k++] = input[i] + smallOutput[j];
        }
    }

    return k;
}

int main () {
    string input;
    cin >> input;
    string output[1000];
    int outputSize = returnAllPermutations(input, output);
    for(int i = 0; i < outputSize; i++) cout << output[i] << endl;
    return 0;
}