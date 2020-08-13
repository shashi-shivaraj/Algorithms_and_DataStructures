/*Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:
Input: 1->1->2
Output: 1->2

Example 2:
Input: 1->1->2->3->3
Output: 1->2->3
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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* list = head;
        ListNode* temp = nullptr;
        while(head && head->next)
        {
            if(head->val == head->next->val)
            {
                temp = head->next;
                head->next = head->next->next;
                
                delete temp;
                
                continue; //need to compare the head value again.
            }
                
            head = head->next;
        }
        
        return list;
    }
};