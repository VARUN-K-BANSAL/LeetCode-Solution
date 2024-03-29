class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int n = intervals.size();
        int i=0,j=1;
        ans.push_back(intervals[i]);
        
        while(j < n)
        {
            if(intervals[j][0]>ans[i][1])
            {
                i++;
                ans.push_back(intervals[j]);
            }
            else
            {
                ans[i][1] = max(ans[i][1],intervals[j][1]);
            }
            j++;
        }
        
        return ans;
    }
};