#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    int consecutiveNumbersSum(int n) {
        vector <long long> d;
    n *= 2;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            d.push_back(i);
            long long x = n / i;
            if (x != i) {
                d.push_back(x);
            }
        }
    }
    long long res = 0;
    for (auto x: d) {
        long long y = (n / x) - x + 1;
        if (y > 0 && y % 2 == 0) {
            res++;
        }
    }
    return res;
    }
};