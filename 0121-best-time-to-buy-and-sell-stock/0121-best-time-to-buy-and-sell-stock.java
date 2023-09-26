class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[] suff = new int[n];
        suff[n-1] = prices[n-1];
        for(int i=n-2; i>=0; i--) {
            if(prices[i] > suff[i + 1]) {
                suff[i] = prices[i];
            } else {
                suff[i] = suff[i + 1];
            }
        }
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(suff[i] - prices[i] > ans) {
                ans = suff[i] - prices[i];
            }
        }
        
        return ans;
    }
}