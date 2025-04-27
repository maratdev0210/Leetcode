#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int smallestNumber(int n) {
            for (int i = 1; i <= 10; i++) {
                int x = 1 << i;
                if (x - 1 >= n) {
                    return x - 1;
                }
            }
        }
    };