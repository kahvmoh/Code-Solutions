/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        
        // Eleminate non-celebrities
        int sur = 0;
        for (int i = 1; i < n; i++) {
            if (knows(sur, i))
                sur = i;
        }
        
        // Verify if sur is a celebrity
        for (int i = 0; i < n; i++) {
            if( (sur != i) && ( (knows(sur, i)) || (!knows(i, sur)) ))
                return -1;
        }
        
        return sur;
    }
};