#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int maxLen(vector<int>& arr, int n) {
    int maxLen = 0, currSum = 0, currLength = 0;
    unordered_map<int, int> map;
    for(int i = 0; i < n; i++) {
        currSum += arr[i];
        if(currSum == 0) maxLen = max(maxLen, i + 1);
        if(map.find(currSum) != map.end()) maxLen = max(maxLen, i - map[currSum]); 
        else map[currSum] = i;
    }
    return maxLen;
}

int main () {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << maxLen(arr, n) << endl;
    return 0;
}