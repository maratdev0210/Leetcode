#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int first = -1, second = -1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    first = i;
                    second = j;
                    break;
                }
            }
            if (first != -1) {
                break;
            }
        }
        vector <int> answer = {first, second};
        return answer;
    }
};