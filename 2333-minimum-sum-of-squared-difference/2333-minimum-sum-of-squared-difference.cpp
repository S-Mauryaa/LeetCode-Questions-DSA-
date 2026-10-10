class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {

        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<long long> diff(n);
        long long maxDiff = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
        }

        long long total = 0;

        for (long long d : diff) {
            total += d;
        }

        // If all differences can become zero
        if (total <= k) {
            return 0;
        }

        // Binary search for the minimum achievable maximum difference
        long long low = 0, high = maxDiff;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long operations = 0;

            for (long long d : diff) {
                if (d > mid) {
                    operations += d - mid;
                }
            }

            if (operations <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        long long level = low;
        long long remaining = k;

        // Reduce all differences greater than the chosen level
        for (long long& d : diff) {
            if (d > level) {
                remaining -= d - level;
                d = level;
            }
        }

        // Use remaining operations to reduce some differences by one
        for (long long& d : diff) {
            if (remaining > 0 && d == level) {
                d--;
                remaining--;
            }
        }

        long long ans = 0;

        for (long long d : diff) {
            ans += d * d;
        }

        return ans;
    }
};