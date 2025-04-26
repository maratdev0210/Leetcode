#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    string convertToTitle(int columnNumber) {
        vector <char> ch;
        for (char i = 'A'; i <= 'Z'; i++) {
            ch.push_back(i);
        }
        vector <int> digits;
        int num = columnNumber;
        while (num != 0) {
            digits.push_back(num % 27);
            num /= 26;
        }
        reverse(digits.begin(), digits.end());
        string ans = "";
        for (auto x: digits) {
            ans += ch[x];
        }
        return ans;
    }
};