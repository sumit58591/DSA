#include<bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& arr) {
    int i = 0, j = 0, n = arr.size();
    int output = INT_MAX, currSum = 0;
    int currLength = 0;
    while(j < n) {
        currSum += arr[j];
        while(currSum >= target) {
            currLength = j - i + 1;
            currSum -= arr[i];
            output = min(output, currLength);
            i++;
        }

        j++;
    }  

    if(output == INT_MAX) return 0;
    return output;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int target;
    cin >> target;
    int output = minSubArrayLen(target, arr);
    cout << output << endl;
    return 0;
}