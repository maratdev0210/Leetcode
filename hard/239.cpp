#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
      vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset <int> st;
        for (int i = 0; i < k; i++) {
          st.insert(nums[i]);
        }

        vector <int> ans;
        for (int i = 0; i <= nums.size() - k; i++) {
          if (i == 0) {
            auto it = st.rbegin();
            ans.push_back(*it);
          } else {
            if (st.find(nums[i - 1]) != st.end()) {
              st.erase(st.find(nums[i - 1]));
            }
          
            st.insert(nums[i + k - 1]);
            auto it = st.rbegin();
            ans.push_back(*it);
          }
        }   

        return ans;
      }
  };