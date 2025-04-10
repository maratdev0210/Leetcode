#include <bits/stdc++.h>

using namespace std;

const long long maxN = 10000;
const long long maxDist = 1e6 + 10;

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

class Solution {
    public:
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            vector<int> adj[maxN];
            vector <int> sources;

            for (int i = 0; i < wordList.size(); i++) {
                if (differByOne(wordList[i], beginWord)) {
                    adj[0].push_back(i + 1);  // words start with 1
                }
            }
        
            for (int i = 0; i < wordList.size(); i++) {
                for (int j = 0; j < wordList.size(); j++) {
                    if (differByOne(wordList[i], wordList[j])) {
                        adj[i + 1].push_back(j + 1);
                    }
                }
            }
        
            int pos = -1;
            for (int i = 0; i < wordList.size(); i++) {
                if (wordList[i] == endWord) {
                    pos = i + 1;
                    break;
                }
            }

            if (pos == -1) {
                return 0;
            }
        
            vector <int> distances(wordList.size() + 10, maxDist); 
            queue <int> q;
            q.push(0);
            distances[0] = 0;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                
                if (cur == pos) {
                    break;
                }
                
                for (auto x: adj[cur]) {
                    if (distances[x] == maxDist) {
                        distances[x] = distances[cur] + 1;
                        q.push(x);
                    } 
                }
            }
            
            if (distances[pos] != maxDist) {
        
                return distances[pos] + 1;
            } else {
                return 0;
            }
    }
};