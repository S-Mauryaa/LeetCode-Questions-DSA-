class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int k = nums[0];

        // ascending rotation
        bool asc = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != (k + i) % n) { asc = false; break; }
        }
        if (asc) {
            if (k == 0) return 0;
            return min(n - k, k + 2);
        }

        // descending rotation
        bool desc = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != (k - i + n) % n) { desc = false; break; }
        }
        if (desc) {
            int m = (k + 1) % n;
            return 1 + min(m, n - m);
        }

        return -1;
    }
};