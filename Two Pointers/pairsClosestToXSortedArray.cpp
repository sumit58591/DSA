#include<bits/stdc++.h>
using namespace std;

vector<int> findPairs(vector<int>& arr, int n, int x) {
    vector<int> output;
    int i = 0, j = n - 1;
    int diff = INT_MAX;
    int firstNumberIndex = 0, secondNumberIndex = 1;
    while(i < j) {
        int pairsSum = arr[i] + arr[j];
        int currDiff = abs(x - pairsSum);
        // cout << "currDiff: " << currDiff << endl; 
        if(currDiff < diff) {
            firstNumberIndex = i;
            secondNumberIndex = j;
            diff = currDiff;
        }

        // cout << "currPairs: " << arr[firstNumberIndex] << " " << arr[secondNumberIndex] << endl;
        if(pairsSum > x) j--;
        else i++;
    }

    output.push_back(arr[firstNumberIndex]);
    output.push_back(arr[secondNumberIndex]);
    return output;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int x;
    cin >> x;
    vector<int> output = findPairs(arr, n, x);
    for(int i = 0; i < output.size(); i++) cout << output[i] << " ";
    return 0;
}