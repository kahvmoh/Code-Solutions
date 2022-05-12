class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double winSum = 0;
        double maxWinAvg = 0;
        
        for( int i = 0; i < k; i++)
            winSum += nums[i];
        
        maxWinAvg = winSum / k;
        
        for( int i = k; i < nums.size(); i++) {
            winSum = winSum + nums[i] - nums[i - k];
            maxWinAvg = max(maxWinAvg, winSum / k);
        }
        
        return maxWinAvg;
    }
};