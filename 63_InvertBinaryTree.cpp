/* Invert a binary tree.

Example:
Input:
     4
   /   \
  2     7
 / \   / \
1   3 6   9

Output:
     4
   /   \
  7     2
 / \   / \
9   6 3   1

*/

//recursive solution
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        if(!root)
            return root;
        
        invertTree(root->left);
        invertTree(root->right);
        
        std::swap(root->left,root->right);
        
        return root;
        
    }
};

//iterative solution
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        if(!root)
            return root;
        
        TreeNode* node;
            
        std::queue<TreeNode*> nodeQ;
        nodeQ.push(root);
        
        while(!nodeQ.empty())
        {
            node = nodeQ.front();
            nodeQ.pop();
            std::swap(node->left,node->right);
            
            if(node->left)
                nodeQ.push(node->left);
            
            if(node->right)
                nodeQ.push(node->right);   
        }
        
        return root;
    }
};
