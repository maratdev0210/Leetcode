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

void solve(vector<vector<int>> &a, int n, int row, int &ans, vector<int> &seen) {
    if (row == n) {
        if (check(a, n)) {
            ans = ans + 1;
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (seen[i]) {
            continue;
        }
        a[row][i] = 1;
        seen[i] = 1;
        solve(a, n, row + 1, ans, seen);
        a[row][i] = 0;
        seen[i] = 0;
    }
}

class Solution {
    public:
        int totalNQueens(int n) {
            vector<vector<int>> a(n, vector<int>(n, 0));
    vector<int> seen(n, 0);
    int ans = 0;
    solve(a, n, 0, ans, seen);
    return ans;
        }
    };