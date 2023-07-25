class Solution {
    public long[] findPrefixScore(int[] nums) {
        int n = nums.length;
        long [] PS = new long[n];
        long max = 0, sum = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] > max) {
                max = nums[i];
            }
            sum += 1L * nums[i] + max;
            PS[i] = sum;
        }

        return PS;
    }
}