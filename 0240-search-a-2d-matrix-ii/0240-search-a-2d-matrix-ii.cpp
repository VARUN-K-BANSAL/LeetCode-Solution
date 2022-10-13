class Solution {
public:
    // bool binarySearch(vector<int> v, int l, int r, int target) {
    //     if(l > r) return false;
    //     int mid = (l + r) / 2;
    //     if(v[mid] == target) return true;
    //     if(v[mid] < target) {
    //         return binarySearch(v, mid + 1, r, target);
    //     }
    //     return binarySearch(v, l, mid - 1, target);
    // }
    bool searchMatrix(vector<vector<int>>& v, int target) {
        // int row = 0;
        int m = v.size();
        int n = v[0].size();
        // for(int i=0; i<m; i++) {
        //     row = i;
        //     if(v[i][0] == target) return true;
        //     if(v[i][0] > target) {
        //         break;
        //     }
        // }
        // for(int i=0; i<=row; i++) {
        //     if(binarySearch(v[i], 0, n - 1, target)) return true;
        // }
        // return false;
        
        int i = m - 1, j = 0;
        while(i >= 0 && j < n) {
            if(v[i][j] == target) return true;
            if(v[i][j] > target) {
                i--;
            } else {
                j++;
            }
        }
        return false;
    }
};