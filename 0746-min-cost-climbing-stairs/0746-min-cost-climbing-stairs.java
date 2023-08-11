class Solution {
    public int solve(int[] cost, int n) {
        if(n <= 1)
            return cost[n];
        
        return Math.min(solve(cost, n-1), solve(cost, n-2)) + cost[n];
    }
    
    public int solveDp(int[] cost, int n, int[] dp) {
        if(n <= 1)
            return cost[n];
        
        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = Math.min(solveDp(cost, n-1, dp), solveDp(cost, n-2, dp)) + cost[n];
    }
    
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        
        // recursive method will give TLE
        // int ans = Math.min(solve(cost, n-1), solve(cost, n-2));
        
        // Optimised approach using top-down dp
        int[] dp = new int[n+1];
        for(int i=0; i<=n; i++)
            dp[i] = -1;
        int ans = Math.min(solveDp(cost, n-1, dp), solveDp(cost, n-2, dp));
        
        return ans;
    }
}