/*Reverse a linked list from position m to n. Do it in one-pass.
Note: 1 ≤ m ≤ n ≤ length of list.

Example:
Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL*/

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
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {   
        ListNode* list = head;
        ListNode* nextNode = nullptr,*prevNode = nullptr; 
        ListNode* beginNode = nullptr,*endNode = nullptr,*beginNodePrev = nullptr;
        
        int count = 1;
        
        while(list && m < n)
        {
            nextNode = list->next;
            
            if(count == m) //find start of reversal
            {
               beginNode = list;
               beginNodePrev = prevNode; 
            }
            
            if(count  > m && count <n) //resverse the links
            { 
                list->next = prevNode;
            }
            
            if(count == n) //find end of reversal
            {
               endNode = list;
                
               //modify the ends 
               beginNode->next = endNode->next;
               endNode->next = prevNode;
               
               if(beginNodePrev)
                   beginNodePrev->next = endNode; 
               else
                    head = endNode; //means that the start node is head of list
               
                break;
            }
             
            count ++;
            prevNode = list;    
            list = nextNode;
        }
        
        return head;
    }
};