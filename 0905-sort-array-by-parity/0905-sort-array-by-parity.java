class Solution {
    public int[] sortArrayByParity(int[] nums) {
        int n = nums.length;
        int ans[] = new int[n];
        int k = 0, z = n - 1;
        
        for(int i=0; i<n; i++) {
            if(nums[i] % 2 == 0) {
                ans[k++] = nums[i];
            } else {
                ans[z--] = nums[i];
            }
        }
        
        return ans;
    }
}