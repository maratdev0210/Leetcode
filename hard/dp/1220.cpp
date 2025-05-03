#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

class Solution {
    public:
    int countVowelPermutation(int n) {
        vector <vector <long long>> dp(n + 1, vector <long long>(5, 0));
        for (int i = 0; i < 5; ++i) {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= n; ++i) {
            dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]) % mod;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
            dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % mod;
            dp[i][3] = dp[i - 1][2] % mod;
            dp[i][4] = (dp[i - 1][2] + dp[i - 1][3]) % mod;
        }
        long long sum = 0;
        for (int i = 0; i < 5; ++i) {
            sum = (sum % mod + dp[n][i] % mod) % mod;
        }
        return sum % mod;    
    }
};
