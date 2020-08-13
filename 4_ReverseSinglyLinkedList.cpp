/*Reverse a singly linked list.
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL*/

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
    ListNode* reverseList(ListNode* head) 
    {
        if(!head || !head->next)
            return head;
        
        ListNode* nextNode = nullptr, *prevNode = nullptr;
        
        while(head)
        {
            nextNode = head->next;
            
            head->next = prevNode;
            
            prevNode = head;
            head = nextNode;
        }
        
        return prevNode;
    }
    
};

//recursion method
class Solution 
{
    public:
        ListNode* reverseList(ListNode* head) 
        {
            if(!head || !head->next)
                return head;
        
            ListNode* last = reverseList(head->next);
        
            if(!head->next->next)
            {
                ListNode *prevNode = head;
            
            
                head = head->next;
                head->next = prevNode;
                prevNode->next = nullptr;
            }
        
            return last;   
    }
};