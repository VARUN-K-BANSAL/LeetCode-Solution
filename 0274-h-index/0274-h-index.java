class Solution {
    public int hIndex(int[] a) {
        Arrays.sort(a);
        int ans = 0;
        int n = a.length;
        for(int i=0; i<n; i++) {
            int h = n - i;
            if(h <= a[i]) ans = Math.max(ans, h);
        }
        
        return ans;
    }
}