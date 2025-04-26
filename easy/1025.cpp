#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        bool divisorGame(int n) {
            if (n == 1) {
                return false;
            }
            if (n == 2) {
                return true;
            }
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                if (n % i == 0) {
                    cnt++;
                }
            }
            if (cnt == 2) {
                return false;
            }
            return true;
        }
    };