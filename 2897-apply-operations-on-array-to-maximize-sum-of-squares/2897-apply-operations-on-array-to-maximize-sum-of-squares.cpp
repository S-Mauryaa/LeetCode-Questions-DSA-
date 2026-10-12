class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;

        vector<int> bits(31, 0);

        // Step 1: Count occurrences of every set bit
        for (int num : nums) {
            for (int b = 0; b < 31; b++) {
                if (num & (1 << b)) {
                    bits[b]++;
                }
            }
        }

        long long ans = 0;

        // Step 2: Greedily construct k numbers
        for (int i = 0; i < k; i++) {
            long long x = 0;

            for (int b = 0; b < 31; b++) {
                if (bits[b] > 0) {
                    x |= (1LL << b);
                    bits[b]--;
                }
            }

            // Step 3: Add the square modulo MOD
            ans = (ans + x * x % MOD) % MOD;
        }

        return ans;
    }
};