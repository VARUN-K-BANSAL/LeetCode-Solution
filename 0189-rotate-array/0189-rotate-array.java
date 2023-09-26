class Solution {
    public void reverse(int[] a, int st, int en) {
        while(st < en) {
            int temp = a[st];
            a[st] = a[en];
            a[en] = temp;
            st++;
            en--;
        }
    }
    public void rotate(int[] nums, int k) {
        int n = nums.length;
//         int ans[] = new int[n];
//         for(int i=0; i<n; i++) {
//             ans[(i + k) % n] = nums[i];
//         }
        
//         for(int i=0; i<n; i++) {
//             nums[i] = ans[i];
//         }
        
        
//          Second approach
        
        k = k % n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
}