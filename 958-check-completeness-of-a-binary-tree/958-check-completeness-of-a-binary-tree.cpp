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
    bool isCompleteTree(TreeNode* root) {
        if ( root == nullptr)
            return true;
        
        std::queue<pair<TreeNode *, long long>>  q;
        
        q.push( pair<TreeNode *, long long>(root, 1));
        
        int expectedId = 1;
        
        while( !q.empty() ) {
            int lSize = q.size();
            
            for( int i = 0; i < lSize; i++) 
            {
                pair<TreeNode *, long long> p = q.front();
                q.pop();
                
                if( expectedId == p.second )
                    expectedId += 1;
                else
                    return false;
                
                if( p.first->left )
                    q.push( pair<TreeNode *, long long>(p.first->left, p.second * 2));
                
                if( p.first->right )
                    q.push( pair<TreeNode *, long long>(p.first->right, p.second * 2 + 1)); 
            }
        }
        
        return true;
    }
};