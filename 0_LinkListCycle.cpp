/*Given a linked list, determine if it has a cycle in it.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
    public:
        
        bool hasCycle(ListNode *shead) 
        {
            ListNode* fast = shead;
            
            while(shead && fast->next && fast->next->next)
            {
                fast = fast->next->next;
                shead = shead->next;
                
                if(fast == shead)
                {
                    return true;
                }
            }
            
            return false;
        }
};