class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        
        for( int i = 0; i < n; i++)  {
            while ( nums[i] != i+1 ) {
                int d = nums[i] - 1;
                if( nums[i] != nums[d] )
                    swap(nums[i], nums[d]);
                else
                    break;
            }
        }
        
        for( int i = 0; i < n; i++) {
            if (nums[i] != i+1) {
                result.push_back(nums[i]);
                result.push_back(i+1);
                break;
            }
        }
        
        return result;
    }
};