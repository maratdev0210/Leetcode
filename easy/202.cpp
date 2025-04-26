#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    bool isHappy(int n) {
         if (n == 2) {
            return false;
         }   
         int sum = n;
         for (int i = 1; i <= 1000; i++) {
            int x = sum, cur = 0;
            while (x != 0) {
                cur += ((x % 10) * (x % 10));
                x /= 10;
            }
            if (cur == 1) {
                return true;
            }
            sum = cur;
         }
         return false;
    }
};