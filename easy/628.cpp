#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int maximumProduct(vector<int>& nums) {
           sort(nums.begin(), nums.end());
           int n = nums.size();
           long long ans1 = nums[n - 3] * nums[n - 2] * nums[n - 1];
           vector <long long> neg;
           for (int i = 0; i < n; i++) {
            if (nums[i] <= 0)
           }
        }
};