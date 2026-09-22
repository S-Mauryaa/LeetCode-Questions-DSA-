class Solution {
public:
    static const int MOD = 1e9 + 7;

    int numberOfSets(int n, int k) {
        // We need C(n + k - 1, 2k)
        int N = n + k - 1;

        vector<vector<long long>> C(N + 1,
                                    vector<long long>(2 * k + 1));

        for (int i = 0; i <= N; i++) {
            C[i][0] = 1;

            for (int j = 1; j <= min(i, 2 * k); j++) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }

        return C[N][2 * k];
    }
};