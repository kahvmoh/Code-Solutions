class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
               
        vector<vector<int>> res;
        
        //sort the array first
        sort(nums.begin(), nums.end()); 
        
        for( int i = 0; i < nums.size() && nums[i] <= 0; i++)
        {
            if( i == 0 || nums[i-1] != nums[i])
            {
                twoSumsII( nums, i, 0, res);
            }    
        }
        
        return res;
    }
    
    
    void twoSumsII( vector<int> &nums, int i, int target, vector<vector<int>> &res)
    {
        int low = i + 1;
        int high = nums.size() - 1;
        
        while( low < high )
        {
            int sum = nums[i] + nums[low] + nums[high];
            if( sum < target )
                ++low;
            else if( sum > target )
                --high;
            else
            {
                res.push_back( { nums[i], nums[low++], nums[high--] } );
                while( low < high && nums[low] == nums[low -1])
                    ++low;
            }    
        }    
        
    }    
};