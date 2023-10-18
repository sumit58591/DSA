#include<iostream>
using namespace std;

int subset(int input[], int n, int output[][20]) {
    if (n == 0) {
      output[0][0] = {0};
      return 1;
    }

    int smallOutput[35000][20];
    int smallOutputSize = subset(input + 1, n - 1, smallOutput);
    int k = 0;
    for (int i = 0; i < smallOutputSize; i++) {
      for (int j = 0; j <= smallOutput[i][0]; j++) {
        output[k][j] = smallOutput[i][j];
      }
      k++;
    }

    for (int i = 0; i < smallOutputSize; i++) {
      output[k][0] = 1 + smallOutput[i][0];
      for (int j = 1; j <= smallOutput[i][0]; j++) {
        output[k][j + 1] = smallOutput[i][j];
      }
      output[k][1] = input[0];
      k++;
    }
    return k;
}
void printSubsequence(string input, string output) {
    if(input[0] == '\0') {
        cout << output << endl;
        return;
    }

    printSubsequence(input.substr(1), output);
    printSubsequence(input.substr(1), output + input[0]);
}

int main () {
    string input;;
    cin >> input;
    string output = "";
    printSubsequence(input, output);
    return 0;
}