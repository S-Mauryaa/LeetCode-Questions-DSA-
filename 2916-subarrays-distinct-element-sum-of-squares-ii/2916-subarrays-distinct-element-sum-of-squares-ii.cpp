class Solution {
public:
    static constexpr long long MOD = 1'000'000'007;

    struct Node {
        long long sum = 0;
        long long sq = 0;
        long long lazy = 0;
    };

    vector<Node> seg;
    int n;

    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;
        long long oldSum = seg[node].sum;

        seg[node].sq = (
            seg[node].sq
            + 2 * val % MOD * oldSum % MOD
            + len % MOD * val % MOD * val % MOD
        ) % MOD;

        seg[node].sum = (oldSum + len * val) % MOD;
        seg[node].lazy = (seg[node].lazy + val) % MOD;
    }

    void push(int node, int l, int r) {
        if (seg[node].lazy == 0 || l == r)
            return;

        int mid = l + (r - l) / 2;
        long long val = seg[node].lazy;

        apply(node * 2, l, mid, val);
        apply(node * 2 + 1, mid + 1, r, val);

        seg[node].lazy = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l)
            return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, 1);
            return;
        }

        push(node, l, r);

        int mid = l + (r - l) / 2;

        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);

        seg[node].sum = (
            seg[node * 2].sum + seg[node * 2 + 1].sum
        ) % MOD;

        seg[node].sq = (
            seg[node * 2].sq + seg[node * 2 + 1].sq
        ) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();
        seg.assign(4 * n, Node{});

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            update(1, 0, n - 1, last[nums[i]] + 1, i);

            last[nums[i]] = i;

            ans = (ans + seg[1].sq) % MOD;
        }

        return ans;
    }
};