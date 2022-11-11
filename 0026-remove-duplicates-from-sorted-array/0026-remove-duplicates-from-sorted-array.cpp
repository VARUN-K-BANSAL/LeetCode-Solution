class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        vector<int> v;
        v.push_back(nums[0]);
        int ans = 0;
        for(int i=1; i<nums.size(); i++) {
            if(v[ans] != nums[i]) {
                v.push_back(nums[i]);
                ans++;
            }
        }
        for(int i=0; i<v.size(); i++) {
            nums[i] = v[i];
        }
        return ans + 1;
    }
};