class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        for( int i = 0; i < n; i++ ) {
            while (nums[i] != i) {
                int d = nums[i];
                if (nums[i] < n)
                    swap( nums[i], nums[d]);
                else
                    break;
            }
        }
            
        for( int i = 0; i < n; i++ ) {
            if(nums[i] == n)
                return i;
        }
         
        return n;
    }
};