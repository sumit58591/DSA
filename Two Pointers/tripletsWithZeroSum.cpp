#include<bits/stdc++.h>
using namespace std;

// USING HASHMAPS
pair<int, int> findPairs(vector<int>& arr, int n, int x, int startIndex) {
    unordered_map<int, int> map;
    pair<int, int> output;
    for(int i = startIndex; i < n; i++) {
        int complement = x - arr[i];
        if(map.find(complement) != map.end()) {
            output.first = arr[i];
            output.second = complement;
            return output;
        }

        map[arr[i]]++;
    }

    output.first = INT_MAX;
    output.second = INT_MAX;
    return output;
}
    
// USING TWO POINTERS
bool findTriplets(vector<int>& arr, int n) {
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++) {
        int startIndex = i + 1, endIndex = n - 1;
        while(startIndex < endIndex) {
            int sum = arr[i] + arr[startIndex] + arr[endIndex];
            if(sum == 0) return true;
            else if(sum > 0) endIndex--;
            else startIndex++;
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    bool output = findTriplets(arr, n);
    if(!output) cout << "No triplet found!!!" << endl;
    return 0;
}
