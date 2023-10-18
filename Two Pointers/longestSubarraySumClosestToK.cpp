#include<bits/stdc++.h>
using namespace std;

int largestSubarray_bruteForce(vector<int> &arr, int n, int k) {
    int maxLength = INT_MIN;
    for(int i = 0; i < arr.size(); i++) {
        int currSum = 0;
        int currSubarrayLen = 0;
        for(int j = i; j < arr.size(); j++) {
            currSum += arr[j];
            if(currSum > k) break;
            else {
                currSubarrayLen++;
            }
        }

        maxLength = max(currSubarrayLen, maxLength);
    }

    return maxLength;
}

int longestSubarray_optimised(vector<int> &arr, int n, int k) {
    int maxLength = INT_MIN, currLength = 0, currSum = 0, j = 0;
    for(int i = 0; i < n; i++) {
        for(; j < n; j++) {
            currSum += arr[j];
            if(currSum > k) {
                break;
            }
        }

        currLength = j - i;
        maxLength = max(currLength, maxLength);
        j = j + 1;
        if(j >= n) break;
        currSum -= arr[i];
    }

    return maxLength;
}

/* 
    First we will declare a maxLength variable, intitially it's value is INT_MIN then a currLength variable which will store the current length of the subarray and currSum which will store the currSum of the subarray. We will take a 'j' pointer which will point to array intially at 0th index. Now there is a for loop and inside that loop the main task is being done. We will be adding the current element to the currSum variable and checking the condition if the currSum is valid or not. If at some index currSum exceeded the value of K then we will break the loop and will come out of there. j - i will be my current length as after adding arr[j] it comes out of the loop that means till previous index sum was valid. Then after calculating current length we will be storing the maximum of maxLength and currLength and storing it to the maxLength. Now we will increment j and if j exceeded n then the array is completed. Hence no need to do further calculation hence breaking the loop again. After that if everything was ok then for i we have calculated currLength hence for next iteration of i we are subtracting current value from currSum. At last returning the maxLength.
*/

int longestSubarray_optimised2(vector<int>& arr, int n, int k) {
    int i = 0, j = 0;
    int maxLength = 0, currLength = 0;
    int currSum = 0;
    while(j < arr.size()) {
        currSum += arr[j];
        while(currSum > k) {
            currSum -= arr[i];
            i++;
            currLength--;
        }

        currLength++;
        maxLength = max(maxLength, currLength);
        j++;
    }

    return maxLength;
}

int main () {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int k;
    cin >> k;
    // int output = longestSubarray_optimised2(arr, n, k);
    int output = longestSubarray_optimised2(arr, n, k);
    cout << output << endl;
    return 0;
}