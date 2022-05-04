/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if( !head )
           return nullptr;
        
        unordered_map<Node *, Node *> ht;
        Node *cur = head;
        
        while(cur)
        {
            ht[cur]= new Node(cur->val);
            cur = cur->next;
        }
        
        Node *oldNode, *newNode;
        for(auto it = ht.begin(); it != ht.end(); it++)
        {
            oldNode = (*it).first;
            newNode = (*it).second;
            if(oldNode->next)
                newNode->next = ht[oldNode->next];
            if(oldNode->random)
                newNode->random = ht[oldNode->random];
        }
        
        return ht[head];
        
        }    
        
};