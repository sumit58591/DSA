#include<bits/stdc++.h>
using namespace std;

string minWindow_brute(string s, string t) {
    if(t.length() > s.length()) return "";
    unordered_map<char, int> map;
    int maxFreqT = 0;
    for(int i = 0; i < t.length(); i++) {
        map[t[i]]++;
    }

    string output = s;
    int mapSize = map.size();
    for(int i = 0; i < s.length(); i++) {
        int currLength = 0;
        unordered_map<char, int> temp;
        for(int j = i; j < s.length(); j++) {
            temp[s[j]]++;
            if(temp[s[j]] == map[s[j]]) {
                currLength++;
                if(currLength == mapSize) {
                    if(j - i + 1 < output.length()) {
                        output = s.substr(i, j - i + 1);
                    }

                    break;
                }
            }
        }
    }

    return output;
}

string minWindow(string s, string t) {
    if(s.length() < t.length()) return "";
    bool flag = false;
    unordered_map<char, int> map;
    for(int i = 0; i < t.length(); i++) map[t[i]]++;

    int startIndex = 0, endIndex = s.length() - 1;
    int minSubstrLength = s.length() + 1, n = s.length();
    int i = 0, j = 0;
    int mapSize = map.size(), currCount = 0;
    while(j < n) {
        map[s[j]]--;
        if(map[s[j]] == 0) currCount++;
        while(currCount == mapSize) {
            if(j - i + 1 < minSubstrLength) {
                minSubstrLength = j - i + 1;
                startIndex = i;
                endIndex = j;
                flag = true;
            }

            map[s[i]]++;
            if(map[s[i]] >= 0) currCount--;
            i++;
        }

        j++;
    }

    if(!flag) return "";
    string output = s.substr(startIndex, endIndex - startIndex + 1);
    return output;
}

int main() {
    string s, t;
    cin >> s >> t;
    string output = minWindow(s, t);
    cout << output << endl;
    return 0;
}