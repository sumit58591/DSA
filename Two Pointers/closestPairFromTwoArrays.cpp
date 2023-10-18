#include<iostream>
#include<vector>
#include<climits>
#include<math.h>
using namespace std;

vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
    int diff = INT_MAX;
    int firstIndex = 0, secondIndex = 0;
    int i = 0, j = m - 1;
    while(i < n and j >= 0) {
        int sum = arr[i] + brr[j];
        int value = abs(sum - x);
        if(value < diff) {
            diff = value;
            firstIndex = i;
            secondIndex = j;
        }

        if(sum > x) j--;
        else i++;
    }

    vector<int> output;
    output.push_back(arr[firstIndex]);
    output.push_back(brr[secondIndex]);
    return output;
}

int main () {
    int n, m;
    cin >> n >> m;
    int* arr = new int[n];
    int* brr = new int[m];
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < m; i++) cin >> brr[i];
    int target;
    cin >> target;
    vector<int> output = printClosest(arr, brr, n, m, target);
    for(int i = 0; i < output.size(); i++) cout << output[i] << " ";
    delete [] arr, brr;
    return 0;
}