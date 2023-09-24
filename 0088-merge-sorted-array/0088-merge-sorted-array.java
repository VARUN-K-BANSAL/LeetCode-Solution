class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int [] ans = new int[n + m];
        int i = 0, j = 0, k = 0;
        
        while(i < m && j < n) {
            if(nums1[i] > nums2[j]) {
                ans[k++] = nums2[j++];
            } else if(nums1[i] < nums2[j]) {
                ans[k++] = nums1[i++];
            } else {
                ans[k++] = nums1[i++];
                ans[k++] = nums2[j++];
            }
        }
        
        while(i < m) {
            ans[k++] = nums1[i++];
        }
        
        while(j < n) {
            ans[k++] = nums2[j++];
        }
        
        for(int ind=0; ind<k; ind++) {
            nums1[ind] = ans[ind];
        }
        
    }
}