class Solution {
    public int helper(String s, int left, int right) {
        while(left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }
        return right - left - 1;
    }
    public String longestPalindrome(String s) {
        int n = s.length();
        int ans = 1;
        int start = 0;
        for(int i=0; i<n-1; i++) {
            int len1 = helper(s, i, i);
            int len2 = helper(s, i, i + 1);
            int len = (len1 > len2) ? len1 : len2;
            
            if(len > ans) {
                ans = len;
                start = i - (ans - 1) / 2;
            }
        }
        
        return s.substring(start, start + ans);
    }
}