#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }   
        vector <int> digits;
        int v = x;
        while (v != 0) {
            digits.push_back(v % 10);
            v /= 10;
        }
        for (int i = 0; i < digits.size(); i++) {
            if (digits[i] == digits[digits.size() - i - 1]) {
                continue;
            }
            return false;
        }
        return true;
    }
};