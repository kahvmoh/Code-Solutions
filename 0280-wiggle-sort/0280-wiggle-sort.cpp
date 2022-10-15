class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        //sort(nums.begin(), nums.end());
        //int n = nums.size();
        
        for(int i = 1; i < nums.size(); i++) {
            if ( ((i % 2 == 0) && (nums[i-1] < nums[i])) ||
                 ((i % 2 == 1) && (nums[i-1] > nums[i]))
                )
            swap(nums[i-1], nums[i]);
        }   
    }
};