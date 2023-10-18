#include<iostream>
#include<unordered_map>
#include "ourmap.h"
using namespace std;

int main () {
    ourmap<double> map;
    unordered_map<int, int>::iterator it;
    for(int i = 0; i < 10; i++) {
        string key = "abc";
        char c = '0' + i;
        key = key + c;
        int value = i + 1;
        map.insert(key, value);
        cout << "Load Factor: " << map.getLoadFactor() << endl;
    }

    cout << map.size() << endl;
    map.remove("abc2");
    map.remove("abc7");
    cout << "Test: " << map.remove("abalsfjl") << endl;
    map.insert("sumit", 0.97);
    cout << "Test value: " << map.getValue("sumit") << endl;
    for(int i = 0; i < 10; i++) {
        string key = "abc";
        char c = '0' + i;
        key = key + c;
        cout << key << " : " << map.getValue(key) << endl;
    }

    cout << map.size();
}


