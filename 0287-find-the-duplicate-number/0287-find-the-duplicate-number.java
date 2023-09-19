class Solution {
    public int findDuplicate(int[] nums) {
//         Arrays.sort(nums);
//         for(int i=0; i<nums.length - 1; i++) {
//             if(nums[i] == nums[i+1]) {
//                 return nums[i+1];
//             }
//         }
        
        for(int i=0; i<nums.length; i++) {
            int val = Math.abs(nums[i]);
            if(nums[val] < 0) {
                return val;
            }
            nums[val] = -nums[val];
        }
        
        return -1;
    }
}