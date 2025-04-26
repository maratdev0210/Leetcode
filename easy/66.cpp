#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            int n = digits.size();
            if (digits[n - 1] < 9) {
                digits[n - 1] += 1;
            } else {
                for (int i = n - 1; i >= 0; --i) {
                    if (digits[i] != 9) {
                        break;
                    }
                    digits[i] = 0;
                }
                
                vector <int> new_digits = {digits[0] + 1};
                for (int i = 0; i < digits.size(); i++) {
                    new_digits.push_back(digits[i]);
                }
                return new_digits;
            }
            return digits;
        }
    };