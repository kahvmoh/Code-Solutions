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
#include <limits.h>

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if ( !root )
            return {};
        
        std::queue<TreeNode *> q;
        vector<int> result;
        
        q.push(root);
        while ( !q.empty() )  {
            int lSize = q.size();
            int lMax = INT_MIN;
            
            for (int i = 0; i < lSize; i++) {
                TreeNode *tmp = q.front();
                q.pop();
                
                if ( lMax < tmp->val )
                    lMax = tmp->val;
                
                if ( tmp->left )
                    q.push ( tmp->left );
                if ( tmp->right )
                    q.push( tmp->right );
            }         
            result.push_back(lMax);            
        }
        return result;     
    }
};