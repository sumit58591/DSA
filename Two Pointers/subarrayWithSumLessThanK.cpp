#include<bits/stdc++.h>
using namespace std;

long long countSubarraySumLessThanK(vector<int>& arr, int n, long long k) {
    int i = 0, j = 0;
    long long currSum = 0, output = 0; 
    while(j < n) {
        currSum += arr[j];
        while(currSum >= k) {
            currSum -= arr[i];
            i++;
        }

        output += j - i + 1;
        j++;
    }

    return output;
}

int main () {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    long long k;
    cin >> k;
    long long output = countSubarraySumLessThanK(arr, n, k);
    cout << output << endl;
    return 0;
}