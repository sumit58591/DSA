#include<iostream>
#include<unordered_map>
using namespace std;

int pairSum(int* arr, int n, int sum) {
    unordered_map<int, int> map;
    int pairs = 0;
    for(int i = 0; i < n; i++) {
        int complement = sum - arr[i];
        pairs += map[complement];
        map[arr[i]]++;
    }

    return pairs;
}


int countTriplet(int *arr, int n, int sum) {
    int triplets = 0;
    for(int i = 0; i < n; i++) {
        triplets += pairSum(arr + i + 1, n - 1, sum - arr[i]);
    }

    return triplets;
}

int main () {
    int test_cases;
    cin >> test_cases;
    while(test_cases--) {
        int n;
        cin >> n;
        int* arr = new int[n];
        for(int i = 0; i < n; i++) cin >> arr[i];
        int sum;
        cin >> sum;
        int countPairs = pairSum(arr, n, sum);
        cout << countPairs << endl;
        delete [] arr;
    }

    return 0;
}