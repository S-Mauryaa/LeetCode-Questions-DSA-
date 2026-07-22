class Solution {
public:
    int binarySearch(vector<int>& nums, int lo, int hi, int target) {
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();

        // Step 1: Find Pivot (Smallest Element)
        int lo = 0, hi = n - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] > nums[hi])
                lo = mid + 1;
            else
                hi = mid;
        }

        int pivot = lo;

        // Step 2: If array is not rotated
        if (pivot == 0)
            return binarySearch(nums, 0, n - 1, target);

        // Step 3: Decide which half to search
        if (target >= nums[0] && target <= nums[pivot - 1])
            return binarySearch(nums, 0, pivot - 1, target);
        else
            return binarySearch(nums, pivot, n - 1, target);
    }
};