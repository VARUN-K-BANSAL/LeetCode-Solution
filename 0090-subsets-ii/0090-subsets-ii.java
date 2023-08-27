class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    public void findSubsets(int[] nums, List<Integer> curr, int start) {
        ans.add(new ArrayList<>(curr));
        for(int i=start; i < nums.length; i++) {
            if(i > start && nums[i] == nums[i-1]) continue;
            curr.add(nums[i]);
            findSubsets(nums, curr, i + 1);
            curr.remove(curr.size() - 1);
        }
    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<Integer> curr = new ArrayList<>();
        findSubsets(nums, curr, 0);
        return ans;
    }
}