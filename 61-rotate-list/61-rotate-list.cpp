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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *sentinal = new ListNode(INT_MIN, NULL);
        ListNode *tail = sentinal;
        ListNode *cur = head;
        int len = 0;
        if( k == 0 || !head || !head->next )
            return head;
        
        while ( cur ) {
            tail = cur;
            cur = cur->next;
            len++;
        }
        
        int green = len - (k % len );
        if( green == len )
            return head;
        
        int i = 1;
        ListNode *prev = NULL;
        cur = head;
        
        while ( cur && i <= green) {
            prev = cur;
            cur = cur->next;
            i++;
        }
        
        prev->next = NULL;
        tail->next = head;
        sentinal->next = cur;
        
        return sentinal->next;
        
    }
};