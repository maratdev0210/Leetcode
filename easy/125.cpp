#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    bool isPalindrome(string s) {
        string n = "";
        for (int i = 0; i < s.size(); i++) {
            bool ok = false;
            s[i] = tolower(s[i]);
            for (char j = 'a'; j <= 'z'; j++) {
                if (s[i] == j) {
                    ok = true;
                    break;
                } 
            }
            if (!ok) {
                for (char j = '0'; j <= '9'; j++) {
                    if (s[i] == j) {
                        ok = true;
                        break;
                    }
                }
            }
            if (ok) {
                n += s[i];
            }
        } 
        if (n.size() == 0) {
            return true;
        }
        for (int i = 0; i < n.size(); i++) {
            if (n[i] != n[n.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }
};