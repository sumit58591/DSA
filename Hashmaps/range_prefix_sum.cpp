#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int queries;
    vector<int> arr(n + 1, 0);
    int test_cases;
    cin >> test_cases;
    while(test_cases--) {
        int l, r;
        cin >> l >> r;
        arr[l] += 1;
        arr[r + 1] += -1;
    }
    
    int currSum = 0;
    for(int i = 0; i < n + 1; i++) {
        currSum += arr[i];
        arr[i] = currSum;
    }

    for(int i = 0; i < n + 1; i++) cout << arr[i] << " ";
    return 0;
}
