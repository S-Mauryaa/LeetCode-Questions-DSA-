class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) adj[e[0]].push_back({e[1], e[2]});

        const long long INF = LLONG_MAX / 4;
        // dist[node * (k+1) + run]
        vector<long long> dist((size_t)n * (k + 1), INF);

        using T = tuple<long long, int, int>; // dist, node, run
        priority_queue<T, vector<T>, greater<T>> pq;

        dist[0 * (k + 1) + 1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, run] = pq.top();
            pq.pop();
            if (d > dist[(size_t)u * (k + 1) + run]) continue;
            if (u == n - 1) return (int)d; // first pop of target is optimal

            for (auto &[v, w] : adj[u]) {
                int nr;
                if (labels[u] == labels[v]) {
                    nr = run + 1;
                    if (nr > k) continue;
                } else {
                    nr = 1;
                }
                long long nd = d + w;
                size_t idx = (size_t)v * (k + 1) + nr;
                if (nd < dist[idx]) {
                    dist[idx] = nd;
                    pq.push({nd, v, nr});
                }
            }
        }
        return -1;
    }
};