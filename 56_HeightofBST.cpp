/*
The height of a binary search tree is the number of edges between the tree's root and its furthest leaf.
You are given a pointer pointing to the root of a binary search tree. 
*/

int getHeight(Node* root)
{
    if(!root)
        return -1;

    int rightHeight = getHeight(root->right);
    int leftHeight = getHeight(root->left);

    if(leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}
