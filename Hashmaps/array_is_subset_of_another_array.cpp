#include<iostream>
#include<unordered_map>
using namespace std;

string isSubset(int* arr1, int* arr2, int n, int m) {
    unordered_map<int, int> map;
    for(int i = 0; i < n; i++) {
        map[arr1[i]]++;
    }

    for(int i = 0; i < m; i++) {
        if(map[arr2[i]] <= 0) return "No";
        map[arr2[i]]--;
    }

    return "Yes";
}

int main () {
    int n, m;
    cin >> n >> m;
    int* arr1 = new int[n];
    int* arr2 = new int[m];
    for(int i = 0; i < n; i++) cin >> arr1[i];
    for(int i = 0; i < m; i++) cin >> arr2[i];
    string output = isSubset(arr1, arr2, n, m);
    cout << output << endl;
    delete [] arr1;
    delete [] arr2;
    return 0;
}