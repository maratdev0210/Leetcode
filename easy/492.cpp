#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        vector<int> constructRectangle(int area) {
            vector <pair<int, int>> d;
            for (int i = 1; i * i <= area; ++i) {
                if (area % i == 0) {
                    d.push_back({i, area / i});
                }
            }
            int mi = area;
            pair <int, int> ans;
            for (int i = 0; i < d.size(); i++) {
                if (abs(d[i].first - d[i].second) < mi) {
                    mi = abs(d[i].first - d[i].second);
                    ans = d[i];
                }
            }
            pair <int, int> res = {max(ans.first, ans.second), min(ans.first, ans.second)};
            vector <int> res2 = {res.first, res.second};
            return res2;
        }
    };