/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        
        Node *myNode = new Node(insertVal, nullptr);
        
        // empty list
        if( !head ) {
            myNode->next = myNode;
            return myNode;
        }
        
        // list with one element
        if( head->next == head ) {
            head->next = myNode;
            myNode->next = head;
            return head;
        }
        
        // list with more than one element
        Node *prev = head;
        Node *cur = head->next;
        while (cur->val >= prev->val && cur != head) {
            prev = cur;
            cur = cur->next;
        }
        
        //insert between prev and cur since cur < prev
        if (insertVal > prev->val) {
            prev->next = myNode;
            myNode->next = cur;
            return head;
        }
        
        // insert somewhere in the middle of the list
        while ( insertVal > cur->val) {
            prev = cur;
            cur = cur->next;
        }
        
        prev->next = myNode;
        myNode->next = cur;
        
        return head;
    }
};