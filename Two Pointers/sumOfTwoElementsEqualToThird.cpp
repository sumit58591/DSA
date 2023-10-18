#include<bits/stdc++.h>
using namespace std;

// bool isValidTriplets(int a, int b, int c) {
//     if(a + b == c) return true;
//     if(a + c == b) return true;
//     if(c + b == a) return true;
//     return false;
// }

vector<int> findTriplets(vector<int> &arr, int n) {
    //Write your code here.
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
    cout << endl;
    vector<int> output;
    for(int i = 0; i < n; i++) {
        int startIndex = i + 1, endIndex = n - 1;
        while(startIndex < endIndex) {
            int sum = arr[startIndex] + arr[endIndex];
            if(sum == arr[i]) {
                output = { arr[i], arr[startIndex], arr[endIndex] };
                return output;
            } else if(sum > arr[i]) {
                startIndex++;
            } else endIndex--;
        }
    }

    return output;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> output = findTriplets(arr, n);
    for(int i = 0; i < output.size(); i++) cout << output[i] << " ";
    return 0;
}