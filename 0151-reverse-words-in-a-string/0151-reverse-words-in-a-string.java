class Solution {
    public String reverseWords(String s) {
        String[] ch = s.split(" ");
        int n = ch.length;
        StringBuilder str = new StringBuilder();
        int k = 0;
        while(ch[k].equals("")) k++;
        for(int i=n-1; i>k; i--) {
            if(ch[i].equals("")) continue;
            str.append(ch[i] + " ");
        }
        
        str.append(ch[k]);
        
        return str.toString();
    }
}