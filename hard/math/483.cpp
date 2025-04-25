#include <bits/stdc++.h>

using namespace std;

long long calc(long long k, long long n) {
    long long res = 1, t = 1;
    for (int i = 1; i <= n; i++) {
        if (t > 1e18 / k) {
            return 1e18;
        }
        t *= k;
        res += t;
        if (res > 1e18) {
            return 1e18;

        }
    }
    return res;
}

long long pow(long long n) {
    long long x = 1;
    for (int i = 0; i < n; i++) {
        x *= 10;
    }
    return x;
}

string convert(long long n) {
    string ans = "";
    long long x = n;
    while (x != 0) {
        ans += to_string(x % 10);
        x /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

class Solution {
    public:
        string smallestGoodBase(string s) {
            long long n = 0;
            for (int i = 0; i < s.size(); i++) {
                n += pow(s.size() - i - 1) * (s[i] - '0');
            }
            if (n == 1e18) {
                return convert(n - 1);
            }
            long long ans = n - 1;
            for (long long i = 2; i <= 63; i++) {
                long long left = 2, right = n;
                while (left <= right) {
                    long long mid = (left + right) / 2;
                    long long sum = calc(mid, i);
                    if (sum == n) {
                        ans = min(ans, mid);
                        break;
                    } else if (sum > n) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
            }
            
            return convert(ans);
        }
};