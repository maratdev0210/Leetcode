#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int firstMissingPositive(vector<int>& nums) {
            set <int> st;
            for (auto x: nums) {
                st.insert(x);
            }
            for (int i = 1; i <= *st.rbegin(); i++) {
                if (!st.count(i)) {
                    return i;
                }
            }
            if (*st.rbegin() < 0) {
                return 1;
            }
            return *st.rbegin() + 1;
        }
};