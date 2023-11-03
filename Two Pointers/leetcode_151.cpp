#include<bits/stdc++.h>
using namespace std;

string reverseWords(string str) {
    reverse(str.begin(), str.end());
    string output;
    int n = str.length();
    for(int i = 0; i < n; i++) {
        if(str[i] == ' ') continue;
        else {
            int startIndex = i, endIndex = i;
            while(str[endIndex] != ' ' and str[endIndex] != '\0') endIndex++;
            string temp = str.substr(startIndex, endIndex - startIndex);
            reverse(temp.begin(), temp.end());
            output += temp;
            output += ' ';
            i = endIndex;
        }
    }

    output.pop_back();
    return output;    
}

int main() {
    string str;
    getline(cin, str);
    string output = reverseWords(str);
    cout << output << endl;
    return 0;
}