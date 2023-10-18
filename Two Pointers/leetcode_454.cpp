#include<bits/stdc++.h>
using namespace std;

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    int i = 0, j = 0, k = 0, l = 0, n = nums1.size();
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    sort(nums3.begin(), nums3.end());
    sort(nums4.begin(), nums4.end());
    int output = 0;
    unordered_map<int, int> map;
    for(int i = 0; i < n; i++) map[nums4[i]]++;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                int sum = nums1[i] + nums2[j] + nums3[k];
                int complement = -sum;
                output += map[complement];
            }
        }
    }

    return output;
}

int fourSumCount_optimal(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    unordered_map<int, int> map;
    int n = nums1.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int currPairSum = nums1[i] + nums2[j];
            map[currPairSum]++;
        }
    }

    int output = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int currPairSum = nums3[i] + nums4[j];
            output += map[-currPairSum];
        }
    }

    return output;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums1(n), nums2(n), nums3(n), nums4(n);
    for(int i = 0; i < n; i++) cin >> nums1[i];
    for(int i = 0; i < n; i++) cin >> nums2[i];
    for(int i = 0; i < n; i++) cin >> nums3[i];
    for(int i = 0; i < n; i++) cin >> nums4[i];
    int output = fourSumCount_optimal(nums1, nums2, nums3, nums4);
    cout << output << endl;
    return 0;
}