class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        if (nums.size() < 2)
            return false;
        
        if ( k == 0) {
            for (int  i = 1; i < nums.size(); i++) {
                if ( (nums[i-1] == 0) && (nums[i] == 0))
                    return true;
            }
            
            return false;
        }
        
        unordered_map<int, bool> hmap;
        hmap[0] = true;
        
        int pSum = nums[0];
        for ( int i = 1; i < nums.size(); i++) {
            int oldSum = pSum;
            pSum = (pSum + nums[i]) % k;
            
            if (hmap.find(pSum) != hmap.end())
                return true;
            
            hmap[oldSum % k] = true;
        }
        
        return false;
    }
};