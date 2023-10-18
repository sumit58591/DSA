#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll findMaximum(vector<int>& arr, int n, int k) {
    vector<ll> temp(2000005, 0);
    for(int i = 0; i < n; i++) {
        ll l = arr[i] - k, r = arr[i] + k;
        temp[l]++;
        temp[r + 1] += -1;
    }

    ll output = 0;
    ll currSum = 0;
    for(int i = 0; i < 200000; i++) {
        currSum += temp[i];
        output = max(currSum, output);
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
    ll output = findMaximum(arr, n, k);
    cout << output << endl;
    return 0;
}