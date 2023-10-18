#include<iostream>
using namespace std;

void merge(int* arr, int si, int mid, int ei) {
    int *temp = new int[si + ei + 1];
    int i = si, j = mid + 1, k = si;
    while(i <= mid and j <= ei) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else temp[k++] = arr[j++];
    }

    while(i <= mid) temp[k++] = arr[i++];
    while(j <= ei) temp[k++] = arr[j++];

    for(int i = si; i <= ei; i++) arr[i] = temp[i];
    delete [] temp;
    return;
}

void mergeSort(int* arr, int si, int ei) {
    if(si >= ei) return;
    int mid = (si + ei) / 2;
    mergeSort(arr, si, mid);
    mergeSort(arr, mid + 1, ei);
    merge(arr, si, mid, ei);
    return;
}

void mergeSort(int* arr, int n) {
    mergeSort(arr, 0, n - 1);
}

int main () {
    int n;
    cin >> n;
    int* input = new int[n];
    for(int i = 0; i < n; i++) cin >> input[i];
    mergeSort(input, n);
    for(int i = 0; i < n; i++) cout << input[i] << " ";
    delete [] input;
    return 0;
}