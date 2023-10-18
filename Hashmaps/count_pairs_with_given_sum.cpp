#include<iostream>
#include<unordered_map>
using namespace std;

int getPairsCount(int* arr, int n, int sum) {
    unordered_map<int, int> map;
    int countPairs = 0;
    for(int i = 0; i < n; i++) {
        int complement = sum - arr[i];
        countPairs += map[complement];
        map[arr[i]]++;
    }

    return countPairs;
}

int main () {
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int sum;
    cin >> sum;
    int countPairs  = getPairsCount(arr, n, sum);
    cout << countPairs << endl;
    delete [] arr;
    return 0;
}