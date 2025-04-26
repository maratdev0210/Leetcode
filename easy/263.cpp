#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        bool isUgly(int n) {
            if (n < 0) {
                return false;
            }
            if (n <= 1) {
                return true;
            }
            int x = n;
            while (x % 2 == 0) {
                x /= 2;
            }
            while (x % 3 == 0) {
                x /= 3;
            }
            while (x % 5 == 0) {
                x /= 5;
            }
            if (x != 1) {
                return false;
            }
            return true;
        }
    };