#include<bits/stdc++.h>
using namespace std;

int countSubarray(string str, int k) {
    int i = 0, j = 0, n = str.length();
    int output = 0;
    unordered_map<char, int> map;
    while(j < str.length()) {
        map[str[j]]++;
        j++;
        while(map.size() >= k and i <= j) {
            map[str[i]]--;
            if(map[str[i]] == 0) map.erase(str[i]);
            output += n - j + 1;
            i++;
        }
    }

    return output;
}

int main () {
    string str;
    cin >> str;
    int k;
    cin >> k;
    int output = countSubarray(str, k);
    cout << output << endl;
    return 0;
}