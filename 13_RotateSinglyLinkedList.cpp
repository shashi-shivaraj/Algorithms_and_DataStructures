/*Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:
Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL

Example 2:
Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(!k || !head || !head->next) //return if null or single node
            return head;
        
        ListNode* list = head;
        ListNode* tail = nullptr, *prev = nullptr;
        int count = 0;
        
        while(head) //determine the length of the linked list
        {
            if(!head->next)
                tail = head;
            
            head = head->next;
            count ++;
        }
    
        head = list;
        
        k = k % count;  //number of shifts required
        
        if(k)
        {
            k = count - k;  //position of new head
            
            tail->next = head; //join tail to head

            while(k)
            {
                prev = head;
                head = head->next;
                k --;
            }
            
            prev->next = nullptr; //update prev of head to point to nullptr
            list = head; //update head of list
        }
        
        return head;
    }
};