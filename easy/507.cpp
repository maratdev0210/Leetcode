#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        bool checkPerfectNumber(int num) {
            vector <int> d;
            for (long long i = 1; i * i <= num; i++) {
                if (num % i == 0) {
                    d.push_back(i);
                    if (num / i == i) {
                        continue;
                    }
                    d.push_back(num / i);
                }
            }
            long long sum = 0;
            for (auto x: d) {
                sum += x;
            }
            if (sum == num) {
                return true;
            }
            return false;
        }

        
    };