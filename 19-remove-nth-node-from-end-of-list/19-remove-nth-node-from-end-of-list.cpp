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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *sentinal = new ListNode(INT_MIN, head);
        ListNode *leader = head;
        ListNode *cur = head;
        ListNode *prev = sentinal;
        
        for( int i = 0; i < n; i++)
            leader = leader->next;
        while( leader ) {
            leader = leader->next;
            prev = cur;
            cur = cur->next;
        }
        
        prev->next = cur->next;
        head = sentinal->next;
        return head;
    }
};