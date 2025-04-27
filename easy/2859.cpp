class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans = 0;
        for (auto x: nums) {
            int cnt = 0;
            for (int i = 0; i <= 16; ++i) {
                if (x & (1 << i)) {
                    cnt++;
                }
            }
            if (cnt == k) {
                ans += x;
            }
        }
        return ans;
    }
};