class Solution {
public:
    int findComplement(int num) {
         
        int tmp = num;
        int mask = 0;

        while( tmp != 0 ) {
            tmp = tmp >> 1;
            mask <<= 1;
            mask |= 1; 
        }

        return num ^ mask;
    }
};