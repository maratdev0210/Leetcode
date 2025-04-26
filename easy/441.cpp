#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int arrangeCoins(int n) {
            for (long long i = 1; i <= n; i++) {
                long long sum = i * (i + 1) / 2;
                if (sum > n) {
                    return i - 1;
                } else if (sum == n) {
                    return i;
                }
            }
        }
    };