#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& arr, int k) {
    int i = 0, j = 0, diff = INT_MAX, n = arr.size();
    int currMin = INT_MAX, currMax = INT_MIN, output = 0;
    while(j < arr.size()) {
        currMax = max(currMax, arr[j]);
        currMin = arr[i];
        int currDiff = currMax - currMin;
        while(currDiff > k) {
            currMin = arr[i];
            i++;
            currDiff = currMax - currMin;
        }

        output = max(output, j - i + 1);
        j++;
    }

    return output;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int k;
    cin >> k;
    cout << longestSubarray(arr, k) << endl;
    return 0;
}