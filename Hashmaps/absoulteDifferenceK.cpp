#include<bits/stdc++.h>
using namespace std;

int countKDifference(vector<int>& arr, int k) {
    unordered_map<int, int> map;
    int output = 0;
    for(int i = 0; i < arr.size(); i++) {
        int complement1 = arr[i] - k;
        int complement2 = arr[i] + k;
        output += map[complement1];
        output += map[complement2];
        map[arr[i]]++;
    }

    return output;
}

int main () {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int k;
    cin >> k;
    int output = countKDifference(arr, k);
    cout << output << endl;
    return 0; 
}