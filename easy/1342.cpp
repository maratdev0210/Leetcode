#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int numberOfSteps(int num) {
            int ans = 0;
            int x = num;
            while (x != 0) {
                if (x % 2 == 0) {
                    x /= 2;
                    ans++;
                } else {
                    x -= 1;
                    ans++;
                }
            }
            return ans;
        }
    };