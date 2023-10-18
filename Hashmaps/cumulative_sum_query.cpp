#include<iostream>
#include<vector>
using namespace std;

int cumulativeSum(vector<int>& temp, int l, int r) {
    return temp[r + 1] - temp[l];
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n); 
    for(int i = 0; i < n; i++) cin >> arr[i];
    int test_cases;
    cin >> test_cases;
    while(test_cases--) {
        int l, r;
        cin >> l >> r;
        vector<int> temp;
        temp.push_back(0);
        int currSum = 0;
        for(int i = 0; i < arr.size(); i++) {
            currSum += arr[i];
            temp.push_back(currSum);
        }
        cout << cumulativeSum(temp, l, r) << endl;
    }

    return 0;
}
