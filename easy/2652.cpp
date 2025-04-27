#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int sumOfMultiples(int n) {
            int res = 0;
            for (int i = 1; i <= n; i++) {
                if (n % 3 == 0 || n % 5 == 0 || n % 7 == 0) {
                    res += i;
                }
            }
            return res;
        }
    };