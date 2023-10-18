#include<bits/stdc++.h>
using namespace std;

long long countSubarrayHelper(vector<int>& arr, int n, long long k) {
    long long currSum = 0;
    long long countOutput = 0;
    int i = 0, j = 0;
    while(j < n) {
        currSum += arr[j];
        while(currSum > k) {
            currSum -= arr[i];
            i++;
        }
        countOutput += j - i + 1;
        j++;
    }

    return countOutput;
}

long long countSubarray(int n, vector<int>& arr, long long l, long long r) {
    long long smallOutput1 = countSubarrayHelper(arr, n, r);
    long long smallOutput2 = countSubarrayHelper(arr, n, l - 1);
    return smallOutput1 - smallOutput2;
}

int main () {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    long long l, r;
    cin >> l >> r;
    long long output = countSubarray(n, arr, l, r);
    cout << output << endl;
    return 0;
}