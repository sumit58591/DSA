#include<iostream>
using namespace std;

void printSubset(int* input, int inputSize, int* output, int outputSize) {
    if(inputSize == 0) {
        for(int i = 0; i < outputSize; i++) cout << output[i] << " ";
        cout << endl;
        return;
    }

    printSubset(input + 1, inputSize - 1, output, outputSize);
    output[outputSize] = input[0];
    printSubset(input + 1, inputSize - 1, output, outputSize + 1);
}

void printSubset(int* input, int size) {
    int* output = new int[size];
    int outputSize = 0;
    printSubset(input, size, output, outputSize);
}

int main () {
    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++) cin >> input[i];
    printSubset(input, n);
    delete [] input;
    return 0;
}