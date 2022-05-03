class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2, 0);
        unordered_multimap<int, int> hmap;
        
        for (int i =0; i < nums.size(); i++) {
            int secondNum = target - nums[i];
            
            unordered_multimap<int, int>::iterator it = hmap.find(secondNum);
            if( it != hmap.end() && it->second != i) {
                result[0] = i;
                result[1] = it->second;
                return result;
            }
            
            hmap.insert({nums[i], i});
        }
        return result;       
    }
};