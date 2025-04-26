#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    bool isPowerOfFour(int n) {
        if (n <= 0) {
            return false;
        }
        int x = n;
        while (x % 4 == 0) {
            x /= 4;
        }
        return x == 1;
    }
};