class Solution {
    
    public:
    uint32_t reverseBits(uint32_t n) {

        uint32_t result = 0;
        for( uint8_t i = 0; i < 31; i++) {
            if( n & 0x1 )
                result += 1;
            n = n >> 1;
            result = result << 1;
        }
        if ( n )
           result += 1;
        return result;
    }
};