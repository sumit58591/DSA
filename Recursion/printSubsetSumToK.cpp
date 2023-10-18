#include<iostream>
using namespace std;

void printSubsetSumToK(int* input, int n, int *output, int outputSize, int sum) {
    if(n == 0) {
        if(sum == 0) {
            for(int i = 0; i < outputSize; i++) cout << output[i] << " ";
            cout << endl;
            return;
        }
        return;
    }

    printSubsetSumToK(input + 1, n - 1, output, outputSize, sum);
    output[outputSize] = input[0];
    printSubsetSumToK(input + 1, n - 1, output, outputSize + 1, sum - input[0]);
}

void printSubsetSumToK(int* input, int n, int sum) {
    int *output = new int[n];
    int outputSize = 0;
    printSubsetSumToK(input, n, output, outputSize, sum);
    delete [] output;
    return;
}

int main () {
    int n;
    cin >> n;
    int* input = new int[n];
    for(int i = 0; i < n; i++) cin >> input[i];
    int sum;
    cin >> sum;
    printSubsetSumToK(input, n, sum);
    delete [] input;
    return 0;
}