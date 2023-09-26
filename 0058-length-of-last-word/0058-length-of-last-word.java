class Solution {
    public int lengthOfLastWord(String s) {
        String[] ch = s.split(" ");
        int n = ch.length;
        int ans = 0;
        int i = n - 1;
        while(ch[i].length() == 0) i--;
        return ch[i].length();
    }
}