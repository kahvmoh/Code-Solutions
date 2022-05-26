class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int winSum = 0;
      int globalAns = INT_MAX;
      int left = 0;
        
      for( int i = 0; i < nums.size(); i++ ) {
          winSum += nums[i];
          while ( left <= i && winSum >= target) {
             winSum -= nums[left];
             globalAns = min(globalAns, i - left + 1);
             left++;
          }    
      }
      
     if(globalAns == INT_MAX )
         return 0;
        
      return globalAns;
    }
};