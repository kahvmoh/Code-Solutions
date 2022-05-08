/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if ( !head )
            return nullptr;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while ( fast->next && fast->next->next ) {
            slow = slow->next;
            fast = fast->next->next;
            
            if( fast == slow ) {
                //cycle detected
                //find starting node of the cycle
                ListNode *third = head;
                while ( slow != third ) {
                    slow = slow->next;
                    third = third->next;
                }
                return slow;
            }    
        }
        
        return nullptr;
    }
};