#include<bits/stdc++.h>
using namespace std;

int sumOfDigit(int num) {
    if(num < 9) return num;
    return num % 10 + sumOfDigit(num / 10);
}

int findMaxPairsSum(vector<int>& arr, int n) {
    unordered_map<int, int> map;
    int outputSum = -1;
    for(int i = 0; i < n; i++) {
        int digitSum = sumOfDigit(arr[i]);
        if(map.find(digitSum) != map.end()) {
            int val = map[digitSum] + arr[i];
            outputSum = max(outputSum, val);
        }

        map[digitSum] = max(map[digitSum], arr[i]);
    }

    return outputSum;
}

int main () {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int output = findMaxPairsSum(arr, n);
    cout << output;
    return 0;
}