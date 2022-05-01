class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;     
        unordered_multimap<int, int> myMap;
        
        for(int i = 0; i < nums.size(); i++)
        {
            int rem = target - nums[i];
            
            unordered_multimap<int, int>::iterator it = myMap.find(rem);
            
            if((it != myMap.end()) && (it->second != i))
            {
                result.push_back(i);
                result.push_back(it->second);
                return result;
            } 
            myMap.insert( std::pair<int, int>(nums[i], i));
        }
        
        return result;       
    }
};