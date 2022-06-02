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
    bool isPalindrome(ListNode* head) {
        if( !head || !head->next )
            return true;
        
        ListNode *slow = head;
        ListNode *fast = head;
        while( fast->next && fast->next->next ) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode *cur = slow->next;
        slow->next = NULL;
        ListNode *succ = NULL, *pred = NULL;
        
        // Reverse the list
        while( cur ) {
            succ = cur->next;
            cur->next = pred;
            pred = cur;
            cur = succ;
        }
        
        // pred is the head of the new list
        ListNode *left = head;
        bool result = true;
        cur = pred;
        pred = NULL;
        
        while( cur ) {
            if( left->val != cur->val )
                result = false;
            left = left->next;
            succ = cur->next;
            cur->next = pred;
            pred = cur;
            cur = succ;
        }
        
        slow->next = pred;
        return result;
    }
};