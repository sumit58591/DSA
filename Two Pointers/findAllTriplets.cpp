#include<bits/stdc++.h>
using namespace std;

// USING TWO POINTERS
bool findTriplets(vector<int>& arr, int n) {
    bool output = false;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++) {
        int startIndex = i + 1, endIndex = n - 1;
        while(startIndex < endIndex) {
            int sum = arr[i] + arr[startIndex] + arr[endIndex];
            if(sum == 0) {
                output = true;
                cout << arr[i] << " " << arr[startIndex] << " " << arr[endIndex] << endl;
                startIndex++;
                endIndex--;
            }
            else if(sum > 0) endIndex--;
            else startIndex++;
        }
    }

    return output;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    bool output = findTriplets(arr, n);
    if(!output) cout << "No triplet found!!!" << endl;
    return 0;
}