#include<iostream>
using namespace std;

int firstUniqChar(string str) {
    int mp[256] = {0};
    for(int i = 0; i < str.length(); i++) {
        mp[str[i]]++;
    }

    for(int i = 0; i < str.length(); i++) {
        if(mp[str[i]] == 1) return i;
    }

    return -1;
}

int main () {
    string input;
    cin >> input;

    int output = firstUniqChar(input);
    cout << output << endl;
    return 0;
}