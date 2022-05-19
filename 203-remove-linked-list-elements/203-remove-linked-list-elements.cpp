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
    ListNode* removeElements(ListNode* head, int val) {
       ListNode *sentinal = new ListNode(INT_MIN, head);
       ListNode *prev = sentinal;
       ListNode *cur = head;
       while( cur ) {
           if( cur->val == val ) {
               prev->next = cur->next;
               cur = cur->next;
           }
           else {
               prev = cur;
               cur = cur->next;
           }
       } 
        head = sentinal->next;
        return head;
    }
};