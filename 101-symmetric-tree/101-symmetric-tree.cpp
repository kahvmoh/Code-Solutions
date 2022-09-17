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
    bool isSymmetric(TreeNode* root) {
        if( !root )
            return true;
        
        
        std::queue<TreeNode *> qL;
        std::queue<TreeNode *> qR;
        qL.push(root);
        qR.push(root);
        
        while (!qL.empty()) {
            int qSize = qL.size();
            
            for( int i = 0; i < qSize; i++) {
                TreeNode *nodeL = qL.front();
                qL.pop();
                TreeNode *nodeR = qR.front();
                qR.pop();
                
                if( nodeL->left && nodeR->right ) {
                    qL.push(nodeL->left);
                    qR.push(nodeR->right);
                }
                else if (nodeL->left || nodeR->right)
                    return false;
                
                if (nodeL->right && nodeR->left ) {
                    qL.push(nodeL->right);
                    qR.push(nodeR->left);
                }
                else if (nodeL->right || nodeR->left)
                    return false;
                
                if (nodeL->val != nodeR->val)
                    return false;
            }
        }
        
        return true;
    }
};