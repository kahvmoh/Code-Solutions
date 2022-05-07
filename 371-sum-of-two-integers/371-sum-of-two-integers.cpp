class Solution {
public:
    int getSum(int a, int b) {
       
        unsigned int carry = 0;
        int sum = a;
        
        while(b)
        {
            carry = sum & b;
            sum = sum ^ b;
             b = carry << 1;
            
        }
        
        return sum;
        
    }
};