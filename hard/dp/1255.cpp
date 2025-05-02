#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
            int n = words.size();
            int m = letters.size();
            map <char, int> cnt;
            for (int i = 0; i < m; ++i) {
                cnt[letters[i]]++;
            }

            long long mx = 0;
    for (int i = 0; i < (1 << n); ++i) {
        string s = "";
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                s += "1";
            } else {
                s += "0";
            }
        }
        reverse(s.begin(), s.end());
        map <char, int> cnt2 = cnt;
        bool ok = true;
        long long sum = 0;
        for (int j = 0; j < n; ++j) {
            if (s[j] == '1') {
                for (int k = 0; k < words[j].size(); ++k) {
                    cnt2[words[j][k]] -= 1;
                    sum += score[words[j][k] - 'a'];
                    if (cnt2[words[j][k]] < 0) {
                        ok = false;
                        break;
                    }
                }
            }
            if (!ok) {
                break;
            }
        }
        if (ok) {
            mx = max(mx, sum);
        }
    }
    return mx;
        }
};