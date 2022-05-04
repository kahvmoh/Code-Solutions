
#include<limits.h>

class Solution {
public:
    int myAtoi(string s) {
        
        int size = s.size();
        int pos = 0;
        int sign = 1;
        int result = 0;
        
        while( pos < size && s[pos] == ' ')
           ++pos;
        
        
        if( pos < size && ( s[pos] == '-' || s[pos] == '+') )
        {    
            sign = (s[pos] == '-') ? -1 : 1;
            ++pos;
        }

        
        while( ( pos < size ) && ( s[pos] >= '0' && s[pos] <= '9' ) )
        {               
                int x = s[pos] - '0';
                               
                if( ( result > INT_MAX / 10 ) || 
                    ( result == INT_MAX / 10 && x > INT_MAX % 10  ) )                    
                    return sign == 1 ? INT_MAX : INT_MIN;
                
                result = result * 10 + x;                
                ++pos;
        }    
             
        return result * sign;
        
    }
};