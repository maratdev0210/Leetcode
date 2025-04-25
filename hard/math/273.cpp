#include <bits/stdc++.h>

using namespace std;

map <long long, string> ranks = {{9, "Billion"}};
map <long long, string> digits = {{1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}};
map <long long, string> tens = {{2, "Twenty"}, {3, "Thirty"}, {4, "Forty"}, {5, "Fifty"}, {6, "Sixty"}, {7, "Seventy"}, {8, "Eighty"}, {9, "Ninety"}};
map <long long, string> teens = {{10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}};

string hundreds(vector <long long> &nums) {
    string ans = "";
    if (nums[0] != 0) {
        ans += digits[nums[0]];
        ans += " ";
        ans += "Hundred ";
    } 
    if (nums[1] != 0) {
        long long ten = 10 * nums[1] + nums[2];
        if (ten >= 10 && ten <= 19) {
            ans += teens[ten];
            return ans;
        }
        ans += tens[nums[1]];
        ans += " ";
        if (nums[2] == 0) {
            return ans;
        }
        ans += digits[nums[2]];
        return ans;
    }
    if (nums[2] != 0) {
        ans += digits[nums[2]];
        return ans;
    }
    return ans;
}

string normalizeSpaces(const string& input) {
    istringstream iss(input);
    string word, result;
    while (iss >> word) {  
        if (!result.empty()) result += " ";
        result += word;
    }
    return result;
}

class Solution {
    public:
        string numberToWords(int num) {
            vector <long long> a;
        while (num != 0) {
            a.push_back(num % 10);
            num /= 10;
        }
        if (a.size() == 0) {
            return "Zero";
        }
        string ans = "";
        int pos = a.size() - 1;
        if (a.size() == 10) {
            ans += digits[a[9]];
            ans += " ";
            ans += "Billion ";
            pos = 8;
        }
        bool ok1 = false, ok2 = true;
        for (int i = pos; i >= 0; i--) {
            if (i >= 6 && !ok1) {
                ok1 = true;
                vector <long long> nums = {};
                if (i - 6 == 2) {
                    nums = {a[i], a[i - 1], a[i - 2]};
                    if (a[i] + a[i - 1] + a[i - 2] == 0) {
                        ok2 = false;
                    }
                } else if (i - 6 == 1) {
                    nums = {0, a[i], a[i - 1]};
                    if (a[i] + a[i - 1] == 0) {
                        ok2 = false;
                    }
                } else if (i - 6 == 0) {
                    nums = {0, 0, a[i]};
                    if (a[i] == 0) {
                        ok2 = false;
                    }
                }
                if (ok2) {
                    ans += hundreds(nums);
                    ans += " Million ";
                }
                continue;
            }
        }
        if (ok1) {
            pos = 5;
        }
        vector <long long> nums = {};
        bool ok3 = false;
        if (pos >= 3) {
            ok2 = true;
            if (pos - 3 == 2) {
                nums = {a[pos], a[pos - 1], a[pos - 2]};
                if (a[pos] + a[pos - 1] + a[pos -2] == 0) {
                    ok2 = false;
                }
            } else if (pos - 3 == 1) {
                nums = {0, a[pos], a[pos - 1]};
                if (a[pos] + a[pos - 1] == 0) {
                    ok2 = false;
                }
            } else if (pos - 3 == 0) {
                nums = {0, 0, a[pos]};
                if (a[pos] == 0) {
                    ok2 = false;
                }
            }
            if (ok2) {
                ans += hundreds(nums);
                ans += " Thousand ";
                ok3 = true;
            }
        }
        pos = 2;
    
        if (pos == 2) {
            vector <long long> nums = {a[pos], a[pos - 1], a[0]};
            if (a[pos] + a[pos - 1] + a[0] != 0) {
                ans += hundreds(nums);
            }
        } else if (pos == 1) {
            vector <long long> nums = {0, a[pos], a[0]};
            if (a[pos] + a[0] != 0) {
                ans += hundreds(nums);
            }
        } else if (pos == 0) {
            vector <long long> nums = {0, 0, a[0]};
            if (a[0] != 0) {
                ans += hundreds(nums);
            } 
        }
        ans = normalizeSpaces(ans);
        return ans;
    }
};