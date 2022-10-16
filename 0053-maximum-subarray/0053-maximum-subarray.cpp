class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int globalMax = nums[0];
        int prevAns   = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            prevAns = max(prevAns + nums[i], nums[i]);
            globalMax = max(globalMax, prevAns);
        }
        
        return globalMax;
    }
};