class Solution {
public:
    
    void helper( int i, int n, int k, vector<int> &blk, vector<vector<int>> &result)
    {
        // base case
        if( blk.size() == k ) {
            result.push_back(blk);
            return;
        }
        
        if( i > n )
            return;
        
        // exclude
        helper(i+1, n, k, blk, result);
            
        // include path
        blk.push_back(i);
        helper(i+1, n, k, blk, result);
        blk.pop_back(); 
    }
    
    vector<vector<int>> combine(int n, int k) {
        if( n == 0  || k == 0)
            return {};
        
        vector<vector<int>> result;
        vector<int> blk;
        
        helper(1, n, k, blk, result);
        
        return result;
        
    }
};