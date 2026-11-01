class Solution {
public:
    int m, n;
    const int mod = 1e9 + 7;

    int solve(int i, int j,int dir, vector<vector<int>>& grid, vector<vector<vector<int>>>&dp) {
        if (i >= m or j >= n) return 0;
        if (i == m - 1 and j == n - 1) return 1;
        if (dp[i][j][dir] != -1) return dp[i][j][dir];
        int ans = 0;

        if(grid[i][j]==1) {
            if(dir==0){
                ans += solve(i+1,j,1,grid,dp);
            }
            else {
                ans += solve(i,j+1,0,grid,dp); 
            }
        }
        else {
            ans += (solve(i,j+1,0,grid,dp) + solve(i+1,j,1,grid,dp)) % mod ; 
        }
        
        return dp[i][j][dir] = ans % mod;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(2,-1)));
        int ans = 0;
        return solve(0, 0, 0,grid, dp);
    }
};