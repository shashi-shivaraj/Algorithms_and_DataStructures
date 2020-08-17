/*
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Example 1:

Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.
*/

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
    void deleteNode(ListNode* node) 
    {
        ListNode* temp = nullptr;
        
        node->val = node->next->val; //copy val of next node
        temp = node->next;
        node->next = node->next->next;//link the node to next next node 
        
        delete temp; //delete next node.
        
    }
};