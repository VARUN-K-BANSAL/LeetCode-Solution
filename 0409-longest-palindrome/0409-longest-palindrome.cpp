class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        int a[26] = {0} , b[26] = {0};
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(s[i] >= 97) {
                a[s[i] - 97]++;
            } else b[s[i] - 65]++;
        }
        for(int i=0; i<26; i++) {
            if(a[i] >= 2) {
                ans += a[i] / 2;
                a[i] = a[i] % 2;
            }
            if(b[i] >= 2) {
                ans += b[i] / 2;
                b[i] = b[i] % 2;
            }
        }
        
        ans = ans*2;
        for(int i=0; i<26; i++) {
            if(a[i] > 0 || b[i] > 0) {
                ans++;
                break;
            }
        }
        return ans;
    }
};