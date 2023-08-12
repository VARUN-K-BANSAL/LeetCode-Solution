class Solution {
    public int solve(int[] nums, int n) {
        if(n < 0)
            return 0;
        if(n == 0)
            return nums[0];
        
        return Math.max(solve(nums, n-2) + nums[n], solve(nums, n-1));
    }
    
    public int solveMem(int[] nums, int n, int[] dp) {
        if(n < 0)
            return 0;
        if(n == 0)
            return nums[0];
        
        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = Math.max(solveMem(nums, n-2, dp) + nums[n], solveMem(nums, n-1, dp));
    }
    
    public int solveTab(int[] nums) {
        int n = nums.length;
        
        if(n == 0)
            return 0;
        if(n == 1)
            return nums[0];
        if(n == 2)
            return Math.max(nums[0], nums[1]);
        int[] dp = new int[n];
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);
        
        for(int i=2; i<n; i++)
            dp[i] = Math.max(dp[i-2] + nums[i], dp[i-1]);
        
        return dp[n-1];
    }
    
    public int solveOpt(int[] nums) {
        int n = nums.length;
        
        if(n == 0)
            return 0;
        if(n == 1)
            return nums[0];
        if(n == 2)
            return Math.max(nums[0], nums[1]);
        
        int prev2 = 0;
        int prev1 = nums[0];
        
        for(int i=1; i<n; i++) {
            int ans = Math.max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = ans;
        }
        
        return prev1;
    }
    
    public int rob(int[] nums) {
        // using recursion will give TLE
        // int ans = solve(nums, nums.length - 1);
        
        // Using top-down dp approach
        // int[] dp = new int[nums.length + 1];
        // Arrays.fill(dp, -1);
        // int ans = solveMem(nums, nums.length - 1, dp);
        
        
        // using bottom-up dp approach
        // int ans = solveTab(nums);
        
        // doing space optimization
        int ans = solveOpt(nums);
        
        
        return ans;
    }
}