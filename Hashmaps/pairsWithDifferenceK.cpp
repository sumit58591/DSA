#include<iostream>
#include<unordered_map>
using namespace std;

int getPairsWithDifferenceK(int* arr, int n, int k) {
    unordered_map<int, int> map;
    int countPairs = 0;
    for(int i = 0; i < n; i++) {
        int first_compelement = arr[i] - k;
        int second_complement = arr[i] + k;
        if(k != 0) countPairs += map[first_compelement] + map[second_complement];
        else countPairs += map[arr[i]];
        map[arr[i]]++;
    }

    return countPairs;
}

int main () {
    int test_cases;
    cin >> test_cases;
    while(test_cases--) {
        int n;
        cin >> n;
        int* arr = new int[n];
        for(int i = 0; i < n; i++) cin >> arr[i];
        int difference;
        cin >> difference;
        int pairsCount = getPairsWithDifferenceK(arr, n, difference);
        cout << "Pairs count: " << pairsCount << endl;
        delete [] arr;
    }

    return 0;
}