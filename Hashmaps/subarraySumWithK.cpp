#include<iostream>
#include<unordered_map>
using namespace std;

int findSubArraySum_naive(int* arr, int n, int k) {
    int countSubarray = 0;
    for(int i = 0; i < n; i++) {
        int currSum = 0;
        for(int j = i; j < n; j++) {
            currSum += arr[j];
            if(currSum == k) countSubarray++;
        }
    }

    return countSubarray;
}

// int findSubarraySum_optimised(int* arr, int n, int k) {
//     int countSubarray = 0;
//     unordered_map<int, int> map;
//     int currSum = 0;
//     for(int i = 0; i < n; i++) {
//         currSum += arr[i];

//         if(currSum == k) countSubarray++;
//         if(map.find(currSum - k) != map.end()) countSubarray += map[currSum - k];
//         map[currSum]++;
//     }

//     return countSubarray;
// }

int findSubarraySum_optimised(int* arr, int n, int k) {
    int countSubarray = 0;
    unordered_map<int, int> map;
    int currSum = 0;
    for(int i = 0; i < n; i++) {
        currSum += arr[i];

        if(currSum == k) countSubarray++;
        if(map.find(currSum - k) != map.end()) countSubarray += map[currSum - k];
        map[currSum]++;
    }

    return countSubarray;
}

int main () {
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int k;
    cin >> k;
    int output = findSubarraySum_optimised(arr, n, k);
    cout << output << endl;
    delete [] arr;
    return 0;
}