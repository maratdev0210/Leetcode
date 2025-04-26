#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        string toHex(int num) {
            vector <char> ch;
            for (char i = '0'; i <= '9'; i++) {
                ch.push_back(i);
            }
            for (char i = 'a'; i <= 'f'; i++) {
                ch.push_back(i);
            }
            long long cur;
            if (num < 0) {
                cur = 2 << 32;
                cur -= num;
            } else {
                cur = num;
            }
            string ans = "";
            while (cur != 0) {
                ans += ch[cur % 16];
                cur /= 16;

            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
    };