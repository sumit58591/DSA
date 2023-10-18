#include<bits/stdc++.h>
using namespace std;

vector<int> longestConsecutive(vector<int> &nums) {
    unordered_set<int> arrSet;
    for(int i = 0; i < nums.size(); i++) {
        arrSet.insert(nums[i]);
    }

    int maxLength = 0;
    int firstNumber = 0, secondNumber = 0;
    int i = 0;
    while(i < nums.size()) {
        int val = nums[i] - 1, currLength = 0;
        if(arrSet.find(val) != arrSet.end()) {
            i++;
            continue;
        } else {
            val = nums[i];
            while(arrSet.find(val) != arrSet.end()) {
                currLength++;
                val++;
            }

            if(currLength > maxLength) {
                firstNumber = nums[i];
                secondNumber = val - 1;
                maxLength = currLength;
            }
            i++;
        }
    }

    vector<int> output;
    output.push_back(firstNumber);
    output.push_back(secondNumber);
    return output;
}

int main () {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> output = longestConsecutive(arr);
    for(int i = 0; i < output.size(); i++) cout << output[i] << " ";
    return 0;
}