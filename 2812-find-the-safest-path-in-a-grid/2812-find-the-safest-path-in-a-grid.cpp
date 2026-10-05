class Solution {
public:

    int n;

    vector<vector<int>> directions = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    // Check if destination can be reached
    // while maintaining safeness >= k
    bool canReach(vector<vector<int>>& dist, int k) {

        if (dist[0][0] < k)
            return false;

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            if (r == n - 1 && c == n - 1)
                return true;

            for (auto& dir : directions) {

                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n &&
                    !visited[nr][nc] &&
                    dist[nr][nc] >= k) {

                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {

        n = grid.size();

        // --------------------------------
        // STEP 1: Multi-source BFS
        // --------------------------------

        vector<vector<int>> dist(
            n,
            vector<int>(n, -1)
        );

        queue<pair<int, int>> q;

        // Put all thieves into the queue
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {

                if (grid[r][c] == 1) {
                    dist[r][c] = 0;
                    q.push({r, c});
                }
            }
        }

        // BFS
        while (!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            for (auto& dir : directions) {

                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n &&
                    dist[nr][nc] == -1) {

                    dist[nr][nc] = dist[r][c] + 1;

                    q.push({nr, nc});
                }
            }
        }

        // --------------------------------
        // STEP 2: Binary Search
        // --------------------------------

        int low = 0;
        int high = 2 * n;

        int answer = 0;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (canReach(dist, mid)) {

                answer = mid;
                low = mid + 1;

            } else {

                high = mid - 1;
            }
        }

        return answer;
    }
};