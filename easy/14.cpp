#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        if (s.size() == 1) {
            return s[0];
        }
        int n = 100000;
        for (int i = 0;i  < s.size(); i++) {
            n = min(n, (int)s[i].size());
        }
        string ans = "";
        for (int i = n - 1; i >= 0; --i) {
            vector <string> cur;
            for (int j = 0; j < s.size(); j++) {
                string d = "";
                for (int k = 0; k <= i; ++k) {
                    d += s[j][k];
                }
                cur.push_back(d);
            }
            bool ok = true;
            for (int j = 0; j < s.size() - 1; j++) {
                if (cur[j] != cur[j + 1]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans = cur[0];
                break;
            }
        }
        return ans;
    }
};