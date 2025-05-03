#include <bits/stdc++.h>

using namespace std;



class Solution {
    public:
        int maxSatisfaction(vector<int>& a) {
            int n = a.size();
            sort(a.begin(), a.end());
            long long mx = 0, cur = 0;
    for (int i = 0; i < n; ++i) {
        cur += (i + 1) * a[i];
    }
    mx = max(mx, cur);
    for (int i = 0; i < n; ++i) {
        long long cur = 0;
        for (int j = i + 1; j < n; ++j) {
            cur += (j - i) * a[j];
        }
        mx = max(mx, cur);
    }
    return mx;
        }
    };