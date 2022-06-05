/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return root;

        std::queue<Node *> myQ;
    
        myQ.push(root);
        root->next = NULL;

        while (myQ.empty() != true)
        {
            int qSize = myQ.size();
            Node *prev = NULL;

            for(int i = 0; i < qSize; i++) {
                Node *cur = myQ.front();
                myQ.pop();

                if(cur->left)
                    myQ.push(cur->left);
                
                if(cur->right)
                    myQ.push(cur->right);
                if( prev )
                    prev->next = cur;
                prev = cur;
            }
        }

        return root;
 
    }
};