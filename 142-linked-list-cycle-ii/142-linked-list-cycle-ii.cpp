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
        if (!head)
            return nullptr;
        
        ListNode *fast = head;
        ListNode *slow = head;
        
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            
            if (slow == fast) {
                ListNode *third = head;
                while (slow != third) {
                    slow = slow->next;
                    third = third->next;
                }
                return third;
            }
        }
        
        return nullptr;
    }
        
};