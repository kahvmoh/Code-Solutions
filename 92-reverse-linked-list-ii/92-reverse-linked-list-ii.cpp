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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *sentinal = new ListNode(INT_MIN, head);
        ListNode *prev = sentinal;
        ListNode *cur = head;
        int index = 1;
        while( index < left ) {
            prev = cur;
            cur = cur->next;
            index++;
        }
        ListNode *left_tail = prev;
        ListNode *middle_tail = cur;
        
        prev = NULL;
        ListNode  *succ;
        
        while( index < right + 1) {
            succ = cur->next;
            cur->next = prev;
            prev = cur;
            cur = succ;
            index++;
        }
        
        ListNode *middle_head = prev;
        ListNode *right_head = cur;
        
        left_tail->next = middle_head;
        middle_tail->next = right_head;
        
        return sentinal->next;    
    }
};