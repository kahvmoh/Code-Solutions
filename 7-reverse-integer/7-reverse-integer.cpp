class Solution {
public:
    int reverse(int x) {
        int forward = abs(x);
        int reversed = 0;
        
        if( x == (1u << 31))
            return 0;
        
        while ( forward != 0 )
        {
            int rem = forward % 10;
            forward /= 10;
           
            if( ( reversed > numeric_limits<int>::max() / 10 ) || ( reversed == numeric_limits<int>::max() / 10 && rem > 7 ) )
                 return 0;

            else
                reversed = 10 * reversed + rem;
        }   
        
        if ( x < 0)
            reversed *= -1;
        
        return reversed;
    }
};