class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        int i = 0, j = n - 1;
        while(i < j) {
            int sum = nums[i] + nums[j];
            if(sum == target) {
                int[] ans = new int[2];
                ans[0] = i + 1;
                ans[1] = j + 1;
                return ans;
            }
            if(sum < target) i++;
            else j--;
        }
        return new int[2];
    }
}