/*
Merge two sorted linked lists and return it as a new sorted list.
The new list should be made by splicing together the nodes of the first two lists.

Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode* head = new ListNode(); //create dummy head
        
        ListNode* list = head;
        
        while(l1 && l2)// loop through elements of each list and update the new list
        {
            if(l1->val < l2->val)
            {
              head->next = l1;
              l1 = l1->next;
            }
            else
            {
                head->next = l2;
                l2 = l2->next;
            }
            
            head = head->next;
        }
        
        if(l1) //check if l1 has more elements
        {
            head->next = l1;
        }
        else if(l2) //check if l2 has more elements
        {
            head->next = l2;
        }
        
        head = list->next;
        
        delete list;//delete dummy node
        
        return head;
    }
};