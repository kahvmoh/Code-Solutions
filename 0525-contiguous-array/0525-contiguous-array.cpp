class Solution {
public:
    int findMaxLength(vector<int>& nums) {
      
        int pSum = 0;
        int gMax = 0;
        
        unordered_map<int, int> hmap;
        hmap[0] = 0;
        
        for( int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                pSum += 1;
            else
                pSum -= 1;
        
            // find the maximum array size of we have a sub array of 
            // unequal 0's and 1's with minimum size
            if (hmap.find(pSum) != hmap.end()) {
                gMax = std::max(gMax, ((i+1) - hmap[pSum]) );
            }
        
            // Add pSum for the current index if it does not already exist in hmap
            if (hmap.find(pSum) == hmap.end()) {
                hmap[pSum] = i + 1;
            }
        } 
        
        return gMax;
    }
};