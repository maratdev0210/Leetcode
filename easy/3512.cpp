class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int cnt = 0;
        for (auto x: nums) {
            cnt += x;
        }
        return cnt % k;
    }
};