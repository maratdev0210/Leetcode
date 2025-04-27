class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map <char, int> m;
        for (auto ch: stones) {
            m[ch]++;
        }
        int cnt = 0;
        for (auto ch: jewels) {
            cnt += m[ch];
        }
        return cnt;
    }
};