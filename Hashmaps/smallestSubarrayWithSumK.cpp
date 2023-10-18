#include<iostream>
#include<unordered_map>
#include<vector>
#include<climits>
using namespace std;

int minSubarrayLen(int target, vector<int>& arr) {
    int minLength = INT_MAX;
    for(int i = 0; i < arr.size(); i++) {
        int currLength = 0, currSum = 0;
        for(int j = i; j < arr.size(); j++) {
            currLength++;
            currSum += arr[j];
            if(currSum == target and currLength < minLength) minLength = currLength;
        }
    }

    return minLength;
}

int minSubarrayLen_optimised(int target, vector<int>& arr) {
    int minLength = INT_MAX, currSum = 0;
    unordered_map<int, int> map;
    for(int i = 0; i < arr.size(); i++) {
        currSum += arr[i];
        if(currSum == target) {
            if(i + 1 < minLength) minLength = i + 1;
        }

        if(map.find(currSum - target) != map.end()) {
            int currVal = map[currSum - target];
            if(i - currVal < minLength) minLength = i - currVal;
        }

        map[currSum] = i;
    }

    if(currSum < target) return 0;
    return minLength;
}

int main () {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int target;
    cin >> target;
    int output = minSubarrayLen_optimised(target, arr);
    cout << output << endl;
    return 0;
}
