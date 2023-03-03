class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, level = 0, ans = 0;
        while(l < r) {
            int temp = 0;
            if(height[l] < height[r]) {
                temp = height[l];
                l++;
            } else {
                temp = height[r];
                r--;
            }
            level = (level > temp) ? level : temp;
            ans += (level - temp);
        }
        return ans;
    }
};