#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        vector<int> selfDividingNumbers(int left, int right) {
            vector <int> ans;
            for (int i = left; i <= right; i++) {
                bool ok = true;
                int x = i;
                while (x != 0) {
                    if (x == 0) {
                        ok = false;
                        break;
                    }
                    if (i % (x % 10) != 0) {
                        ok = false;
                        break;
                    }
                    x /= 10;
                }
                if (ok) {
                    ans.push_back(i);
                }
            }
            return ans;
        }
    };