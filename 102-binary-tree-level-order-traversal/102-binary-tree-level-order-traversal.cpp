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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        
        std::queue<TreeNode *> myQ;
        vector<vector<int>> result;
        
        myQ.push(root);
        
        while (myQ.empty() != true)
        {
            int qSize = myQ.size();
            
            vector<int> mLevel(0, qSize);
            
            for(int i = 0; i < qSize; i++) {
                TreeNode *tmp = myQ.front();
                myQ.pop();
                mLevel.push_back(tmp->val);
            
                if(tmp->left)
                    myQ.push(tmp->left);
                if(tmp->right)
                    myQ.push(tmp->right);
            }
            
            result.push_back(mLevel);
        }
        
        return result;
            
    }
};