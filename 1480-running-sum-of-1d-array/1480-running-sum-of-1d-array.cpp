class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        vector<int> result(nums.size());
        
        if(nums.empty())
            return result;
        
        for( int i = 0; i < nums.size(); i++)
        {
            //int sum = 0;
            for(int j = i; j >= 0; j--)
            {    
                result[i] += nums[j];
            }    
        }    
        
        return result;
    }
};