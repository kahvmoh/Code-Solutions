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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *sentinal = new ListNode(INT_MIN, head);
        ListNode *prev = sentinal;
        ListNode *cur = head;
        
        while ( cur )  {
            if(prev->val == cur->val) {
                // delete  the next dup
                prev->next = cur->next;
                ListNode *temp = cur;
                cur = cur->next;
                delete temp;
            }
            else {
                // move to the next node
                prev = cur; 
                cur  = cur->next;
            }
        }
        
        head = sentinal->next;
        delete sentinal;
        return head;
    }
};