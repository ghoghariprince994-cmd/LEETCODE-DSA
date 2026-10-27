class Solution {
public:
    vector<string> createGrid(int m, int n) {
         vector<string> res(m, string(n, '#'));

        for (int i = 0; i < m; i++) {
            res[i][0] = '.';
        }

        for (int j = 0; j < n; j++) {
            res[m - 1][j] = '.';
        }

        return res;
    }
};