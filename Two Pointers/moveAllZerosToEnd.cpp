#include<bits/stdc++.h>
using namespace std;

void pushZerosToEnd_brute(int* arr, int n) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) {
            int k = i + 1;
            while(k < n) {
                if(arr[k] != 0) {
                    int temp = arr[k];
                    arr[k] = 0;
                    arr[i] = temp;
                    break;
                }

                k++;
            }
        }
    }
}

void pushZerosToEnd(int* arr, int n) {
    int i = 0, j = 0;
    while(j < n) {
        if(arr[j] != 0) {
            arr[i] = arr[j];
            i++; j++;
        } else {
            j++;
        }
    }

    while(i < n) {
        arr[i] = 0; 
        i++;
    }
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    pushZerosToEnd_brute(arr, n);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}