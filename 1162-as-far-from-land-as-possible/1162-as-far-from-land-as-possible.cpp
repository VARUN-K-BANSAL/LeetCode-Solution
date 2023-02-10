class Solution {
public:
    // void findMinDistance(vector<vector<int>>& g, int i, int j, int dist = 1) {
    //     if (i < 0 || j < 0 || i >= g.size() || j >= g[i].size() || (g[i][j] != 0 && g[i][j] <= dist)) return;
    //     g[i][j] = dist;
    //     findMinDistance(g, i - 1, j, dist + 1),
    //     findMinDistance(g, i, j - 1, dist + 1),
    //     findMinDistance(g, i + 1, j, dist + 1),
    //     findMinDistance(g, i, j + 1, dist + 1);
    // }
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0;
        vector<vector<int>> dp = grid;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) continue;
                int top = i-1 >= 0 ? dp[i-1][j] : 1e6;
                int left = j-1 >= 0 ? dp[i][j-1] : 1e6;
                dp[i][j] = min(top, left) + 1;
            }
        }
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j]) continue;
                int down = i+1 < n ? dp[i+1][j] : 1e6;
                int right = j+1 < n ? dp[i][j+1] : 1e6;
                dp[i][j] = min(dp[i][j], min(down, right) + 1);
                res = max(res, dp[i][j]);
            }
        }
        
        return res >= 1e6 ? -1 : res - 1;
    }
};