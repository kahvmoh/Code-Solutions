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
    int diameter = 0;
    
    int diameter_dfs(TreeNode *node)
    {
        if ( !node )
            return 0;
        
        int height = 0;
        int leftHeight = 0;
        int rightHeight = 0;
        int longPath = 0;
        
        if ( node->left ) {
            leftHeight = 1 + diameter_dfs( node->left );
            longPath = leftHeight;
            height = leftHeight;
        }
        if ( node->right ) {
            rightHeight = 1 + diameter_dfs( node->right );
            longPath += rightHeight;
            height = max(leftHeight, rightHeight);
        }
        
        if(longPath > diameter)
            diameter = longPath;
        return height;
    } 
    
    int diameterOfBinaryTree(TreeNode* root) {
        diameter_dfs( root );
        
        return diameter;
        
    }
};