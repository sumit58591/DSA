/*
    You are given two sorted arrays ; 
    both arrays were of size N ;  
    you have to find a pair of numbers such that sum of those numbers <=x and as close as possible to x 
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> findClosest_bruteForce(int arr1[], int arr2[], int n, int x) {
    vector<int> output;
    int i = 0, j = n - 1;
    int l = 0, r = 0;
    int diff = INT_MAX;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int sum = arr1[i] + arr2[j];
            if(sum <= x) {
                if(x - sum < diff) {
                    diff = x - sum;
                    l = i; r = j;
                }
            }
        }
    }

    output.push_back(arr1[l]);
    output.push_back(arr2[r]);
    return output;
}

vector<int> findClosest_optimised(int arr1[], int arr2[], int n, int x) {
    vector<int> output;
    int i = 0, j = n - 1;
    int l = 0, r = 0;
    int diff = INT_MAX;
    while(i < n and j >= 0) {
        int sum = arr1[i] + arr2[j];
        if(sum <= x) {
            if(x - sum < diff) {
                diff = x - sum;
                l = i; r = j;
            }
            i++;
        } else {
            j--;
        }
    }

    output.push_back(arr1[l]);
    output.push_back(arr2[r]);
    return output;
}

int main () {
    int n;
    cin >> n;
    int* arr1 = new int[n];
    int* arr2 = new int[n];
    for(int i = 0; i < n; i++) cin >> arr1[i];
    for(int i = 0; i < n; i++) cin >> arr2[i];
    int target;
    cin >> target;
    vector<int> output = findClosest_bruteForce(arr1, arr2, n, target);
    for(int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    delete [] arr1;
    delete [] arr2;
    return 0;
}