/*
Remove all elements from a linked list of integers that have value val.

Example:
Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5

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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        if(!head || (!head->next && head->val != val))
            return head;
        
        ListNode* prev = nullptr;
        ListNode* list = head;
        ListNode* temp = head;
        
        while(head)
        {
            if(head->val == val)
            {
                temp = head;
                head = head->next;
                
                if(prev)
                {
                    prev->next = head;
                }
                else
                {
                    list = head;
                }
                
                delete temp;
                
                continue;
            }
            
            prev = head;
            head = head->next;
        }
        
        return list;
    }
};