#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    int addDigits(int num) {
        int cur = num;
        for (int i = 1; i <= 100; i++) {
            int x = cur;
            int sum = 0;
            while (x != 0) {
                sum += (x % 10);
                x /= 10;
            }
            if (sum <= 9) {
                return sum;
            }
            cur = sum;
        }
    }
};