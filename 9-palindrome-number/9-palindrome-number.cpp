class Solution {
public:
    bool isPalindrome(int x) {
      
        if (x < 0)
          return false;
        
        int forward = x;
        int reversed = 0;
        while (forward > 0) {
           if ( (reversed > INT_MAX / 10) ||
                ( (reversed == INT_MAX / 10) && ((reversed * 10) > (INT_MAX - (forward % 10)) ) ) )
                 return false;
           reversed = (reversed * 10) + (forward % 10);
           forward /= 10;      
        }
                 
        return (x == reversed);
    }
};