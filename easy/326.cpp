#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        bool isPowerOfThree(int n) {
            if (n <= 0) {
                return false;
            }
            int x = n;
            while (x % 3 == 0) {
                x /= 3;
            }
            return x == 1;
        }
    };