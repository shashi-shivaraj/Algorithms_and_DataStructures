Write a program to find the node at which the intersection of two singly linked lists begins.
For example:

Test Case 0

 1
  \
   2--->3--->NULL
  /
 1

Test Case 1

1--->2
      \
       3--->Null
      /
     1

Test Case 3

1--->2--->3--->NULL

5--->6--->7--->NULL

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode *listA = headA;
        ListNode *listB = headB;
            
        while(headA && headB)
        {
            if(headA == headB)  //check if nodes are same 
                return headA;
            
            if(!headA->next && !headB->next) //if both reach end in 2nd iteration, no intersection
            {
                return nullptr;
            }
            
            headA = headA->next;
            headB = headB->next;

            
            if(!headA)
            {
                headA = listB; //point tail of A to head of B
            }
            
            if(!headB)
            {
                headB = listA; //point tail of B to head of A
            }
        }
        
        return nullptr;
    }
};