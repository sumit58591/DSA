#include <iostream>
using namespace std;

int subset(int* input, int length, int output[][20]) {
    if(length == 0) {
        output[0][0] = {0};
        return 1;
    }

    int smallOutput[3500][20];
    int smallOutputSize = subset(input + 1, length - 1, smallOutput);
    int k = 0;
    for(int i = 0; i < smallOutputSize; i++) {
        for(int j = 0; j <= smallOutput[i][0]; j++) {
            output[k][j] = smallOutput[i][j];  
        }    
        k++;
    }

    for(int i = 0; i < smallOutputSize; i++) {
        output[k][0] = smallOutput[i][0] + 1;
        for(int j = 1; j <= smallOutput[i][0]; j++) {
            output[k][j + 1] = smallOutput[i][j];
        }
        output[k][1] = input[0];
        k++;
    }
    return 2 * smallOutputSize;
}

int main() {
    int length;
    cin >> length;
    int* input = new int[length];
    int output[3500][20];
    for(int i = 0; i < length; i++) cin >> input[i];
    int size = subset(input, length, output);

    for( int i = 0; i < size; i++) { 
        for( int j = 1; j <= output[i][0]; j++) { 
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

    delete [] input;
    return 0;
}
