/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *sentinalS = new ListNode(INT_MIN, NULL);
        ListNode *tailS = sentinalS;
        ListNode *sentinalL = new ListNode(INT_MIN, NULL);
        ListNode *tailL = sentinalL;
        
        ListNode *succ = NULL;
        ListNode *cur = head;
        
        while( cur ) {
            succ = cur->next;
            cur->next = NULL;
            
            if( cur->val < x ) {
                tailS->next = cur;
                tailS = cur;
            }
            else {
                tailL->next = cur;
                tailL = cur;
            }
            
            cur = succ;
        }
        tailS->next = sentinalL->next;
        
        return sentinalS->next;
    }
};