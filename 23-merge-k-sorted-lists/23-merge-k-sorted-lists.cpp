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
    
    private:
    class myComparator
    {
        public:
        int operator() (const pair<int, ListNode *>& lhs, const pair<int, ListNode *>& rhs)
        {
            return lhs.second->val > rhs.second->val;
        }   
    };
    
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode *sentinal = new ListNode( INT_MIN, NULL);
        ListNode *tail = sentinal;
            
        priority_queue < pair<int, ListNode*>, vector<pair<int, ListNode *>>, myComparator >  myMaxHp;
        
        for(int i = 0; i < lists.size(); i++)
        {
            if(lists[i] != nullptr) {
                ListNode *node = lists[i];
                myMaxHp.push( pair<int, ListNode *>(node->val, node));
            }
        }    
        
        while ( !myMaxHp.empty())
        {
            ListNode *node = myMaxHp.top().second;
            myMaxHp.pop();
            
            tail->next = node;
            tail = node;
            node = node->next;
            tail->next = NULL;
            if( node )
                myMaxHp.push( pair<int, ListNode *>(node->val, node));
               
        }
        
        return sentinal->next;
    }
};