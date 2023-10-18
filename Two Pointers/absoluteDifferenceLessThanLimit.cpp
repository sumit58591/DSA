#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& arr, int k) {
    int maxLength = INT_MIN, currLength = 0, currDiff = 0, j = 0;
    for(int i = 0; i < arr.size(); i++) {
        int currMax = INT_MIN;
        for(; j < arr.size(); j++) {
            currMax = max(currMax, arr[j]);
            currDiff = abs(currMax - arr[i]);
            if(currDiff > k) {
                break;
            }
        }

        currLength = j - i;
        maxLength = max(currLength, maxLength);
        if(j >= arr.size()) break;
    }

    return maxLength;
}

int longestSubarray_optimised(vector<int> &arr, int k) {
    int i = 0, j = 0;
    int maxLength = 0, currLength = 0;
    int currDiff = 0;
    while(j < arr.size()) {
        currDiff = (arr[j] - arr[i]);
        while(currDiff > k) {
            i++;
            currDiff = (arr[j] - arr[i]);
            currLength--;
        }

        currLength++;
        maxLength = max(maxLength, currLength);
        j++;
    }

    return maxLength;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int limit;
    cin >> limit;
    int output = longestSubarray_optimised(arr, limit);
    cout << output << endl;
    return 0;
}