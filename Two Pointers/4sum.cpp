#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<vector<int>> fourSum(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> output;
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        if(i > 0 and arr[i - 1] == arr[i]) continue;
        for(int j = i + 1; j < n; j++) {
            if(j > i + 1 and arr[j - 1] == arr[j]) continue;
            int startIndex = j + 1, endIndex = n - 1;
            while(startIndex < endIndex) {
                ll sum = ll(arr[i]) + ll(arr[j]) + ll(arr[startIndex]) + ll(arr[endIndex]);
                if(sum == target) {
                    vector<int> quadruplets = { arr[i], arr[j], arr[startIndex], arr[endIndex] };
                    output.push_back(quadruplets);
                    startIndex++; endIndex--;
                    while(startIndex < endIndex and arr[startIndex] == arr[startIndex - 1]) startIndex++;
                    while(startIndex < endIndex and arr[endIndex] == arr[endIndex + 1]) endIndex--;
                } else if(sum < target) {
                    startIndex++;
                } else endIndex--;
            }
        }
    }

    return output;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int target;
    cin >> target;
    vector<vector<int>> output = fourSum(arr, target);
    for(int i = 0; i < output.size(); i++) {
        for(int j = 0; j < output.at(i).size(); j++) {
            cout << output[i][j] << " ";
        }

        cout << endl;
    }
    return 0;
}