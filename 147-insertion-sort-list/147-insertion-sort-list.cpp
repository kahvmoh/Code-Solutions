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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *sentinal = new ListNode(INT_MIN, NULL);
        ListNode *succ = NULL;
        ListNode *cur = head;
        
        while( cur ) {
            //remove the current node
            succ = cur->next;
            cur->next = NULL;
            
            // Find the irght place to insert the node
            ListNode *prev = sentinal;
            ListNode *cur2 = sentinal->next;
            while( cur2 && cur2->val < cur->val ) {
                prev = cur2;
                cur2 = cur2->next;
            }
            // insert the node
            prev->next = cur;
            cur->next = cur2;
            
            // move to the next node in the main list
            cur = succ;
        }
        
        return sentinal->next;
        
    }
};