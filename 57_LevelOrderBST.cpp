/*A level-order traversal, also known as a breadth-first search, 
visits each level of a tree's nodes from left to right, top to bottom.
You are given a pointer pointing to the root of a binary search tree.*/

void levelOrder(Node * root)
{
    if(!root)
        return;

    std::queue<Node*> nodeQ;

    nodeQ.push(root);

    while(nodeQ.empty() != true)
    {
        root = nodeQ.front();

        std::cout<<root->data<<" ";

        nodeQ.pop();

        if(root->left)
            nodeQ.push(root->left);

        if (root->right)
            nodeQ.push(root->right); 
    }
}