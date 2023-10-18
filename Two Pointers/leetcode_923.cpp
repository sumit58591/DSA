#include<bits/stdc++.h>
using namespace std;

// USING TWO POINTERS
int threeSumMulti(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    int n = arr.size(), mod = 1000000007;
    int output = 0;
    for(int i = 0; i < arr.size(); i++) {
        int startIndex = i + 1, endIndex = n - 1;
        int numPairs = 0;
        while(startIndex < endIndex) {
            int sum = arr[i] + arr[startIndex] + arr[endIndex];
            if(sum == target) {
                int startIndexElement = arr[startIndex];
                int endIndexElement = arr[endIndex];
                if (startIndexElement == endIndexElement)
                {
                    int totalCount = endIndex - startIndex + 1;
                    numPairs += ((totalCount * (totalCount - 1)) / 2) % mod;
                    break;
                }

                else
                {
                    int tempStartIndex = startIndex + 1;
                    int tempEndIndex = endIndex - 1;
                    while (tempStartIndex <= tempEndIndex && arr[tempStartIndex] == startIndexElement)
                        tempStartIndex++;
                    while (tempEndIndex >= tempStartIndex && arr[tempEndIndex] == endIndexElement)
                        tempEndIndex--;
                    int totalDuplicatesFromStart = tempStartIndex - startIndex;
                    int totalDuplicatesFromEnd = endIndex - tempEndIndex;
                    numPairs += (totalDuplicatesFromEnd * totalDuplicatesFromStart) % mod;
                    startIndex = tempStartIndex;
                    endIndex = tempEndIndex;
                }
            } else if(sum > target) {
                endIndex--;
            } else startIndex++;
        }

        output += numPairs % mod;
    }

    return output;
}

// USING HASHMAPS
int threeSumMulti_helper(vector<int>& arr, int si, int k) {
    int countPairs = 0, mod = 1000000007;
    unordered_map<int, int> map;
    for(int i = si; i < arr.size(); i++) {
        int complement = k - arr[i];
        countPairs = (countPairs + map[complement]) % mod;
        map[arr[i]]++;
    }

    return countPairs % mod;
}

int threeSumMulti_maps(vector<int>& arr, int k) {
    int mod = 1000000007;
    int output = 0;
    for(int i = 0; i < arr.size(); i++) {
        output = ((output + threeSumMulti_helper(arr, i + 1, k - arr[i])) % mod) % mod;
    }

    return output;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int target;
    cin >> target;
    int output = threeSumMulti(arr, target);
    cout << output << endl;
    return 0;
}