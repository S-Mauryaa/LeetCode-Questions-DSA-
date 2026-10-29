class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n, 0));
        vector<int> depth(n, 0), tin(n), tout(n);

        // iterative DFS from root 0
        int timer = 0;
        vector<int> it(n, 0), stk;
        stk.push_back(0);
        up[0][0] = 0;
        tin[0] = ++timer;
        while (!stk.empty()) {
            int u = stk.back();
            if (it[u] < (int)adj[u].size()) {
                int v = adj[u][it[u]++];
                if (v == up[0][u] && u != 0) continue;
                if (u == 0 && v == 0) continue;
                up[0][v] = u;
                depth[v] = depth[u] + 1;
                tin[v] = ++timer;
                stk.push_back(v);
            } else {
                tout[u] = timer;
                stk.pop_back();
            }
        }

        for (int j = 1; j < LOG; j++)
            for (int v = 0; v < n; v++)
                up[j][v] = up[j - 1][up[j - 1][v]];

        auto lca = [&](int a, int b) {
            if (depth[a] < depth[b]) swap(a, b);
            int diff = depth[a] - depth[b];
            for (int j = 0; j < LOG; j++)
                if (diff >> j & 1) a = up[j][a];
            if (a == b) return a;
            for (int j = LOG - 1; j >= 0; j--)
                if (up[j][a] != up[j][b]) {
                    a = up[j][a];
                    b = up[j][b];
                }
            return up[0][a];
        };

        // Fenwick tree with XOR, size n+2
        vector<int> bit(n + 2, 0);
        auto upd = [&](int i, int val) {
            for (; i <= n + 1; i += i & -i) bit[i] ^= val;
        };
        auto qry = [&](int i) {
            int r = 0;
            for (; i > 0; i -= i & -i) r ^= bit[i];
            return r;
        };
        auto rangeXor = [&](int l, int r, int val) {
            upd(l, val);
            upd(r + 1, val);
        };

        vector<int> mask(n);
        for (int i = 0; i < n; i++) {
            mask[i] = 1 << (s[i] - 'a');
            rangeXor(tin[i], tout[i], mask[i]);
        }

        vector<bool> ans;
        for (auto& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                int nm = 1 << (c - 'a');
                int delta = mask[u] ^ nm;
                if (delta) {
                    rangeXor(tin[u], tout[u], delta);
                    mask[u] = nm;
                }
            } else {
                int u, v;
                ss >> u >> v;
                int l = lca(u, v);
                int m = qry(tin[u]) ^ qry(tin[v]) ^ mask[l];
                ans.push_back((m & (m - 1)) == 0);
            }
        }
        return ans;
    }
};