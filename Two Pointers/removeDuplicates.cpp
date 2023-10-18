#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& arr) {
    int j = 0, n = arr.size();
    if(n <= 1) return n;
    for(int i = 1; i < n; i++) {
        if(arr[j] != arr[i]) {
            j++;
            arr[j] = arr[i];
        }
    }

    return j + 1;
}

int main () {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int output = removeDuplicates(arr);
    cout << output << endl;
    return 0;
}