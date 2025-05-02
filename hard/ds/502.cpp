#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
           int n = profits.size();
           vector <pair<int, int>> a(n);
           for (int i = 0; i < n; ++i) {
              a[i] = {capital[i], profits[i]};
           }
           sort(a.begin(), a.end());
           priority_queue<int> pq;
           int j = 0;
           while (j < n && k > 0) {
              if (a[j].first <= w) {
                pq.push(a[j].second);
                j++;
              } else {
                if (pq.empty()) {
                    return w;
                }
                w += pq.top();
                pq.pop();
                k--;
              }
           }

           while (k > 0 && !pq.empty()) {
            w += pq.top();
            pq.pop();
            k--;
           }
           return w;
    }
};