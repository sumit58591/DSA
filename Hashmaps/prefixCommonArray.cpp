#include<bits/stdc++.h>
using namespace std;

vector<int>findThePrefixCommonArray(vector<int>& arr1, vector<int>& arr2) {
    vector<int> output;
    unordered_set<int> set;
    int i = 0,count = 0;
    while(i < arr1.size()) {
        if(arr1[i] == arr2[i]) {
            count++;
            output.push_back(count);
        } else if(set.count(arr1[i]) and set.count(arr2[i])) {
            count += 2;
            output.push_back(count);
        } else if(set.count(arr1[i]) or set.count(arr2[i])) {
            count++;
            output.push_back(count);
        } else {
            output.push_back(count);
        }

        set.insert(arr1[i]);
        set.insert(arr2[i]);
        i++;
    }
    return output;
}

int main () {
    int n;
    cin >> n;
    vector<int> arr1(n), arr2(n);
    for(int i = 0; i < n; i++) cin >> arr1[i];
    for(int i = 0; i < n; i++) cin >> arr2[i];
    vector<int> output = findThePrefixCommonArray(arr1, arr2);
    for(int i = 0; i < output.size(); i++) cout << output[i] << " ";
    return 0;
}