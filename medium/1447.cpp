class Solution {
public:
    vector<string> simplifiedFractions(int n) {
      set <string> s;
      for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; ++j) {
            int g = gcd(i, j);
            int x = i / g;
            int y = j / g;
            string s1 = to_string(x);
            string s2 = to_string(y);
            string r = s1 + "/" + s2;
            s.insert(r);
        }
      }
      vector <string> res;
      for (auto x: s) {
        res.push_back(x);
      }
      return res;
    }
};