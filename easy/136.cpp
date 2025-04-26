#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        int ans = nums[0];
        for (int i = 1; i < n; i++) {
            int cur = ans ^ nums[i];
            ans = cur;
        }
        return ans;
    }
};