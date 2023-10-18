#include<bits/stdc++.h>
using namespace std;

bool isBalanced(unordered_map<char, int>& mp, int k) {
    unordered_map<char, int>::iterator it = mp.begin();
    for(; it != mp.end(); it++) {
        if(it->second > k) return false;
    }

    return true;
}

int balancedString(string s) {
    unordered_map<char, int> map;
    for(int i = 0; i < s.length(); i++) map[s[i]]++;
    int i = 0, j = 0, n = s.length();
    int k = n / 4, minLength = n;
    while(j < n) {
        map[s[j]]--;
        while(i <= j and isBalanced(map, k)) {
            minLength = min(minLength, j - i + 1);
            map[s[i]]++;
            i++;
        }

        j++;
    }

    return minLength;
}

int main() {
    string s = "QWER";
    cin >> s;

    int result = balancedString(s);

    cout << "Minimum replacements needed: " << result << endl;

    return 0;
}
