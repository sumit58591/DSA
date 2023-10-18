#include<iostream>
using namespace std;

int subsequence(string input, string* output) {
    if(input[0] == '\0') {
        output[0] = "";
        return 1;
    }

    string smallOutput[1000];
    int smallOutputSize = subsequence(input.substr(1), smallOutput);
    int k = 0;
    for(int i = 0; i < smallOutputSize; i++) {
        output[k++] = smallOutput[i];
    }

    for(int i = 0; i < smallOutputSize; i++) {
        output[k++] = input[0] + smallOutput[i];
    }

    return k;
}

int subsequence_spaceOptimise(string input, string* output) {
    if(input[0] == '\0') {
        output[0] = "";
        return 1;
    }

    int smallOutputSize = subsequence_spaceOptimise(input.substr(1), output);
    for(int i = 0; i < smallOutputSize; i++) {
        output[i + smallOutputSize] = input[0] + output[i];
    }

    return 2 * smallOutputSize;
}

int main () {
    string input;
    cin >> input;
    string* output = new string[1000];
    int outputSize = subsequence_spaceOptimise(input, output);
    for(int i = 0; i < outputSize; i++) cout << output[i] << endl;
    delete [] output;
    return 0;
}