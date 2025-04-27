#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int sumOfTheDigitsOfHarshadNumber(int x) {
            int n = x;
            int sum = 0;
            while (n != 0) {
                sum += (n % 10);
                n /= 10;
            }
            if (n % sum == 0) {
                return sum;
            }
            return -1;
        }
    };