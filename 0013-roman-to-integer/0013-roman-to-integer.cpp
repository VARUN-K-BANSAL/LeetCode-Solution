class Solution {
public:
    int value(char r)
        {
            if (r == 'I')
                return 1;
            if (r == 'V')
                return 5;
            if (r == 'X')
                return 10;
            if (r == 'L')
                return 50;
            if (r == 'C')
                return 100;
            if (r == 'D')
                return 500;
            if (r == 'M')
                return 1000;
            return 0;
        }
    
    int romanToInt(string s) {
        int numerals=0;
        for(int i=0;i<s.length();i++){
            int a=value(s[i]),b;
            if(i <= (s.length()-1)){
                b=value(s[i+1]);
            if(a<b){
                numerals+=(b-a);
                i++;
            }
            else{
                numerals+=a;
            }
            }
            else{
                numerals+=a;
            }
        }
        return numerals;
    }
};