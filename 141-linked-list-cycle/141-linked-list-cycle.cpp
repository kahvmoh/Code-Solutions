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
    bool hasCycle(ListNode *head) {
        
        if (!head)
            return false;
        
        ListNode *slow = head, *fast = nullptr;
        if(slow && slow->next) {
            fast = slow->next->next;
        }
        
        while (slow != fast) {
            slow = slow->next;
            if (fast && fast->next) {
                fast = fast->next->next;
            }
            else
            {
                return false;
            }        
        }
        
        return true;
    }
};