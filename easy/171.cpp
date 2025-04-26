#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
    int titleToNumber(string columnTitle) {
        map <char, int> ch;
        int cnt = 1;
        for (char i = 'A'; i <= 'Z'; i++) {
            ch[i] = cnt;
            cnt++;
        }
        if (columnTitle.size() == 1) {
            return ch[columnTitle[0]];
        }
        int answer = 0;
        for (int i = 0; i < columnTitle.size(); i++) {
            int p = 1;
            for (int j = 0; j < columnTitle.size() - i - 1; ++j) {
                p *= 26;
            }
            answer += (p * ch[columnTitle[i]]);
        }
        return answer;
    }
};