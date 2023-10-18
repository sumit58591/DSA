#include<bits/stdc++.h>
using namespace std;

int countSubarrays(vector<int>& arr, int n, int k) {
    int i = 0, j = 0;
    int output = 0;
    int currSum = 0;
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

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int k;
    cin >> k;
    int output = countSubarrays(arr, n, k);
    cout << output << endl;
    return 0;
}