#include <bits/stdc++.h>

using namespace std;

bool check(vector<vector<int>> &a, int n) {
    vector <pair<int, int>> p;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1) {
                p.push_back({i, j});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].first == p[j].first || p[i].second == p[j].second || (abs(p[i].first - p[j].first) == abs(p[i].second - p[j].second))) {
                return false;
            }
        }
    }
    return true;
}

vector <vector<string>> sol;


void solve(vector<vector<int>> &a, int n, int row, vector<int> &seen) {
    if (row == n) {
        if (check(a, n)) {
            vector<string> ans(n);
            for (int i = 0; i < n; i++) {
                string s = "";
                for (int j = 0; j < n; j++) {
                    if (a[i][j] == 1) {
                        s += 'Q';
                    } else {
                        s += '.';
                    }
                }
                ans[i] = s;
            }
            sol.push_back(ans);
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (seen[i]) {
            continue;
        }
        a[row][i] = 1;
        seen[i] = 1;
        solve(a, n, row + 1, seen);
        a[row][i] = 0;
        seen[i] = 0;
    }
}

class Solution {
  
    public:
        vector<vector<string>> solveNQueens(int n) {
            vector<vector<int>> a(n, vector<int>(n, 0));
            vector<int> seen(n, 0);
            solve(a, n, 0, seen);
            vector<vector<string>> result = sol;
            sol.clear();
            return result;
        }
    };
