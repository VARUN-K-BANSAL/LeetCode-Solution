class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length() - 1;
        while(i < j) {
            if(s[i] == 'a' ||
              s[i] == 'e' ||
              s[i] == 'o' ||
              s[i] == 'i' ||
              s[i] == 'u' ||
              s[i] == 'A' ||
              s[i] == 'E' ||
              s[i] == 'O' ||
              s[i] == 'I' ||
              s[i] == 'U') {
                if(s[j] == 'a' ||
              s[j] == 'e' ||
              s[j] == 'o' ||
              s[j] == 'i' ||
              s[j] == 'u' ||
              s[j] == 'A' ||
              s[j] == 'E' ||
              s[j] == 'O' ||
              s[j] == 'I' ||
              s[j] == 'U') {
                    char temp = s[j];
                    s[j] = s[i];
                    s[i] = temp;
                    i++;
                    j--;
                } else {
                    j--;
                }
            } else {
                i++;
            }
        }
        return s;
    }
};