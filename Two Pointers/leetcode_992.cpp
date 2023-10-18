#include<bits/stdc++.h>
using namespace std;

int subarraysWithKDistinct_helper(vector<int>& arr, int k) {
    int i = 0, j = 0, n = arr.size();
    int output = 0;
    unordered_map<int, int> map;
    while(j < n) {
        map[arr[j]]++;
        while(map.size() > k) {
            map[arr[i]]--;
            if(map[arr[i]] == 0) map.erase(arr[i]);
            i++;
        }

        output = output += j - i + 1;
        j++;
    }  

    return output;
}

int subarraysWithKDistinct(vector<int>& arr, int k) {
    return subarraysWithKDistinct_helper(arr, k) - subarraysWithKDistinct_helper(arr, k - 1);       
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int k;
    cin >> k;
    int output = subarraysWithKDistinct(arr, k);
    cout << output << endl;
    return 0;
}