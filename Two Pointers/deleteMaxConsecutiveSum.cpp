#include<bits/stdc++.h>
using namespace std;

int removeMaxConsecutive(vector<int>& arr, int k) {
    int i = 0, j = 0;
    int sum = 0;
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }

    int currSum = 0, maxSum = INT_MIN;
    while(j < arr.size()) {
        currSum += arr[j];
        if(j - i + 1 < k) {
            j++;
        } else if(j - i + 1 == k) {
            maxSum = max(maxSum, currSum);
            currSum -= arr[i];
            i++; j++;
        } else break;
    }

    return sum - maxSum;
}

int main () {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int k;
    cin >> k;
    cout << removeMaxConsecutive(arr, k) << endl;
    return 0;
}