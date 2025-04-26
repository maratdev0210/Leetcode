#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int countPrimeSetBits(int left, int right) {
            int ans = 0;
            for (int i = left; i <= right; i++) {
                int one = 0;
                int x = i;
                while (x != 0) {
                    one += ((x % 2) == 1);
                    x /= 2;
                }
                if (one == 2 || one == 3 || one == 5 || one == 7 || one == 11 || one == 13 || one == 17 || one == 19 | one == 23 || one == 29) {
                    ans++;
                }
            }
            return ans;
        }
    };