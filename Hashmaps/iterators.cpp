#include<iostream>
#include<unordered_map>
using namespace std;

int main () {
    unordered_map<int, int> map;
    map[1] = 100;
    map[2] = 200;
    map[3] = 300;
    map[4] = 400;
    map[5] = 500;
    unordered_map<int, int>::iterator it;
    for(it = map.begin(); it != map.end(); it++) cout << "Key: " << it->first << " and Value: " << it->second << endl;
    return 0;
}