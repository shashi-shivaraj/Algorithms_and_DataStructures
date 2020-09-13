/*You are given a pointer to the root of a binary search tree and values to be inserted into the tree.
 Insert the values into their appropriate position in the binary search tree and return the root of the updated binary tree.*/

//iterative method
    Node * insert(Node * root, int data) 
    {
        Node * newNode = new Node(data);
        Node * prev = nullptr;

        if(!root)
        {
            root  = newNode;
            return root;
        }

        Node * origRoot = root;

        while(root)
        {
            prev = root;
            if(root->data > data)
            {
                root = root ->left;
            }
            else
            {
                root = root -> right;
            }
        }

        if(prev->data > data)
            prev->left = newNode;
        else
            prev->right = newNode;

        return origRoot;
    }


//recursive method
  Node * insert(Node * root, int data) 
    {
         Node* newNode  = new Node(data);

        if(!root)
        {
            root = newNode;
            return root;
        }

        if(root->data > data)
            root->left = insert(root->left, data);
        else
            root->right = insert(root->right, data);

        return root;
    }