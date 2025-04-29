#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        vector <int> d;
        int cur = 0;
        for (auto x: nums) {
            int cnt = 0;
            for (int i = 1; i <= x; ++i) {
                if (x % i == 0) {
                    cnt += 1;
                }
            }
            if (cnt == 2) {
                d.push_back(cur);
            }
            cur++;
        }
        return d[d.size() - 1] - d[0];
    }
};