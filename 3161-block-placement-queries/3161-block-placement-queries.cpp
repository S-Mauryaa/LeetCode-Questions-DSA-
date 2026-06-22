class SegmentTree {
    int n;
    vector<int> tree;

public:
    SegmentTree(int n) {
        this->n = n;
        tree.resize(4 * n + 5, 0);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int idx, int val) {
        update(1, 0, n, idx, val);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l)
            return 0;

        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        return max(
            query(node * 2, l, mid, ql, qr),
            query(node * 2 + 1, mid + 1, r, ql, qr)
        );
    }

    int query(int l, int r) {
        if (l > r) return 0;
        return query(1, 0, n, l, r);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {

        int MAXX = 50000;

        set<int> obstacles;
        obstacles.insert(0);

        SegmentTree seg(MAXX + 1);

        vector<bool> ans;

        for (auto &q : queries) {

            if (q[0] == 1) {

                int pos = q[1];

                auto it = obstacles.upper_bound(pos);

                int right = (it == obstacles.end()) ? MAXX : *it;
                int left = *prev(it);

                seg.update(pos, pos - left);

                if (right != MAXX)
                    seg.update(right, right - pos);

                obstacles.insert(pos);
            }
            else {

                int x = q[1];
                int sz = q[2];

                auto it = obstacles.upper_bound(x);

                int lastObs = *prev(it);

                int best = seg.query(0, lastObs);

                best = max(best, x - lastObs);

                ans.push_back(best >= sz);
            }
        }

        return ans;
    }
};