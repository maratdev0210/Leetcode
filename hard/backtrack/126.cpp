#include <bits/stdc++.h>

using namespace std;

bool differByOne(string &a, string &b) {
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            cnt++;
        }
    }
    if (cnt == 1) {
        return true;
    }
    return false;
}

const int maxN = 510;
const int maxDist = 1e6 + 10;

vector <vector<string>> ans;

void reconstruct(int current, int source, vector<int> prev[], vector<vector<int>> &paths, vector<int> &current_path) {
    if (current == source) {
        paths.push_back(current_path);
        return;
    }

    for (auto x: prev[current]) {
        current_path.push_back(x);
        reconstruct(x, source, prev, paths, current_path);
        current_path.pop_back();
    }
}

class Solution {
    public:
        vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
            vector <int> adj[maxN];
            vector <int> sources;

            for (int i = 0; i < wordList.size(); i++) {
                if (differByOne(wordList[i], beginWord)) {
                    sources.push_back(i);
                }
                for (int j = 0; j < wordList.size(); j++) {
                    if (differByOne(wordList[i], wordList[j])) {
                        adj[i].push_back(j);
                    }
                }
            }

            int pos = -1;
            for (int i = 0; i < wordList.size(); i++) {
                if (wordList[i] == endWord) {
                    pos = i;
                    break;
                }
            }

            if (pos == -1) {
                vector <vector<string>> temp = {};
                return temp;
            }
            
            int shortest = maxN;
            for (int i = 0; i < sources.size(); i++) {
                int source = sources[i];
                vector <int> distances(wordList.size() + 10, maxDist); 
                vector <int> prev[maxN];
                queue <int> q;
                q.push(source);
                distances[source] = 0;
                while (!q.empty()) {
                    int cur = q.front();
                    q.pop();
        
                    if (cur == pos) {
                        break;
                    }
        
                    for (auto x: adj[cur]) {
                        if (distances[x] == maxDist) {
                            distances[x] = distances[cur] + 1;
                            prev[x].push_back(cur);
                            q.push(x);
                        } else if (distances[x] == distances[cur] + 1) {
                            prev[x].push_back(cur);
                        }
                    }
                }
             
                if (distances[pos] != maxDist) {
                    vector<vector<int>> paths;
                    vector<int> current = {pos};
                    reconstruct(pos, source, prev, paths, current);
                    
                    for (vector<int> &path: paths) {
                        reverse(path.begin(), path.end());
                    }
                    
                    for (int i = 0; i < paths.size(); i++) {
                        vector <string> cur;
                        cur.push_back(beginWord);
                        for (int j = 0; j < paths[i].size(); j++) {
                            cur.push_back(wordList[paths[i][j]]);
                        }
                        shortest = min(shortest, (int)cur.size());
                        ans.push_back(cur);
                    }
                    
                }   
            }

            vector <vector<string>> final;
            for (int i = 0; i < ans.size(); i++) {
                if (ans[i].size() == shortest) {
                    final.push_back(ans[i]);
                }
                
            }
            
            vector<vector<string>> temp = ans;
            ans.clear();
            return temp;
        }
    };