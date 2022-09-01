/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (!root)
            return 0;
        int level = 0;
        std::queue<Node *> q;
        q.push(root);
        
        while(q.empty() == false) {
            level++;
            int numNode = q.size();
            for(int i = 0; i < numNode; i++) {
                Node *tmpNode = q.front();
                q.pop();
                for( int j = 0; j < tmpNode->children.size(); j++)
                     q.push(tmpNode->children[j]);
            }  
        }
        return level;
    }
};