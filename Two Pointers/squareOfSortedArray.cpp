#include<bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int> &arr) {
    int i = 0, j = arr.size() - 1;
    int k = arr.size() - 1;
    vector<int> output(arr.size(), 0);
    while(i <= j) {
        int value1 = arr[i] * arr[i];
        int value2 = arr[j] * arr[j];
        if(value1 > value2) {
            output[k--] = value1;
            i++;
        } else {
            output[k--] = value2;
            j--;
        }
    }

    return output;
}

int main () {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> output = sortedSquares(arr);
    for(int i = 0; i < output.size(); i++) cout << output[i] << " ";
    return 0;
}