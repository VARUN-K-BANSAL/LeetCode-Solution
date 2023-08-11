class Solution {
    
    public int solve(int[] coins, int amount) {
        if(amount == 0)
            return 0;
        
        if(amount < 0)
            return Integer.MAX_VALUE;
        
        int min = Integer.MAX_VALUE;
        
        for(int i=0; i<coins.length; i++) {
            int temp = solve(coins, amount - coins[i]);
            if(temp != Integer.MAX_VALUE)
                min = Math.min(min, temp + 1);
        }
        
        return min;
    }
    
    public int solveMem(int[] coins, int amount, int[] dp) {
        if(amount == 0)
            return 0;
        if(amount < 0)
            return Integer.MAX_VALUE;
        
        if(dp[amount] != -1)
            return dp[amount];
        
        int min = Integer.MAX_VALUE;
        for(int i=0; i<coins.length; i++) {
            int temp = solveMem(coins, amount - coins[i], dp);
            if(temp != Integer.MAX_VALUE)
                min = Math.min(min, temp + 1);
        }
        
        return dp[amount] = min;
    }
    
    public int solveDp2(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        
        for(int i=1; i<=amount; i++) {
            for(int j=0; j<coins.length; j++) {
                if(i - coins[j] >= 0 && dp[i - coins[j]] != Integer.MAX_VALUE)
                    dp[i] = Math.min(dp[i], dp[i - coins[j]] + 1);                                           
            }
        }
        return dp[amount];
    }
    
    public int coinChange(int[] coins, int amount) {
        // using recursion
        //int ans = solve(coins, amount);
        
        // optimised approach using top-down dp
        // int[] dp = new int[amount + 1];
        // Arrays.fill(dp, -1);
        // int ans = solveMem(coins, amount, dp);
        
        // Optimised approach suign bottom-up approach
        int ans = solveDp2(coins, amount);
        
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}