#include<bits/stdc++.h>
using namespace std;

int numberOfSubarrays_helper(vector<int>& arr, int k) {
    int i = 0, j = 0;
    int currCount = 0, n = arr.size();
    int output = 0;
    while(j < arr.size()) {
        if(arr[j] % 2 != 0) currCount++;
        while(currCount > k) {
            if(arr[i] % 2 != 0) currCount--;
            i++;
        }

        output += j - i + 1;
        j++;
    }

    return output;
}

int numberOfSubarrays(vector<int>& arr, int k) {
    return numberOfSubarrays_helper(arr, k) - numberOfSubarrays_helper(arr, k - 1);
}

int main () {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int k;
    cin >> k;
    int output = numberOfSubarrays(arr, k);
    cout << output << endl;
    return 0;
}