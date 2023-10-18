#include<bits/stdc++.h>
using namespace std;

int consecutiveSum(vector<int>& arr, int k) {
    int i = 0, j = 0;
    int currSum = 0, maxSum = INT_MIN;
    while(j < arr.size()) {
        currSum += arr[j];
        if(j - i + 1 < k) j++;
        else {
            if(j - i + 1 == k) {
                maxSum = max(currSum, maxSum);
                currSum -= arr[i];
                i++; j++;
            }
        }
    }

    return maxSum;
}

int main () {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int k;
    cin >> k;
    int output = consecutiveSum(arr, k);
    cout << output << endl;
    return 0;
}