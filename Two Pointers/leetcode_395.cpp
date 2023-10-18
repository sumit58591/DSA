#include<bits/stdc++.h>
using namespace std;

int longestSubstring_brute(string s, int k) {
    int output = 0;
    for(int i = 0; i < s.length(); i++) {
        for(int j = i; j < s.length(); j++) {
            vector<int> arr(26, 0);
            string str = s.substr(i, j - i + 1);
            bool flag = true;
            for(int i = 0; i < str.length(); i++) {
                arr[str[i] - 'a']++;
            }

            for(int i = 0; i < str.length(); i++) {
                if(arr[str[i] - 'a'] < k) flag = false;
            }

            if(flag) {
                int currLength = str.length();
                output = max(output, currLength);
            }
        }
    }
    
    return output;
}

int longestSubstring(string s, int k) {
    int n = s.length();
    if(k > n or n == 0) return 0;
    if(k <= 1) return n;

    unordered_map<char, int> map;
    for(int i = 0; i < s.length(); i++) map[s[i]]++;

    int si = 0, ei = 0;
    while(ei < n and map[s[ei]] >= k) ei++;
    if(ei >= n - 1) return ei;
    
    int longestSubstring1 = longestSubstring(s.substr(si, ei), k);
    while(ei < n and map[s[ei]] < k) ei++;
    int longestSubstring2 = (ei < n) ? longestSubstring(s.substr(ei), k) : 0;
    return max(longestSubstring1, longestSubstring2);
}

int main() {
    string str;
    cin >> str;
    int k;
    cin >> k;
    int output = longestSubstring_brute(str, k);
    cout << output << endl;
    return 0;
}

