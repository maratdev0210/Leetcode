#include <bits/stdc++.h>

using namespace std;

unordered_map<char, string> m = {{'2', "abc"},{'3', "def"},{'4', "ghi"},{'5', "jkl"},{'6', "mno"},{'7', "pqrs"},{'8', "tuv"},{'9', "wxyz"}};
        vector <string> answer;

void solve(string digits, int n, string s) {
    if (digits.size() == n) {
        answer.push_back(s);
        return;
    }
    for (int i = 0; i < m[digits[n]].size(); ++i) {
        string t = s;
        t += m[digits[n]][i];
        solve(digits, n + 1, t);
    }
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }
        solve(digits, 0, "");
        vector <string> res = answer;
        answer.clear();
        return res;
    }
};