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
    bool isUnivalTree(TreeNode* root) {

        if (!root)
            return {};

        std::queue<TreeNode *> myQ;
        myQ.push(root);
        
        int rootVal = root->val;

        while (myQ.empty() != true)
        {
            TreeNode *node = myQ.front();
            myQ.pop();
            
            if( node->val != rootVal )
                return false;
            
            if(node->left)
                myQ.push(node->left);
            if(node->right)
                myQ.push(node->right);
        }

        return true;
    }
};