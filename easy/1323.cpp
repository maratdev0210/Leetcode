#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int maximum69Number (int num) {
            vector <int> d;
            int x = num;
            while (x != 0) {
                d.push_back(x % 10);
                x /= 10;
            }
            reverse(d.begin(), d.end());

            for (int i = 0; i < d.size(); i++) {
              
                if (d[i] == 6) {
                    d[i] = 9;
                    break;
                }
            }
            int ans = 0;
            if (d.size() == 4) {
                ans = 1000 * d[0] + 100 * d[1] + 10 * d[2] + d[3];
            } else if (d.size() == 3) {
                ans = 100 * d[0] + 10 * d[1] + d[2];
            } else if (d.size() == 2) {
                ans = 10 * d[0] + d[1];
            } else {
                ans = d[0];
            }
            return ans;
        }
    };