class Solution {
public:
    int reverse(int x) {
        int result = 0;
        
        while ( x != 0 )
        {
            int rem = x % 10;
            x /= 10;
           
            if( ( result > INT_MAX / 10 ) || ( result == INT_MAX / 10 && rem > 7 ) )
                 return 0;
            else if( ( result < INT_MIN / 10) || ( result == INT_MIN / 10 && rem < -8 ) )
                 return 0;
            else
                result = 10 * result + rem;
        }   
        
        return result;
    }
};