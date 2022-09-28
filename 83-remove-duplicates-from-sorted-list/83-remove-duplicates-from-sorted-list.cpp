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
         ListNode *sentinel = new ListNode(INT_MIN, head);
         ListNode *cur = head;
         ListNode *prev = sentinel;
        
        while ( cur ) {
            if (cur->val == prev->val) {
                ListNode *tmp = cur;
                prev->next = cur->next;
                cur = cur->next;
                delete tmp;
            }
            else {
                prev = cur;
                cur = cur->next;
            }
        }
        
        head = sentinel->next;
        delete sentinel;
        return head;
    }
    
};
