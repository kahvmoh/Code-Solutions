class Solution {
    
    public:
    uint32_t reverseBits(uint32_t n) {

        uint32_t result = 0;
        
        for (uint8_t i = 0; i < 31; i++)
        {
            uint32_t temp = n % 2;
            n = n >> 1;
            result += temp;
            result = result << 1;
        }

        result += n;
        return result;
    }
};