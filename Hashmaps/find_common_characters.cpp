#include<iostream>
#include<vector>
#include<string>
#include<climits>
using namespace std;

vector<string> commonChars(vector<string>& words) {
    vector<string> output;
    int** arr = new int*[words.size()];
    for(int i = 0; i < words.size(); i++) {
        string word = words[i];
        arr[i] = new int[256]; std::fill_n(arr[i], 256, 0);
        for(int j = 0; j < word.length(); j++) {
            arr[i][word[j]]++;
        }
    }

    for(int i = 0; i < 256; i++) {
        int min = INT_MAX;
        for(int j = 0; j < words.size(); j++) {
            if(arr[j][i] < min) min = arr[j][i];
        }

        if(min > 0) {
            string commonChar = "";
            commonChar += char(i);
            while(min--) output.push_back(commonChar);
        }
    }

    return output;
}

vector<string> commonCharsApprochSecond(vector<string>& words) {
    vector<int>alpha(26, 10000);
    for(string word : words) {
        vector<int> tempAlpha(26, 0);
        for(char c : word) {
            tempAlpha[c - 'a']++;
        }

        for(int i = 0; i < 26; i++) {
            alpha[i] = min(tempAlpha[i], alpha[i]);
        }
    }
    
    vector<string> output;
    for(int i = 0; i < 26; i++) {
        while(alpha[i]--) {
            string currVal(1, 'a' + i);
            output.push_back(currVal);
        }
    }

    return output;
}

int main () {
    int n;
    cin >> n;
    vector<string> words;
    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        words.push_back(temp);
    }

    vector<string> output = commonCharsApprochSecond(words);
    for(int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    return 0;
}