#include<iostream>
#include<cstring>
using namespace std;

void removeConsecutiveDuplicates(char input[]) {
    if(input[0] == '\0') return;
    if(input[0] == input[1]) {
        int length = strlen(input);
        int i = 1;
        for(; i <= length; i++) {
            input[i - 1] = input[i];
        }
        removeConsecutiveDuplicates(input);
    }
    removeConsecutiveDuplicates(input + 1);
}

int main () {
    char str[100000];
    cin >> str;
    removeConsecutiveDuplicates(str);
    cout << str << endl;
    return 0;
}