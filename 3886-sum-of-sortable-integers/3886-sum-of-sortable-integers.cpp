class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool possible = true;

            for (int start = 0; start < n && possible; start += k) {
                int descents = 0;

                for (int j = 1; j < k; j++) {
                    if (nums[start + j] < nums[start + j - 1]) {
                        descents++;
                    }
                }

                if (descents > 1) {
                    possible = false;
                } else if (descents == 1 &&
                           nums[start + k - 1] > nums[start]) {
                    possible = false;
                }
            }

            if (!possible) continue;

            vector<int> rotated = nums;

            for (int start = 0; start < n; start += k) {
                int pivot = start;
                int descents = 0;

                for (int j = 1; j < k; j++) {
                    if (nums[start + j] < nums[start + j - 1]) {
                        descents++;
                        pivot = start + j;
                    }
                }

                if (descents == 1) {
                    rotate(rotated.begin() + start,
                           rotated.begin() + pivot,
                           rotated.begin() + start + k);
                }
            }

            if (is_sorted(rotated.begin(), rotated.end())) {
                ans += k;
            }
        }

        return ans;
    }
};