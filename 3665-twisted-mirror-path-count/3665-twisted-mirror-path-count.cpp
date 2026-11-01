class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> R(m, vector<int>(n, 0)), D(m, vector<int>(n, 0));
        R[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int total = (R[i][j] + D[i][j]) % MOD;
                    if (j + 1 < n) R[i][j + 1] = (R[i][j + 1] + total) % MOD;
                    if (i + 1 < m) D[i + 1][j] = (D[i + 1][j] + total) % MOD;
                } else {
                    // entered moving right -> reflected down
                    if (i + 1 < m) D[i + 1][j] = (D[i + 1][j] + R[i][j]) % MOD;
                    // entered moving down -> reflected right
                    if (j + 1 < n) R[i][j + 1] = (R[i][j + 1] + D[i][j]) % MOD;
                }
            }
        }
        return (R[m - 1][n - 1] + D[m - 1][n - 1]) % MOD;
    }
};