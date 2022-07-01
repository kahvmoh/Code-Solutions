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
        
        while( cur ) {
            if( cur->next && cur->val == cur->next->val ) {
                ListNode *p = cur->next;
                int dupVal = cur->val;
                delete cur;
                while( p && p->val == dupVal) {
                    ListNode *temp = p;
                    p = p->next;
                    delete temp;
                }    
                prev->next = p;
                cur = p;
            }
            else {
                prev = cur;
                cur = cur->next;
            }
        }
        
        head = sentinal->next;
        delete sentinal;
        return head;
    }
};