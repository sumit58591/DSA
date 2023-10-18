#include<iostream>
#include<unordered_map>
using namespace std;

bool checkDuplicatesWithinK(int* arr, int n, int k) {
    unordered_map<int, int> map;
    for(int i = 0; i < n; i++) {
        if(map.find(arr[i]) != map.end()) {
            int getIndex = map[arr[i]];
            int difference = i - getIndex;
            if(difference <= k) return true;
        }
        
        map[arr[i]] = i;
    }
    
    return false;
}

int main () {
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int k;
    cin >> k;
    bool output = checkDuplicatesWithinK(arr, n, k);
    if(output) cout << "True" << endl;
    else cout << "False" << endl;
    delete [] arr;
    return 0;
}