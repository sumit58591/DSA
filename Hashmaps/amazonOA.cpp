#include<bits/stdc++.h>
using namespace std;

int checkSubset(string s, string t) {
    unordered_map<char, int> map1, map2;
    for(int i = 0; i < s.length(); i++) map1[s[i]]++;
    for(int i = 0; i < t.length(); i++) map2[t[i]]++;
    int minVal = INT_MAX;
    for(int i = 0; i < t.length(); i++) minVal = min(minVal, map1[t[i]] / map2[t[i]]);
    return minVal;
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    int output = checkSubset(str1, str2);
    cout << output << endl;
    return 0;
}