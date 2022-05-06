class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        for( int i = 0; i < n; i++ ) {
            while (nums[i] != i) {
                int d = nums[i];
                if( nums[i] != nums[d] )
                    swap(nums[i], nums[d]);
                else
                    break;
            }
        }
    
        for( int i = 0; i < n; i++)  {
            if (nums[i] != i)
                return nums[i];
        }
        
        return n;
    
    }
};