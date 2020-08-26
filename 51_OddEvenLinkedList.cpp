/*
Given a singly linked list, group all odd nodes together followed by the even nodes. 
Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. 
The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if(!head || !head->next)
            return head;
        
        ListNode* list = head;
        
        ListNode* odd = head; //odd at at node 0
        ListNode* even = head->next; //even at at node 1
        
        ListNode* evenInit = head->next; //store for joining
        
        while(even && even->next)
        {
            odd->next = even->next; //point odd to next of even
            even->next = odd->next->next; //point even to next of updated odd
            
            odd = odd->next; //move to next pair
            even = even->next;
        }
        
        odd->next = evenInit; //join end of oll list to head of even list
        
        return list;
    }
};