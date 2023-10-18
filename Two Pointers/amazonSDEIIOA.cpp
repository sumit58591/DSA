// You are given an array of size “N”.For each and every subarray->find the count of distinct elements in it->put all those counts in new array->sort it->find the middle element
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll findMedian_brute(vector<ll>& arr, ll n) {
    ll totalSubarraysCount = (n * (n + 1)) / 2;
    vector<ll> distinct;
    for(ll i = 0; i < n; i++) {
        unordered_set<ll> set;
        for(ll j = i; j < n; j++) {
            set.insert(arr[j]);
            distinct.push_back(set.size());
        }
    }

    sort(distinct.begin(), distinct.end());
    ll index = (totalSubarraysCount - 1) / 2;
    return distinct[index];
}

ll countSubarrays(vector<ll>&arr, ll k) {
    ll n = arr.size();
	ll i = 0, j = 0, output = 0;
	unordered_map<ll, ll> map;
	while(j < n) {
		map[arr[j]]++;
		while(map.size() > k) {
			map[arr[i]]--;
			if(map[arr[i]] == 0) map.erase(arr[i]);
			i++;
		}

		output += j - i + 1;
		j++;
	}

	return output;
}

ll findMedian_optimal(vector<ll>& arr, ll n) {
    ll finalOutput = 1;
    ll totalSubarraysCount = (n * (n + 1)) / 2;
    ll index = (totalSubarraysCount - 1) / 2;
    ll prev = 0, curr = 0;
    // for(ll i = 1; i <= n; i++) {
    //     prev = curr;
    //     curr = countSubarrays(arr, i);
    //     cout << "prev: " << prev << ", " << "curr: " << curr << endl;
    //     if(prev < index and curr >= index) return i;
    // }

    int low = 1, high = n, k = 0;
    while(low <= high and k == 0) {
        int mid  = (low + high) / 2;
        
        if(mid == 1) {
            // cout << "1 mil gya!!!" << endl;
            // return 1;
            finalOutput = 1;
            k = 1;
        }

        if(countSubarrays(arr, mid) < index and countSubarrays(arr, mid + 1) >= index) {
            k = 1;
            finalOutput = mid + 1;
            // return mid + 1;
        } 

        if(countSubarrays(arr, mid) >= index and countSubarrays(arr, mid - 1) >= index) high = mid - 1;
        else if(countSubarrays(arr, mid) < index and countSubarrays(arr, mid + 1) < index) low = mid + 1;
    }

    return finalOutput;
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    ll output = findMedian_optimal(arr, n);
    cout << output << endl;
    return 0;
}