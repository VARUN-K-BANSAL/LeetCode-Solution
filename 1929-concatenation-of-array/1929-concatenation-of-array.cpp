class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> v;
        int n = nums.size();
        for(int k=0; k<2; k++) {
            for(int i=0; i<n; i++) {
                v.push_back(nums[i]);
            }
        }
        return v;
    }
};