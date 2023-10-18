#include<bits/stdc++.h>
using namespace std;

int longestPalindrome(vector<string>& words) {
    unordered_map<string, int> map;
    for(int i = 0; i < words.size(); i++) {
        map[words[i]]++;
    }

    int output = 0;
    bool flag = true;
    for(int i = 0; i < words.size(); i++) {
        string temp1 = words[i], temp2 = words[i];
        reverse(temp2.begin(), temp2.end());
        if(temp1[0] != temp1[1]) {
            int val = min(map[temp1], map[temp2]);
            output += 4 * val;
        } else {
            if(map[temp1] % 2 == 0) {
                output += 2 * map[temp1];
            } else {
                if(flag) {
                    output += 2 * map[temp1];
                    flag = false;
                } else {
                    output += 2 * (map[temp1] - 1);
                }
            }
        }

        map.erase(temp1);
        map.erase(temp2);
    }

    return output;
}

int main () {
    int n;
    cin >> n;
    vector<string> words(n);
    for(int i = 0; i < n; i++) cin >> words[i];
    int output = longestPalindrome(words);
    cout << output << endl;
    return 0;
}