#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int tribonacci(int n) {
            if (n <= 1) {
                return n;
            }
            if (n == 2) {
                return 1;
            }
            vector <int> dp(n + 4);
            for (int i = 0; i <= n; i++) {
                dp[i + 3] = dp[i] + dp[i + 1] + dp[i + 2];
            }
            return dp[n];
        }
    };