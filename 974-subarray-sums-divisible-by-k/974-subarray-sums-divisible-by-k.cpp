class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> hmap;
        int pSum = 0;
        int total = 0;
        hmap[0] = 1;
        
        for(int i = 0; i < nums.size(); i++) {
            pSum = (pSum + nums[i]) % k;

            if( pSum < 0 )
                pSum += k;
            
            if( hmap.find(pSum) != hmap.end() )
                total += hmap[pSum];
            
            // Update the hash maap table
            if( hmap.find(pSum) != hmap.end() )
                hmap[pSum] += 1;
            else
                hmap[pSum] = 1;

        }
                     
        return total;
    }
};