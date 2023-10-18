#include<bits/stdc++.h>
using namespace std;

int findPairs(vector<int>& arr, int x) {
    int i = 0, j = arr.size() - 1;
    int output = 0;
    while(i < j) {
        if(arr[i] + arr[j] < x) {
            output += j - i;
            i++;
        } else {
            j--;
        }
    }

    return output;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int x;
    cin >> x;
    int output = findPairs(arr, x);
    cout << output << endl;
    return 0;
}