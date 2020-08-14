/*
Given a sorted linked list, delete all nodes that have duplicate numbers,
leaving only distinct numbers from the original list.

Return the linked list sorted as well.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5

Example 2:

Input: 1->1->1->2->3
Output: 2->3
*/
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
class Solution 
{
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(!head || !head->next)
        {
            return head;
        }
        
        ListNode* list = head;
        ListNode* temp = nullptr;
        ListNode* prev = nullptr;
        
        int dupValue = 0;
        bool dupFound = false;
        
        while(head)
        {
            //first peek into next to find duplicate
            if((head->next && head->val == head->next->val) || (dupFound && head->val == dupValue))
            {
                dupFound = true;
                dupValue = head->val; //next use this value to check for duplicates
                
                temp = head->next;
                delete head;
                head = temp;
                
                if(prev)
                    prev->next = head;
                else
                    list = head; //update original list head
                
                continue; //check for remaining single entry with dup value
            }
            
            dupFound = false; //reset for new value
            prev = head;
            head = head->next;
        }
        
        return list;
    }
};