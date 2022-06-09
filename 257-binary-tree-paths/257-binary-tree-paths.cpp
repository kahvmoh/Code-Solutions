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
    void helper( TreeNode *node, string slate, vector<string> & res)
    {
        
        slate += to_string(node->val);

        if( !node->left && !node->right ) {
            res.push_back(slate);
        }
            
        if( node->left )
            helper( node->left, slate + "->", res);
        if( node->right )
            helper( node->right, slate + "->", res);

    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;

        if( !root )
            return {};
        
        helper(root, "", result);
        
        return result;
        
    }
};