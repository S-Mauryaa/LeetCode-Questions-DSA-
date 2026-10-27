class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res(m, string(n, '#'));

        for (int j = 0; j < n; j++) res[0][j] = '.';
        for (int i = 0; i < m; i++) res[i][n - 1] = '.';

        return res;
    }
};