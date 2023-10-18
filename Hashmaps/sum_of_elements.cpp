#include<iostream>
#include<unordered_map>
using namespace std;

int sumOfElements(int* arr, int n) {
    unordered_map<int, int> map;
    for(int i = 0; i < n; i++) {
        map[arr[i]]++;
    }

    int sum = 0;
    for(auto it = map.begin(); it != map.end(); it++) {
        if(it->second >= it->first) sum += it->first;
    }
    
    return sum;
}

int main () {
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int output = sumOfElements(arr, n);
    cout << output << endl;
    delete [] arr;
    return 0;
}