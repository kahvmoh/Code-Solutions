class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> hmap;
        int pSum = 0;
        int total = 0;
        hmap[0] = 1;
        
        for(int i = 0; i < nums.size(); i++) {
            pSum = pSum + nums[i];
            int rem = pSum % k;
            if( rem < 0 )
                rem += k;
            // Is there any pSum with the same reminder?   
            if( hmap.find(rem) != hmap.end() )
                total += hmap[rem];
            
            // Update the hash maap table
            if( hmap.find(rem) != hmap.end() )
                hmap[rem] += 1;
            else
                hmap[rem] = 1;
        }
                     
        return total;
    }
};