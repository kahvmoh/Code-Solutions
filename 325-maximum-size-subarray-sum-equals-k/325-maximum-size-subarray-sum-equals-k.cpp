class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int globalMax = 0;
        int pSum = 0;
        unordered_map<int, int> hmap;
        
        hmap[0] = 0;
        for( int i = 0; i < nums.size(); i++)  {
            // calculate prefixSum
            pSum += nums[i];
            // find the shortest array with pSum = pSum - k
            if(hmap.find(pSum - k) != hmap.end()) 
                globalMax = max(globalMax, (i+1 - hmap[pSum - k]) );
            
            // update the hashmap
            if(hmap.find(pSum) == hmap.end())
                hmap[pSum] = i + 1;
        }
        
        return globalMax;
    }
};