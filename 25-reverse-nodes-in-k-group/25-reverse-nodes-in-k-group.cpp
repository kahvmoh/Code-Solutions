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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *sentinal = new ListNode(INT_MIN, head);
        ListNode *cur = head, *pred = sentinal;
        
        while( cur ) {
           ListNode *m = cur;
           for( int i = 0; i < k; i++) {
               if( !m )
                   return sentinal->next;
               m = m->next;
           }
           
           // reverse the list from cur to m 
           ListNode *localPred = NULL;
           ListNode *localSucc = NULL; 
           ListNode *localCur = cur;
           while ( localCur != m ) {
               localSucc = localCur->next;
               localCur->next = localPred;
               localPred = localCur;
               localCur = localSucc;
           }
           // localPred is head of the reversed local list
           // cur is the tail of the reversed local list
           pred->next = localPred;
           cur->next = m;
            
           pred = cur;
           cur = m; 
        }
        
        return sentinal->next;
    }
};