class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        // best[i] = minimum length of a valid subarray
        // completely inside arr[0...i]
        vector<int> best(n, INF);

        int left = 0;
        long long sum = 0;
        int ans = INF;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            // Shrink the window if sum becomes too large
            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            // If current window has sum == target
            if (sum == target) {
                int len = right - left + 1;

                // Check for a previous non-overlapping subarray
                if (left > 0 && best[left - 1] != INF) {
                    ans = min(ans, len + best[left - 1]);
                }

                // This is the best valid subarray ending at right
                if (right == 0) {
                    best[right] = len;
                } else {
                    best[right] = min(best[right - 1], len);
                }
            } 
            else {
                // No valid subarray ending at right
                if (right > 0) {
                    best[right] = best[right - 1];
                }
            }
        }

        return ans == INF ? -1 : ans;
    }
};