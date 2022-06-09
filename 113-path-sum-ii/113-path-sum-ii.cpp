/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode *node, int targetSum, vector<int> &slate, vector<vector<int>> &result) 
    {
        targetSum -= node->val;
        slate.push_back(node->val);
        
        if( (node->left == NULL) && (node->right == NULL) && (targetSum == 0))
        {
            result.push_back(slate);
        } 
        
        if(node->left)
            helper(node->left, targetSum, slate, result);
        if(node->right)
            helper(node->right, targetSum, slate, result);
        
        slate.pop_back();
    
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if( !root )
            return {};      
        
        vector<vector<int>> result;
        vector<int> slate;
        helper(root, targetSum, slate, result);

        return result;
    }
};