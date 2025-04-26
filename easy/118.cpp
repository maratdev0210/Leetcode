#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
     vector<vector<int>> generate(int numRows) {
         vector <vector<int>> answer; 
         for (int i = 0; i < numRows; i++) {
            int cols = i + 1;
            vector <int> row(cols);
            if (cols == 1) {
                row[0] = 1;
                answer.push_back(row);
                continue;
            } else if (cols == 2) {
                row[0] = 1;
                row[1] = 1;
                answer.push_back(row);
                continue;
            }
            row[0] = 1;
            row[cols - 1] = 1;
            for (int j = 1; j < cols - 1; j++) {
                row[j] = answer[i - 1][j - 1] + answer[i - 1][j];
            }
            answer.push_back(row);
         }   
         return answer;
    }
};