class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int xorAll = 0;
        unsigned int mask = 0;
        vector<int> result(2, -1);
        
        if (nums.size() < 2)
            return result;
        
        for (int i = 0; i < nums.size(); i++)
        {
            xorAll ^= nums[i];
        }
        
        //get the right most bit that is set
        mask = xorAll & -xorAll; //~(xorAll - 1);
        
        int num1 = 0, num2 = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if(mask & nums[i])
            {
                num1 ^= nums[i];
            }  
        }
        
        num2 = num1 ^ xorAll;
        
        result[0] = num1;
        result[1] = num2;
        
        return result;
    }
};