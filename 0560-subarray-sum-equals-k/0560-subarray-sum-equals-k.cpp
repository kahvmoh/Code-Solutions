class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int tCount = 0;
        int pSum = 0;
        unordered_map<int, int> hmap;
        hmap[0] = 1;
        
        for( int i = 0; i < nums.size(); i++) {
            pSum += nums[i];
            
            // how many prefixes sum to prefixsum - k
            if( hmap.find(pSum - k) != hmap.end() )
                tCount += hmap[pSum - k];
            // Update hmap
            if ( hmap.find( pSum ) != hmap.end() )
                hmap[pSum]++;
            else
                hmap[pSum] = 1;
        }
        
        return tCount;
    }
};