#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 
        multiset <int> st;
        vector <int> mx(n);
        st.insert(prices[0]);
        mx[0] = prices[0];
        for (int i = 1; i < n; i++) {
            auto it = st.end();
            --it;
            if (*it <= prices[i]) {
                st.erase(it);
                st.insert(prices[i]);
                mx[i] = prices[i];
            } else {
                mx[i] = mx[i - 1];
                
            }
        }   
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, mx[n - 1] - prices[i]);
        }
        return ans;
    }
};