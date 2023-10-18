#include<iostream>
using namespace std;

int staircase(int n) {
    if(n == 0) return 1;
    if(n <= 2) return n;
    return staircase(n - 3) + staircase(n - 2) + staircase(n - 1);
}

int main () {
    int input;
    cin >> input;
    cout << staircase(input) << endl;
    return 0;
}