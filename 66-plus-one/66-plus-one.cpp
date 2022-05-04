class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int carry = 1;
        bool added = false;
        for( int i = digits.size() - 1; i >= 0; i--)
        {
            if( digits[i] + carry < 9 )
            {
                digits[i] += carry;
                carry = 0; 
                break;
            }    
            else
            {
                digits[i] += carry;   
                carry = digits[i] / 10;
                digits[i] %= 10;
            }    
        }
        
       if(carry > 0)
           digits.insert(digits.begin(), carry);
            
        
        return digits;
    }
};