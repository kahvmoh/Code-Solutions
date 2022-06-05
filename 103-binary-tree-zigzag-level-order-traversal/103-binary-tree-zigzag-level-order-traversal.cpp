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
private:
    void reverseVector(vector<int> &v)
    {
        for(int l = 0, r = v.size() - 1; l < r; l++, r--)
        {
            swap(v[l], v[r]);
        }    
    }    
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        
        vector<vector<int>> result;
        std::queue<TreeNode *> q;
        
        q.push(root);
        bool l2r = false;
        
        while (q.empty() == false) {
            int lSize = q.size();
            vector<int> thisLevel(0, lSize);

            for( int i = 0; i < lSize; i++)
            {
                TreeNode *tmp = q.front();
                q.pop();
                thisLevel.push_back(tmp->val);
                
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);    
            }
            
            if(l2r)
                reverseVector(thisLevel);
            l2r = !l2r;
            result.push_back(thisLevel);
        }
        
        return result;
    }
};