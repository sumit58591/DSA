#include<iostream>
using namespace std;

int partition(int* arr, int si, int ei) {
    int pivot = arr[si];
    int i = si, j = ei + 1;
    do{
        do{
            i++;
        } while(arr[i] <= pivot and i <= ei);
        do{
            j--;
        } while(arr[j] > pivot);
        if(i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while(i <= j);
    int temp = arr[j];
    arr[j] = pivot;
    arr[si] = temp;
    return j;
}

void quickSort(int* arr, int si, int ei) {
    if(si >= ei) return;
    int p = partition(arr, si, ei);
    quickSort(arr, si, p - 1);
    quickSort(arr, p + 1, ei);
    return; 
}

void quickSort(int* arr, int n) {
    quickSort(arr, 0, n - 1);
}

int main () {
    int n;
    cin >> n;
    int* input = new int[n];
    for(int i = 0; i < n; i++) cin >> input[i];
    quickSort(input, n);
    for(int i = 0; i < n; i++) cout << input[i] << " ";
    delete [] input;
    return 0;
}