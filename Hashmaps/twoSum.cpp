#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& arr, int target) {
    unordered_map<int, int> map;
    vector<int> output;
    for(int i = 0; i < arr.size(); i++) {
        int complement = target - arr[i];
        if(map.find(complement) != map.end()) {
            output.push_back(map[complement]);
            output.push_back(i);
        }

        map[arr[i]] = i;
    }

    return output;
}

int main () {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        arr[i] = val;
    }
    
    int sum;
    cin >> sum;
    vector<int> output = twoSum(arr, sum);
    for(int i = 0; i < output.size(); i++) cout << output[i] << " ";
    return 0;
}