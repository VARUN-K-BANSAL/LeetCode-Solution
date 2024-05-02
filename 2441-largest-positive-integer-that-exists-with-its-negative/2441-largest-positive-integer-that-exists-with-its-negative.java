class Solution {
    public int findMaxK(int[] nums) {
        Map<Integer, Integer> mp = new HashMap<>();
        for(int num : nums) {
            mp.put(num, mp.getOrDefault(num, 0) + 1);
        }
        int ans = -1;
        for(int num: nums) {
            if(ans < num && (mp.getOrDefault(-1 * num, 0) != 0)) {
                ans = num;
            }
        }
        return ans;
    }
}