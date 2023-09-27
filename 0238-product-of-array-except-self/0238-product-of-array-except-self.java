class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
//         int pref[] = new int[n];
//         int suff[] = new int[n];
        
//         pref[0] = 1;
//         for(int i=1; i<n; i++) {
//             pref[i] = pref[i - 1] * nums[i - 1];
//         }
        
//         suff[n-1] = 1;
//         for(int i=n-2; i>=0; i--) {
//             suff[i] = suff[i + 1] * nums[i + 1];
//         }
        
//         int ans[] = new int[n];
//         for(int i=0; i<n; i++) {
//             ans[i] = pref[i] * suff[i];
//         }
        
//         return ans;
        
//         Space Optimised
        
        int ans[] = new int[n];
        ans[0] = 1;
        for(int i=1; i<n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        
        int temp = 1;
        for(int i=n-1; i>=0; i--) {
            ans[i] *= temp;
            temp *= nums[i];
        }
        
        return ans;
    }
}