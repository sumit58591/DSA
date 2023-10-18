#include<iostream>
#include<map>
#include<vector>
using namespace std;

vector<int> countFreq(int* arr, int n) { 
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }

    map<int, int>::iterator it;
    vector<int> output;
    for(it = mp.begin(); it != mp.end(); it++) {
        output.push_back(it->second);
    }

    return output;
}

int main () {
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> output = countFreq(arr, n);
    for(int i = 0; i < output.size(); i++) cout << output[i] << " ";
    delete [] arr;
    return 0;
}