#include<bits/stdc++.h>
using namespace std;

int longestKSubstr_bruteFroce(string s, int k) {
    int maxLength = -1;
    int uniqueCount = 0;
    for(int i = 0; i < s.size(); i++) {
        int currLength = 0;
        int currUniqueCount = 0;
        vector<int> temp(256, 0);
        for(int j = i; j < s.size(); j++) {
            currLength++;
            if(temp[s[j]] == 0) currUniqueCount++;
            if(currUniqueCount == k) {
                maxLength = max(maxLength, currLength);
            }
            temp[s[j]]++;
        }
    }

    return maxLength;
}

int longestKSubstr(string s, int k) {
    int maxLength = -1;
    int i = 0, j = 0;
    int currLength = 0;
    unordered_map<char, int> arr;
    while(j < s.length()) {
        arr[s[j]]++;
        while(i <= j and arr.size() > k) {
            arr[s[i]]--;
            if(arr[s[i]] == 0) {
                arr.erase(s[i]);
            }
            i++;
        }

        if(arr.size() == k) {
            currLength = j - i + 1;
            maxLength = max(maxLength, currLength);
        }

        j++;
    }

    if(maxLength == 0) return -1;
    return maxLength;
}

int main () {
    string str;
    cin >> str;
    int k;
    cin >> k;
    int output = longestKSubstr(str, k);
    cout << output << endl;
    return 0;
}