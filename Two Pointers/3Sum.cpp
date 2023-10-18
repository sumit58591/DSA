#include <bits/stdc++.h>
using namespace std;

// USING TWO POINTERS, TIME COMPLEXITY: O(n* n)
vector<vector<int>> threeSum_optimal(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<vector<int>> output;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 and arr[i - 1] == arr[i])
            continue;
        int startIndex = i + 1, endIndex = n - 1;
        while (startIndex < endIndex)
        {
            int tripletSum = arr[i] + arr[startIndex] + arr[endIndex];
            if (tripletSum == 0)
            {
                vector<int> triplets = {arr[i], arr[startIndex], arr[endIndex]};
                output.push_back(triplets);
                startIndex++;
                endIndex--;
                while (startIndex < endIndex and arr[startIndex] == arr[startIndex - 1])
                    startIndex++;
                while (startIndex < endIndex and arr[endIndex] == arr[endIndex + 1])
                    endIndex--;
            }
            else if (tripletSum > 0)
            {
                endIndex--;
            }
            else
            {
                startIndex++;
            }
        }
    }

    return output;
}

// USING HASHMAPS, TIME COMPLEXITY: O(n * n logn)
vector<vector<int>> threeSum(vector<int> &arr)
{
    vector<vector<int>> output;
    set<vector<int>> st;
    for (int i = 0; i < arr.size(); i++)
    {
        unordered_set<int> set;
        for (int j = i + 1; j < arr.size(); j++)
        {
            int pairComplement = -(arr[i] + arr[j]);
            if (set.find(pairComplement) != set.end())
            {
                vector<int> triplets;
                triplets.push_back(arr[j]);
                triplets.push_back(pairComplement);
                triplets.push_back(arr[i]);
                sort(triplets.begin(), triplets.end());
                if (st.find(triplets) == st.end())
                    output.push_back(triplets);
                st.insert(triplets);
                continue;
            }

            set.insert(arr[j]);
        }
    }

    return output;
}

// OPTIMAL APPROACH USING HASHMAP, TIME COMPLEXITY: O(n * n)
vector<vector<int>> threeSum_hashing(vector<int> &arr)
{
    unordered_set<int> set;
    vector<vector<int>> output;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        if (set.find(arr[i]) != set.end())
            continue;
        unordered_set<int> tempSet;
        int startIndex = i + 1, endIndex = n - 1;
        while (startIndex < endIndex)
        {
            int sum = arr[i] + arr[startIndex] + arr[endIndex];
            if (sum == 0)
            {
                vector<int> triplets = {arr[i], arr[startIndex], arr[endIndex]};
                output.push_back(triplets);
                tempSet.insert(arr[startIndex]);
                tempSet.insert(arr[endIndex]);
                startIndex++;
                endIndex--;
                while (startIndex < endIndex and tempSet.find(arr[startIndex]) != tempSet.end())
                    startIndex++;
                while (startIndex < endIndex and tempSet.find(arr[endIndex]) != tempSet.end())
                    endIndex--;
            }
            else if (sum > 0)
                endIndex--;
            else
                startIndex++;
        }

        set.insert(arr[i]);
    }

    return output;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> output = threeSum_optimal(arr);
    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output[i].size(); j++)
        {
            cout << output[i][j] << " ";
        }

        cout << endl;
    }
    return 0;
}