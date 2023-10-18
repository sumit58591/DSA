#include<bits/stdc++.h>
using namespace std;

int countSubarrays(vector<int>& arr, int k) {
    int i = 0, j = 0, currPairs = 0, n = arr.size();
    int output = 0;
    unordered_map<int, int> map;
    while(j < n) {
        map[arr[j]]++;
        currPairs += map[arr[j]] - 1;
        while(currPairs >= k and i < j) {
            map[arr[i]]--;
            currPairs -= map[arr[i]];
            output += n - j;
            i++;
        }
        j++;
    }
    return output;
}

int main () {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int k;
    cin >> k;
    cout << countSubarrays(arr, k);
    return 0;
}