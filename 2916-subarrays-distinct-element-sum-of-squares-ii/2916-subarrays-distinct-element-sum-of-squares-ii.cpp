class Solution {
public:
    static const int MOD = 1e9 + 7;

    using ll = long long;

    struct Node {
        ll sum;
        ll sumSq;
        ll lazy;
    };

    vector<Node> tree;
    int n;

    void build(int node, int start, int end) {
        tree[node] = {0, 0, 0};

        if (start == end) return;

        int mid = start + (end - start) / 2;

        build(node * 2, start, mid);
        build(node * 2 + 1, mid + 1, end);
    }

    void apply(int node, int start, int end, ll val) {
        ll len = end - start + 1;

        tree[node].sumSq =
            (tree[node].sumSq
             + 2LL * val % MOD * tree[node].sum % MOD
             + len % MOD * val % MOD * val % MOD) % MOD;

        tree[node].sum = (tree[node].sum + len * val) % MOD;
        tree[node].lazy = (tree[node].lazy + val) % MOD;
    }

    void push(int node, int start, int end) {
        if (tree[node].lazy == 0 || start == end) return;

        int mid = start + (end - start) / 2;

        apply(node * 2, start, mid, tree[node].lazy);
        apply(node * 2 + 1, mid + 1, end, tree[node].lazy);

        tree[node].lazy = 0;
    }

    void update(int node, int start, int end,
                int l, int r, ll val) {
        if (r < start || end < l) return;

        if (l <= start && end <= r) {
            apply(node, start, end, val);
            return;
        }

        push(node, start, end);

        int mid = start + (end - start) / 2;

        update(node * 2, start, mid, l, r, val);
        update(node * 2 + 1, mid + 1, end, l, r, val);

        tree[node].sum =
            (tree[node * 2].sum + tree[node * 2 + 1].sum) % MOD;

        tree[node].sumSq =
            (tree[node * 2].sumSq + tree[node * 2 + 1].sumSq) % MOD;
    }

    ll query(int node, int start, int end,
             int l, int r) {
        if (r < start || end < l) return 0;

        if (l <= start && end <= r) {
            return tree[node].sumSq;
        }

        push(node, start, end);

        int mid = start + (end - start) / 2;

        return (
            query(node * 2, start, mid, l, r) +
            query(node * 2 + 1, mid + 1, end, l, r)
        ) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> last(100001, -1);

        ll ans = 0;

        for (int i = 0; i < n; i++) {
            int p = last[nums[i]];

            update(1, 0, n - 1, p + 1, i, 1);

            last[nums[i]] = i;

            ans = (ans + query(1, 0, n - 1, 0, i)) % MOD;
        }

        return ans;
    }
};