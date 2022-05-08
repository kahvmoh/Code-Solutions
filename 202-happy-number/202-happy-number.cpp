class Solution {
public:
    int fun( int x )
    {
        int total = 0;
        while( x != 0 ) {
            total += ( x % 10 ) * ( x % 10 );
            x = x / 10;    
        }
            
        return total;
    }
        
    bool isHappy(int n) {
       int slow = n;
       int fast = n;
       while ( 1 ) {
           slow = fun( slow );
           fast = fun( fun ( fast ) ) ;
           if( slow == fast ) {
               return (fast == 1);
           }
      } 
    }
};