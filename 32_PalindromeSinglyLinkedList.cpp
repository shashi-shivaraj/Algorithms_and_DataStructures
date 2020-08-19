/*Given a singly linked list, determine if it is a palindrome.

Example 1:
Input: 1->2
Output: false

Example 2:
Input: 1->2->2->1
Output: true

Follow up:
Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) 
    {
        if(!head || !head->next)
            return true;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        ListNode* temp = nullptr;
        
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        fast = head;
        
        while(slow)
        {
            temp = slow->next;
            slow->next = prev;
            
            prev = slow;
            slow = temp;
        }
        
        slow = prev;
        
        while(slow && fast)
        {
            if(slow->val != fast->val)
                return false;
            
            slow = slow->next;
            fast = fast->next;
        }
        
        return true;
    }
};