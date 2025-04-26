#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int lengthOfLastWord(string s) {
            int pos = -1;
            for (int i = s.size() - 1; i >= 0; --i) {
                if (s[i] != ' ') {
                    pos = i;
                    break;
                }
            }
            string ans = "";
            for (int i = pos; i >= 0; --i) {
                if (s[i] == ' ') {
                    break;
                }
                ans += s[i];
            }
            int len = ans.size();
            return len;
        }
    };