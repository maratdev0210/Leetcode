#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    bool isValid(string s) {
        int s1 = 0, s2 = 0, s3 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s1 < 0 || s2 < 0 || s3 < 0) {
                return false;
            }
            if (s[i] == '(') {
                s1++;
            } else if (s[i] == ')') {
                s1--;
            }
            if (s[i] == '[') {
                s2++;
            } else if (s[i] == ']') {
                s2--;
            }
            if (s[i] == '{') {
                s3++;
            } else {
                s3--;
            }
        }
        if (s1 == 0 && s2 == 0 && s3 == 0) {
            return true;
        }
        return false;
    }
};