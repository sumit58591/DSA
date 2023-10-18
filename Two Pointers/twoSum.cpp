#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> twoSum(vector<int>& arr, int target) {
    vector<int> output;
    for(int i = 0; i < arr.size(); i++) {
        int complement = target - arr[i];
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[j] == complement) {
                output.push_back(i);
                output.push_back(j);
                return output;
            }
        }
    }
    return output;
}

int main () {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int target;
    cin >> target;
    vector<int> output = twoSum(arr, target);
    for(int i = 0; i < output.size(); i++) cout << output[i] << " ";
    return 0;
}