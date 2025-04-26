#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int xorOperation(int n, int start) {
            vector <int> d(n);
            for (int i = 0; i < n; i++) {
                d[i] = start + 2 * i;
            }
            long long res = d[0];
            for (int i = 1; i < n; i++) {
                res = (res ^ d[i]);
            }
            return res;
        }
    };