#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

class Solution {
    public:
    int nthMagicalNumber(int n, int a, int b) {
        if (a > b) {
            swap(a, b);
        }
        if (a == b) {
            long long ans = ((a % mod) * (n % mod)) % mod;
            return ans;
        }
        long long lcm = (a * b) / gcd(a, b);
        long long ta = lcm / a - 1;
        long long tb = lcm / b - 1;
        if (n % (ta + tb + 1) == 0) {
            long long k = n / (ta + tb + 1);
            long long ans = ((k % mod) * (lcm % mod)) % mod;
            return ans;
        }
        long long k = n / (ta + tb + 1);
        long long cur = ((k % mod) * (lcm % mod)) % mod;
        long long r = n % (ta + tb + 1);
        
        if (b == lcm) {
            cur = (cur + a * r) % mod;
        } else {
            vector <long long> nums;
            for (long long i = 1; i <= 100000; i++) {
                nums.push_back(a * i);
            }
            for (long long i = 1; i <= 100000; i++) {
                nums.push_back(b * i);
            }
            sort(nums.begin(), nums.end());
            cur = (cur + nums[r - 1] % mod) % mod;
        }   
        return cur;
    }
};