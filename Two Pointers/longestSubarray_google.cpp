#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &arr, int n, int k) {
    int maxLength = INT_MIN, currLength = 0, currDiff = 0, j = 0;
    for(int i = 0; i < n; i++) {
        for(; j < n; j++) {
            currDiff = arr[j] - arr[i];
            if(currDiff > k) {
                break;
            }
        }

        currLength = j - i;
        maxLength = max(currLength, maxLength);
        if(j >= n) break;
    }

    return maxLength;
}

int main () {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int k;
    cin >> k;
    int output = longestSubarray(arr, n, k);
    cout << output << endl;
    return 0;
}