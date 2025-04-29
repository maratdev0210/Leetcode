#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            bool ok = true;
            int n = nums.size();
            for (int i = 0;i < nums.size(); i++) {
                if (nums[i] != n - i) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                for (int i = 0;i  < nums.size(); ++i) {
                    nums[i] = i + 1;
                }
                return;
            }
            next_permutation(nums.begin(), nums.end());
            return;
        }
    };