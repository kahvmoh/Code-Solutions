class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double winSum = 0;
        double maxSum = 0;
        
        for( int i = 0; i < k; i++)
            winSum += nums[i];
        
        maxSum = winSum;
        
        for( int i = k; i < nums.size(); i++) {
            winSum = winSum + nums[i] - nums[i - k];
            maxSum = max(maxSum, winSum);
        }
        
        return maxSum / k;
    }
};