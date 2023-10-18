#include<bits/stdc++.h>
using namespace std;

int longestEqualSubarray(vector<int>& arr, int k) {
    int i = 0, j = 0;
    unordered_map<int, int> map;
    int output = 0, currLength = 0, currMaxFreq = 0;
    int n = arr.size();
    while(j < n) {
        map[arr[j]]++;
        currMaxFreq = max(map[arr[j]], currMaxFreq);
        int currEleCount = j - i + 1,  rem = currEleCount - currMaxFreq;
        while(rem > k) {
            map[arr[i]]--;
            i++;
            currMaxFreq = max(currMaxFreq, map[arr[j]]);
            currEleCount = j - i + 1;
            rem = currEleCount - currMaxFreq;
        }

        output = max(output, currMaxFreq);
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
    int output = longestEqualSubarray(arr, k);
    cout << output << endl;
    return 0;
}