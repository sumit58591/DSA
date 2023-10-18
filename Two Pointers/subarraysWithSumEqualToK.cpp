#include<bits/stdc++.h>
using namespace std;

int countSubarray(vector<int>& arr, int n, int k) {
    int i = 0, j = 0, currSum = 0, output = 0;
    while(j < n) {
        currSum += arr[j];
        while(currSum > k) {
            currSum -= arr[i];
            i++;
        }

        if(currSum == k) {  
            output++;
        }
        j++;
    }

    return output;
}

int main () {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int k;
    cin >> k;
    int output = countSubarray(arr, n, k);
    cout << output << endl;
    return 0;
}