#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    bool isPowerOfTwo(int n) {
       if (n == 1) {
        return true;
       }       
       if (n & (n - 1)) {
        return false;
       }
       return true;
    }
};