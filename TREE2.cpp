/*
Preorder traversal (Iterative) 
Medium Accuracy: 71.48% Submissions: 12378 Points: 4
Given a binary tree. Find the preorder traversal of the tree without using recursion.


Example 1:

Input:
           1
         /   \
        2     3
      /  \
     4    5
Output: 1 2 4 5 3
Explanation:
Preorder traversal (Root->Left->Right) of 
the tree is 1 2 4 5 3.
*/
 vector<int> preOrder(Node* root)
    {
    vector<int>v;
    if(root==NULL)return v;
    stack<Node*>s;
    s.push(root);
    while(!s.empty()){
        Node*temp=s.top();
        s.pop();
        v.push_back(temp->data);
        if(temp->right){
            s.push(temp->right);
        }
        if(temp->left){
            s.push(temp->left);
        }
    }
    return v;
 }
/*
Inorder Traversal (Iterative) 
Medium Accuracy: 74.94% Submissions: 11060 Points: 4
Given a binary tree. Find the inorder traversal of the tree without using recursion.

Example 1

Input:
           1
         /    \
       2       3
      /   \
    4     5
Output: 4 2 5 1 3
Explanation:
Inorder traversal (Left->Root->Right) of 
the tree is 4 2 5 1 3.
*/
vector<int> inOrder(Node* root)
    {
     vector<int>v;
    if(root==NULL)return v;
    stack<Node*>s;
    Node*temp=root;
    while(!s.empty()|| temp!=NULL){
        while(temp!=NULL){
            s.push(temp);
            temp=temp->left;
        }
        temp=s.top();
        s.pop();
        v.push_back(temp->data);
        temp=temp->right;    
        //code here
    }
    return v;
    }
