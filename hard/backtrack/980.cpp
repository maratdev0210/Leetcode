#include <bits/stdc++.h>

using namespace std;

vector <pair<int, int>> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool ok2 = false;
int ans = 0;
map <pair<int, int>, int> obstacles;

void solve(vector <vector<int>> &a, vector <pair<int, int>> path, int n, int m, int si, int sj, int ei, int ej, int curi, int curj, int ob, int cnt) {
    path.push_back({curi, curj});
    map <pair<int, int>, int> seen;
    bool ok = true;
    for (int i = 0; i < path.size(); ++i) {
        if (seen[path[i]] == 0) {
            seen[path[i]] = 1;
        } else {
            ok = false;
            break;
        }
    }
    if (!ok) {
        return;
    }
    if (path.size() == n * m - ob) {
        if (ok && path[n * m - ob - 1].first == ei && path[n * m - ob - 1].second == ej) {
            // cout << "Found the path: " << endl;
            // for (int i = 0; i < path.size(); ++i) {
            //     cout << path[i].first << " " << path[i].second << endl;
            // }
            ans += 1;
        } 
        return;
    }
    for (int i = 0; i < 4; ++i) {
        if (curi + d[i].first >= 0 && curi + d[i].first < n && curj + d[i].second >= 0 && curj + d[i].second < m && obstacles[{curi + d[i].first, curj + d[i].second}] == 0) {
            solve(a, path, n, m, si, sj, ei, ej, curi + d[i].first, curj + d[i].second, ob, cnt + 1);
        }
    }
}

class Solution {
    public:
    int uniquePathsIII(vector<vector<int>>& a) {
        int si = 0, sj = 0, ei = 0, ej = 0;
        int ob = 0;
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < a[i].size(); ++j) {
                if (a[i][j] == 1) {
                    si = i;
                    sj = j;
                }
                if (a[i][j] == 2) {
                    ei = i;
                    ej = j;
                }
                if (a[i][j] == -1) {
                    ob++;
                    obstacles[{i, j}] = 1;
                }
            }
        }
        int cnt = 0;
        int n = a.size();
        int m = a[0].size();
        vector <pair<int, int>> path;
        solve(a, path, n, m, si, sj, ei, ej, si, sj, ob, cnt);
        int temp = ans;
        ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                obstacles[{i, j}] = 0;
            }
        }
        return temp;
    }
};