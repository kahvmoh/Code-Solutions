class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        if(nums.empty())
            return -1;
        
        int l = 0; 
        int r = nums.size() -1;
        int mid;
        while(l <= r)
        {
            mid = (l + r) / 2;
            if( nums[mid] == target)
                return mid;
            else if( nums[mid] < target)
            {    
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }          
        }    
            
        return l;
    }
};