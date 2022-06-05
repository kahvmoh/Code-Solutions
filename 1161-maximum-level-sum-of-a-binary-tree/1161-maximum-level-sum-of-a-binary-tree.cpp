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
    int maxLevelSum(TreeNode* root) {
        if ( !root )
            return -1;
        std::queue<TreeNode *> treeQ;
        treeQ.push(root);
        int minLevel = 0;
        int level = 0;
        int maxSum = INT_MIN;
        while (treeQ.empty() == false) {
            int levelSize = treeQ.size();
            int levelSum = 0;
            level += 1;
            std::cout << "leve = " << level << std::endl;
            for( int i = 0; i < levelSize; i++) {
                TreeNode *tmpNode = treeQ.front();
                treeQ.pop();
                if (tmpNode->left)
                    treeQ.push(tmpNode->left);
                if (tmpNode->right)
                    treeQ.push(tmpNode->right);
                
                levelSum += tmpNode->val;
            }
            if (levelSum > maxSum) {
                maxSum = levelSum;
                minLevel = level;
            }    
        }
        
        return minLevel;
    }
};