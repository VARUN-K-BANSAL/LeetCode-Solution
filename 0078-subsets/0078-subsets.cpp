class Solution {
public:
    void helper(int i, vector<int>& nums, int k, vector<int>& ans, vector<vector<int>>& res) {
        if(ans.size() == k) {
            res.push_back(ans);
            return;
        }
        for(int j = i; j<nums.size(); j++) {
            ans.push_back(nums[j]);
            helper(j + 1, nums, k, ans, res);
            ans.pop_back();
        }
    }
    vector<vector<int>> combine(vector<int>& nums, int k) {
        vector<vector<int>> res;
        vector<int> ans;
        helper(0, nums, k, ans, res);
        return res;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>> s;
        vector<int> v;
        s.insert(v);
        for(int i=1; i<=nums.size(); i++) {
            vector<vector<int>> temp = combine(nums, i);
            for(auto iter : temp) {
                s.insert(iter);
            }
        }

        vector<vector<int>> res;
        for(auto iter : s) {
            res.push_back(iter);
        }
        return res;
    }
};