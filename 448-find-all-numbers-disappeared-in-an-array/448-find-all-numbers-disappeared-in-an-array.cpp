class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        
        // sort the array
        for( int i = 0; i < n; i++) {
           while (nums[i] != i+1) {
               int d = nums[i] - 1;
               if( nums[i] != nums[d])
                   swap(nums[i], nums[d]);
               else
                   break;
           } 
        }
        
        //look for missing nums
        for( int i = 0; i < n; i++) {
            if ( nums[i] != i+1 )
                result.push_back(i+1);
        }    
        
        return result;
    }
};