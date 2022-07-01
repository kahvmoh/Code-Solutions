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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode *sentinal = new ListNode(INT_MIN, head);
        ListNode *cur = head;
        ListNode *prev = sentinal;
        
        while( cur ) {
            for( int i = 0; i < m && cur; i++) {
                prev = cur;
                cur = cur->next;
            }
            
            for ( int i = 0; i < n && cur; i++) {
                ListNode *temp = cur;
                cur = cur->next;
                delete temp;
            }    
            prev->next = cur;
        }
        
        head = sentinal->next;
        return head;
    
    }
};