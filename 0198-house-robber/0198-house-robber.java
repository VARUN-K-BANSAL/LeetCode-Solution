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
    
    public int rob(int[] nums) {
        // using recursion will give TLE
        // int ans = solve(nums, nums.length - 1);
        
        // Using top-down dp approach
        int[] dp = new int[nums.length + 1];
        Arrays.fill(dp, -1);
        int ans = solveMem(nums, nums.length - 1, dp);
        
        
        return ans;
    }
}