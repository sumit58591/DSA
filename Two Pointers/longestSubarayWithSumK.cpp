#include<bits/stdc++.h>
using namespace std;

int lenOfLongSubarr(vector<int>& arr, int n, int k) {
    unordered_map<int, int> map;
    int maxLength = 0;
    int currSum = 0;
    for(int i = 0; i < n; i++) {
        currSum += arr[i];
        if(currSum == k) maxLength = max(maxLength, i + 1);
        if(map.find(currSum - k) != map.end()) {
            maxLength = max(maxLength, i - map[currSum - k]);
        }

        map[currSum] = i;
    }

    return maxLength;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int k;
    cin >> k;
    int output = lenOfLongSubarr(arr, n, k);
    cout << output << endl;
    return 0;
}