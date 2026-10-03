class Solution {
public:
    string s1, s2;
    int dp[30][30][31];

    bool solve(int i, int j, int len) {

        // Already calculated
        if (dp[i][j][len] != -1)
            return dp[i][j][len];

        // Same substring
        if (s1.compare(i, len, s2, j, len) == 0)
            return dp[i][j][len] = true;

        // Character frequency pruning
        int freq[26] = {};

        for (int k = 0; k < len; k++) {
            freq[s1[i + k] - 'a']++;
            freq[s2[j + k] - 'a']--;
        }

        for (int k = 0; k < 26; k++) {
            if (freq[k] != 0)
                return dp[i][j][len] = false;
        }

        // Try every possible split
        for (int k = 1; k < len; k++) {

            // Case 1: No swap
            if (solve(i, j, k) &&
                solve(i + k, j + k, len - k))
                return dp[i][j][len] = true;

            // Case 2: Swap
            if (solve(i, j + len - k, k) &&
                solve(i + k, j, len - k))
                return dp[i][j][len] = true;
        }

        return dp[i][j][len] = false;
    }

    bool isScramble(string s1, string s2) {

        if (s1.length() != s2.length())
            return false;

        this->s1 = s1;
        this->s2 = s2;

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, s1.length());
    }
};