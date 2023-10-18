#include<bits/stdc++.h>
using namespace std;

int numberOfSubarrays(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> temp(n);
    for(int i = 0; i < n; i++) {
        if(arr[i] % 2 == 0) temp[i] = 0;
        else temp[i] = 1;
    }

    unordered_map<int, int> map;
    int output = 0, currSum = 0;
    for(int i = 0; i < n; i++) {
        currSum += temp[i];
        if(currSum == k) output++;
        if(map.find(currSum - k) != map.end()) {
            output += map[currSum - k];
        }

        map[currSum]++;
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
    int output = numberOfSubarrays(arr, k);
    cout << output << endl;
    return 0;
}