class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int r = matrix.size();
        int c = matrix[0].size();
        int k = 0;
        int l = 0;
        while(k < r && l < c) {
            // first row
            for(int i=l; i<c; i++) {
                v.push_back(matrix[k][i]);
            }
            k++;
            
            // last column
            for(int i=k; i<r; i++) {
                v.push_back(matrix[i][c-1]);
            }
            c--;
            
            // last row
            if(k < r) {
                for(int i=c-1; i>=l; i--) {
                    v.push_back(matrix[r-1][i]);
                }
                r--;
            }
            
            // first column
            if(l < c) {
                for(int i=r-1; i>=k; i--) {
                    v.push_back(matrix[i][l]);
                }
                l++;
            }
        }
        return v;
    }
};