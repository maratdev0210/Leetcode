class Solution {
    public:
        int findCenter(vector<vector<int>>& edges) {
            map <int, int> m;
            for (int i = 0; i < edges.size(); i++) {
                m[edges[i][0]]++;
                m[edges[i][1]]++;
            }
            for (int i = 1; i <= edges.size(); i++) {
                if (m[i] == edges.size()) {
                    return i;
                }
            }
            return 0;
        }
    };