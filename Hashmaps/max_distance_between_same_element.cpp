#include<iostream>
#include<unordered_map>
using namespace std;

int maxDistance(int* arr, int n) {
    unordered_map<int, int> map;
    int maxDistance = 0;
    for(int i = 0; i < n; i++) {
        if(map.find(arr[i]) != map.end()) {
            if(i - map[arr[i]] > maxDistance)maxDistance = i - map[arr[i]];
        } else map[arr[i]] = i;
    }

    return maxDistance;
}

int main () {
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int output = maxDistance(arr, n);
    cout << output << endl;
    delete [] arr;
    return 0;
}