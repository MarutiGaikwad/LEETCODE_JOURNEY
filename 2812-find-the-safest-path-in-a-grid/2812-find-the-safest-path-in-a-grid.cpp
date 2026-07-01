class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        // Step 1: Compute distance of every cell from nearest thief
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    dist[nr][nc] == INT_MAX) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        // Step 2: Max Heap (Maximum Minimum Path)
        priority_queue<vector<int>> pq;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        pq.push({dist[0][0], 0, 0});
        vis[0][0] = 1;

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int safe = cur[0];
            int r = cur[1];
            int c = cur[2];

            if (r == n - 1 && c == n - 1)
                return safe;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    !vis[nr][nc]) {

                    vis[nr][nc] = 1;
                    pq.push({min(safe, dist[nr][nc]), nr, nc});
                }
            }
        }

        return 0;
    }
};