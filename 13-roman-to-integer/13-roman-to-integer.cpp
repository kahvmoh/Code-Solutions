class Solution {
public:
        int romanToInt(string s) {
            
            int sum = 0;
            
            for (int i = 0; i < s.size(); i++) 
            {            
               if( i == s.size() - 1 || romanVal(s[i]) >= romanVal(s[i+1]))
                   sum += romanVal(s[i]);
               else
               {    
                  sum += romanVal(s[i+1]) - romanVal(s[i]);
                  ++i;
               }
            }
            
            return sum;
        }

        int romanVal(char c) {
            
            switch(c) {
                case 'I': 
                    return 1;
                case 'V':
                    return 5;
                case 'X': 
                    return 10;
                case 'L':
                    return 50;
                case 'C':
                    return 100;
                case 'D':
                    return 500;
                case 'M':
                    return 1000;
            }
            
            return -1;
        }
};