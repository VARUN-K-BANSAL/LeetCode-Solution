class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int n = nums.length;
//         int pref[] = new int[n];
//         pref[0] = nums[0];
//         for(int i=1; i<n; i++)
//             pref[i] = pref[i - 1] + nums[i];
        
//         int ans = Integer.MAX_VALUE;
//         for(int i=0; i<n; i++) {
//             for(int j=i; j<n; j++) {
//                 int sum = pref[j] - pref[i] + nums[i];
//                 if(sum >= target) {
//                     ans = Math.min(ans, j - i + 1);
//                 }
//             }
//         }
        
//         return (ans != Integer.MAX_VALUE) ? ans : 0;
        
//         Above will Give TLE
        int left = 0;
        int ans = Integer.MAX_VALUE;
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            while(sum >= target) {
                ans = Math.min(ans, i - left + 1);
                sum -= nums[left++];
            }
        }
        
        return (ans != Integer.MAX_VALUE) ? ans : 0;
    }
}