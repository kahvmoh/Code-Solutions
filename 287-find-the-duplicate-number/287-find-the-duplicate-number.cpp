class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        for( int i = 0; i < n; i++ ) {
            while (nums[i] != i + 1) {
                int d = nums[i] - 1;
                if( nums[i] != nums[d] )
                    swap(nums[i], nums[d]);
                else
                    break;
            }
        }
    
        for( int i = 0; i < n; i++)  {
            if( nums[i] != i + 1)
                return nums[i];
        }
        
        return n;
    
    }
};