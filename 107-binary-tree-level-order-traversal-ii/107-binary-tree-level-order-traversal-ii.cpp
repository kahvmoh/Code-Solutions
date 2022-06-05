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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        if ( !root )
            return {};
        
        std::vector<vector<int>> result;
        std::stack<vector<int>> stackRes;
        std::queue<TreeNode *> q;
        q.push( root );
        
        while ( q.empty() == false ) {
            int lSize = q.size();
            std::vector<int> thisLevel(0, lSize);

            
            for ( int i = 0; i < lSize; i++ ) {
                TreeNode *tmp = q.front();
                q.pop();
                thisLevel.push_back( tmp->val );
                if(tmp->left)
                    q.push( tmp->left );
                if(tmp->right)
                    q.push( tmp->right );
            }
            
            stackRes.push( thisLevel );
        }
        
        while(stackRes.empty() == false) {
            result.push_back(stackRes.top());
            stackRes.pop();
        }
        
        return result;
    }
};;