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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if (depth == 1) {
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left = root;
            root = newRoot;
            return root;
        }
        
        std::queue<TreeNode *> myQ;
        myQ.push(root);
        int level = 0;
        
        while (myQ.size() != 0) {
            int lSize = myQ.size();
            level += 1;
            
            for( int i = 0; i < lSize; i++) {
                TreeNode *node = myQ.front();
                myQ.pop();
                
                if (node->left)
                    myQ.push(node->left);
                if (node->right)
                    myQ.push(node->right);
                
                if (level == depth - 1) {
                    TreeNode *newLeft = new TreeNode(val);
                    newLeft->left = node->left;
                    TreeNode *newRight = new TreeNode(val);
                    newRight->right = node->right;
                    
                    node->left = newLeft;
                    node->right = newRight;
                }
            }
        }
        
        return root;
        
    }
};