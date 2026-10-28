class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int K = 1024;

        // dp[j] = set of reachable XOR values at current row, column j
        vector<vector<char>> dp(n, vector<char>(K, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<char> cur(K, 0);

                if (i == 0 && j == 0) {
                    cur[grid[0][0]] = 1;
                } else {
                    for (int x = 0; x < K; x++) {
                        bool reachable = false;
                        // from above: dp[j] still holds the previous row's value
                        if (i > 0 && dp[j][x]) reachable = true;
                        // from left: dp[j-1] already updated for current row
                        if (j > 0 && dp[j - 1][x]) reachable = true;
                        if (reachable) cur[x ^ grid[i][j]] = 1;
                    }
                }
                dp[j] = std::move(cur);
            }
        }

        for (int x = 0; x < K; x++) {
            if (dp[n - 1][x]) return x;
        }
        return -1;
    }
};