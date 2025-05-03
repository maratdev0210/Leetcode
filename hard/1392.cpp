#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

class Solution {
    public:
        string longestPrefix(string s) {
            int n = s.size();
            vector <int> pref = prefix_function(s);
            int m = pref[n - 1]; 
            return s.substr(0, m);
        }
};