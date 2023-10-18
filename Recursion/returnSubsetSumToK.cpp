#include<iostream>
using namespace std;

int subsetSumToK(int* input, int n, int output[][20], int k) {
    if(n == 0) {
        if(k == 0) {
            output[0][0] = 0;
            return 1;
        }
        return 0;
    }

    int smallOutput1[3500][20], smallOutput2[3500][20];
    int smallOutputSize1 = subsetSumToK(input + 1, n - 1, smallOutput1, k);
    int smallOutputSize2 = subsetSumToK(input + 1, n - 1, smallOutput2, k - input[0]);
    int p = 0;
    for(int i = 0; i < smallOutputSize1; i++) {
        for(int j = 0; j <= smallOutput1[i][0]; j++) {
            output[p][j] = smallOutput1[i][j];
        }
        p++;
    }

    for(int i = 0; i < smallOutputSize2; i++) {
        output[p][0] = smallOutput2[i][0] + 1;
        for(int j = 1; j <= smallOutput2[i][0]; j++) {
            output[p][j + 1] = smallOutput2[i][j];
        }
        output[p][1] = input[0];
        p++;
    }

    return p;
}

int main () {
    int n;
    cin >> n;
    int* input = new int[n];
    for(int i = 0; i < n; i++) cin >> input[i];
    int sum;
    cin >> sum;
    int output[3500][20];
    int outputSize = subsetSumToK(input, n, output, sum);
    for(int i = 0; i < outputSize; i++) {
        for(int j = 1; j <= output[i][0]; j++) {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

    delete [] input;
    return 0;
}