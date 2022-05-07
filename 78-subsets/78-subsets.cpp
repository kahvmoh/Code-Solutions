class Solution {
    private:
       void helper(vector<int> &nums, int idx, vector<int>& sofar, vector<vector<int>>& results)
       {
           if(idx == nums.size())
           {
               results.push_back(sofar);
               return;
           }
           else
           {
               // exclude the current element
               helper(nums, idx+1, sofar, results);
               
               // include the current element
               sofar.push_back(nums[idx]);
               helper(nums, idx+1, sofar, results);
               sofar.pop_back();
           }    
           
       }    
    public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> sofar;
        helper(nums, 0, sofar, results);
        
        return results;
        
    }
};