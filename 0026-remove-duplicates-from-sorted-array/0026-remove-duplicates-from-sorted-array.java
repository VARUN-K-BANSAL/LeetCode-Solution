class Solution {
    public int removeDuplicates(int[] nums) {
        ArrayList<Integer> u = new ArrayList<>();
        int ans = 0;
        u.add(nums[0]);
        for(int i=1; i<nums.length; i++) {
            if(u.get(ans) != nums[i]) {
                u.add(nums[i]);
                ans++;
            }
        }
        
        for(int i=0; i<ans + 1; i++) {
            nums[i] = u.get(i);
        }
        
        return ans + 1;
    }
}