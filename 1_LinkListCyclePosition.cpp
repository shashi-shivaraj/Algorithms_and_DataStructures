/*Given a linked list, return the node where the cycle begins. 
If there is no cycle, return null.*/

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
        ListNode *detectCycle(ListNode *head) 
        {
            ListNode* fast = head;
            ListNode* slow = head;
            
            while(slow && fast->next && fast->next->next)
            {
                fast = fast->next->next;
                slow = slow->next;
                
                if(fast == slow)
                {
                    slow = head;
                    while(slow && fast)
                    {
                        if(slow == fast)
                        {
                            return slow;
                        }
                        
                        slow = slow->next;
                        fast = fast->next;
                    }
                }
            }
            
            return nullptr;
        }
};