#include <bits/stdc++.h>

using namespace std;

string ans;

void solve(long long n, long long k, vector <long long> &a, vector <long long> &seen, long long &cur) {
    if (a.size() == n) {
        cur += 1;
        if (cur == k) {
            for (int i = 0; i < n; i++) {
                ans += to_string(a[i]);
            }
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (seen[i]) {
            continue;
        }
        a.push_back(i + 1);
        seen[i] = 1;
        solve(n, k, a, seen, cur);
        seen[i] = 0;
        a.pop_back();
    }
}

class Solution {
    public:
        string getPermutation(int n, int k) {
            vector <long long> seen(n, 0);
            vector <long long> a;
            long long cur = 0;
            solve(n, k, a, seen, cur);
            string result = ans;
            ans.clear();
            return result;
        }
    };

