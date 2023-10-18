#include<iostream>
using namespace std;

bool checkAB_better(char input[]) {
    if(input[0] == '\0') return true;
    if(input[0] == 'a') return checkAB_better(input + 1);
    else {
        if(input[1] != '\0') {
            if(input[0] == 'b' and input[1] == 'b') {
                return checkAB_better(input + 2);
            }
            else return false;
        } else return false;
    }
}

bool checkAB(char input[]) {
	// Write your code here
	if(input[0] != 'a') return false;
	return checkAB_better(input);
}

int main () {
    char input[100];
    bool ans;
    cin >> input;
    ans = checkAB(input);
    if(ans) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}