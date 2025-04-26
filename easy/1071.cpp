#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        string gcdOfStrings(string str1, string str2) {
            int n = str1.size();
            int m = str2.size();
            int k = min(n, m);
            for (int i = k - 1; k >= 0; --k) {
                string cur = "";
                for (int j = 0; j <= i; ++j) {
                    cur += str1[j];
                }
                bool ok = true;
                
            }
        }
    };