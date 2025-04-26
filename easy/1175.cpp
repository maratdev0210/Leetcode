#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

class Solution {
    public:
        int numPrimeArrangements(int n) {
            int cnt = 0;
            for (int i = 2; i <= n; i++) {
                int sm = 0;
                for (int j = 1; j <= i; j++) {
                    if (i % j == 0) {
                        sm++;
                    }
                }
                if (sm == 2) {
                    cnt++;
                }
            }
            int comp = n - cnt;
            long long res1 = 1;
            for (int i = 1; i <= cnt; i++) {
                res1 = (res1 * i) % mod;
            }
            long long res2 = 1;
            for (int i = 1; i <= comp; i++) {
                res2 = (res2 * i) % mod;
            }
            long long res = (res1 * res2) % mod;
            return res;
        }
};