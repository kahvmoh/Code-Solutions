class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();    
        for( int i = 0; i < n; i++ )  {
            while((nums[i] > 0) &&
                  (nums[i] - 1 < n ) &&
                  (nums[i] != i + 1) &&
                  (nums[i] != nums[nums[i] - 1] ) ) {
                int d = nums[i] - 1;
                swap(nums[i], nums[d]); 
            }
        }
        
        for( int i = 0; i < n; i++) {
            if( nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        return n + 1;
    }
};