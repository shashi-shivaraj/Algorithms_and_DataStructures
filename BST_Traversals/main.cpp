#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;	

class Node{
    public:
        int data;
        Node *left,*right;
        Node(int d){
            data=d;
            left=right=NULL;
        }
};

class Solution{
    public:
  		Node* insert(Node* root, int data){
            if(root==NULL){
                return new Node(data);
            }
            else{
                Node* cur;
                if(data<=root->data){
                    cur=insert(root->left,data);
                    root->left=cur;
                }
                else{
                   cur=insert(root->right,data);
                   root->right=cur;
                 }           
           return root;
           }
        }

    //inorder traversal
	void inOrder(Node * root)
    {
      if(!root)
        return;

      inOrder(root->left);
      std::cout<<root->data<<" ";
      inOrder(root->right);
	}

    //post oder traversal
    void postOrder(Node * root)
    {
      if(!root)
        return;

      postOrder(root->left);
      postOrder(root->right);
      std::cout<<root->data<<" ";
    }

    //pre oder traversal
    void preOrder(Node * root)
    {
      if(!root)
        return;

      std::cout<<root->data<<" ";
      preOrder(root->left);
      preOrder(root->right);
      
    }

    //level oder traversal or breadth-first-search
    void levelOrder(Node * root)
    {
      if(!root)
        return;
  
      que.push(root);

      while(false == que.empty())
      {
          Node *node = que.front();
          que.pop();

          std::cout<<node->data<<" ";

          if(node->left)
            que.push(node->left);
          if(node->right)
            que.push(node->right);
      }
    }

    private:
        std::queue<Node*> que; //queue for level order traversal

};//End of Solution


int main()
{
    Solution myTree;
    Node* root=NULL;
    int T,data;
    cin>>T;
    while(T-->0)
    {
        cin>>data;
        root= myTree.insert(root,data);
    }
    std::cout<<"IN order traversal : "<<std::endl;
    myTree.inOrder(root);
    std::cout<<std::endl;
    std::cout<<"POST order traversal : "<<std::endl;
    myTree.postOrder(root);
    std::cout<<std::endl;
    std::cout<<"PRE order traversal : "<<std::endl;
    myTree.preOrder(root);
    std::cout<<std::endl;
    std::cout<<"Level order traversal : "<<std::endl;
    myTree.levelOrder(root);
    std::cout<<std::endl;
    return 0;
}
