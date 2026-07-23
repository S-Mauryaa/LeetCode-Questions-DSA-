class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans(k);

        if (x < arr[0]) {
            for (int i = 0; i < k; i++)
                ans[i] = arr[i];
            return ans;
        }

        if (x > arr[n - 1]) {
            for (int i = n - k; i < n; i++)
                ans[i - (n - k)] = arr[i];
            return ans;
        }

        int lo = 0, hi = n - 1;
        bool flag = false;
        int mid = -1;
        int t = 0;

        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;

            if (arr[mid] == x) {
                flag = true;
                ans[t++] = arr[mid];
                break;
            } else if (arr[mid] > x)
                hi = mid - 1;
            else
                lo = mid + 1;
        }

        int lb, up;

        if (flag) {
            lb = mid - 1;
            up = mid + 1;
        } else {
            lb = hi;
            up = lo;
        }

        while (t < k && lb >= 0 && up < n) {
            int d1 = abs(x - arr[lb]);
            int d2 = abs(x - arr[up]);

            if (d1 <= d2)
                ans[t++] = arr[lb--];
            else
                ans[t++] = arr[up++];
        }

        while (t < k && lb >= 0)
            ans[t++] = arr[lb--];

        while (t < k && up < n)
            ans[t++] = arr[up++];

        sort(ans.begin(), ans.end());
        return ans;
    }
};