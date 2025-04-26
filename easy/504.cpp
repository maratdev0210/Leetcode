#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        string convertToBase7(int num) {
            bool ok = false;
            if (num < 0) {
                ok = true;
                num = abs(num);
            }
            if (num == 0) {
                return "0";
            }
            string ans = "";
            int x = num;
            while (x != 0) {
                ans += to_string(x % 7);
                x /= 7;;
            }
            if (ok) {
                ans += "-";
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
    };