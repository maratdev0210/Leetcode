#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int subsetXORSum(vector<int>& nums) {
            int n = nums.size();
            int x = 1 << n;
            long long res = 0;
            for (int i = 1; i < n; i++) {
                int x = i;
                vector <int> d;
                while (x != 0) {
                    d.push_back(x % 2);
                    x /= 2;
                }
                if (d.size() < n) {
                    int k = n - d.size();
                    for (int j = 0; j < k; j++) {
                        d.push_back(0);
                    }
                }
                reverse(d.begin(), d.end());
                long long cur = -1;
                for (int j = 0; j < d.size(); j++) {
                    if (d[j] == 1) {
                        if (cur == -1) {
                            cur = d[j];
                        } else {
                            cur = (cur ^ d[j]);
                        }
                    }
                }
                res += cur;
            }
            return res;
        }
    };