/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {   
        vector<int> res;
        
        traverse(root, res);
        
        return res;
        
    }
    
    void traverse(TreeNode* root,vector<int>& res)
    {
        if(!root)
            return;
        
        traverse(root->left,res);
        
        res.push_back(root->val);
        
        traverse(root->right,res);
        
    }      
};

/*Iterative method*/


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {   
        vector<int> res;
        
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        TreeNode* temp = nullptr;
        
        while(cur)
        {
            if(!cur->left) //end of left subtree
            {
                res.push_back(cur->val);
                cur = cur->right;
            }
            else //has left subtree
            {
                prev = cur->left;
                
                while(prev->right)
                {
                    prev = prev->right;
                }
                
                prev->right = cur; //end of right subtree points to curr
                
                temp = cur;
                
                cur = cur -> left; //make the left subtree head
                
                temp->left = nullptr; // left subtree has moved
            }
            
        }
        
        return res;
        
    }
    
};

/*

          1
        /   \
       2     3
      / \   /
     4   5 6

First, 1 is the root, so initialize 1 as current, 1 has left child which is 2, the current's left subtree is

         2
        / \
       4   5
So in this subtree, the rightmost node is 5, then make the current(1) as the right child of 5. Set current = cuurent.left (current = 2). The tree now looks like:

         2
        / \
       4   5
            \
             1
              \
               3
              /
             6
For current 2, which has left child 4, we can continue with thesame process as we did above

        4
         \
          2
           \
            5
             \
              1
               \
                3
               /
              6
then add 4 because it has no left child, then add 2, 5, 1, 3 one by one, for node 3 which has left child 6, do the same as above. Finally, the inorder taversal is [4,2,5,1,6,3].

*/