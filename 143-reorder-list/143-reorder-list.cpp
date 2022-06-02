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
    void reorderList(ListNode* head) {
      if( !head || !head->next )
          return;
        
      // split the list into two halves  
      ListNode *slow = head;
      ListNode *fast = head;   
      while( fast->next && fast->next->next ) {
          fast = fast->next->next;
          slow = slow->next;
      }
    
      ListNode *cur = slow->next;
      slow->next = NULL;
      
      ListNode *pred = NULL, *succ = NULL;
      // reverse the second half
      while ( cur ) {
          succ = cur->next;
          cur->next = pred;
          pred = cur;
          cur = succ;
      }
      
      ListNode *l1 = head;
      ListNode *l2 = pred;
      ListNode *sentinal = new ListNode(0, NULL);
      ListNode *tail  = sentinal;
        
      while ( l1 && l2 ) {
          tail->next = l1;
          tail = l1;
          l1 = l1->next;
          tail->next = NULL;
          
          tail->next = l2;
          tail = l2;
          l2 = l2->next;
          tail->next = NULL;
      }
        
      tail->next = l1;
        
    }
};