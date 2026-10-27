class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0 and !vis[i][j]) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j]=1;
                    long long sum = 0;
                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();
                        sum += grid[r][c];
                        for (int d = 0; d < 4; d++) {
                            int nr = r + dx[d];
                            int nc = c + dy[d];
                            if (nr>=0 and nc>=0 and nr<=m-1 and nc<=n-1 and grid[nr][nc]>0 and !vis[nr][nc]) {
                                vis[nr][nc] = 1;
                                q.push({nr,nc});
                            }
                        }
                    }
                    if (sum % k == 0) cnt++;
                }
            }
            
        }

        return cnt;
    }
};