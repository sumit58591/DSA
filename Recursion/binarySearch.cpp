#include<iostream>
#include<algorithm>
using namespace std;

int binarySearch(int* arr, int si, int ei, int key) {
    if(si > ei) return -1;
    int mid = (si + ei) / 2;
    if(arr[mid] == key) return mid;
    else if(arr[mid] > key) return binarySearch(arr, si, mid - 1, key);
    else return binarySearch(arr, mid + 1, ei, key);
}

int binarySearch(int* arr, int n, int key) {
    return binarySearch(arr, 0, n - 1, key);
}

int binarySearch_iterative(int* arr, int n, int key) {
    int l = 0, h = n - 1, index = -1;
    while(l <= h) {
        int mid = (l + h) / 2;
        if(arr[mid] == key) return mid;
        else if(arr[mid] > key) {
            h = mid - 1;
        } else l = mid + 1;
    }

    return index;
}

int main () {
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    int key;
    cin >> key;
    int index = binarySearch(arr, n, key);
    if(index == -1) cout << "Key not found!" << endl;
    else cout << "Key present at: " << index << endl;
    delete [] arr;
    return 0;
}