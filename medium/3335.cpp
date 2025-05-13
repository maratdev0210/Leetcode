#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector <long long> cnt(26);
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            cnt[s[i] - 'a']++;
        }
        
        for (int i = 0; i < t; ++i) {
            vector <long long> prev = cnt;
            long long new_a = cnt[25] % mod;
            long long new_b = (cnt[0] % mod + cnt[25] % mod) % mod;
            cnt[25] = 0;
            for (int j = 1; j < 25; ++j) {
                cnt[j + 1] = prev[j];
                cnt[j + 1] %= mod;
            }
            cnt[0] = new_a % mod;
            cnt[1] = new_b % mod;
        }
        long long res = 0;
        for (int i = 0; i <= 25; ++i) {
            res = (res % mod + cnt[i] % mod) % mod;
        }
        return res % mod;
    }
};