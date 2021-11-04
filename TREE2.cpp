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
/*
Postorder Traversal (Iterative) 
Medium Accuracy: 76.51% Submissions: 7228 Points: 4
Given a binary tree. Find the postorder traversal of the tree without using recursion.

Example 1

Input:
           1
         /   \
        2     3
      /  \
     4    5

Output: 4 5 2 3 1
Explanation:
Postorder traversal (Left->Right->Root) of 
the tree is 4 5 2 3 1.
*/
 vector<int> postOrder(Node* node) {
        stack<Node*> s;
vector<int> res;
s.push(node);
while(!s.empty())
{
node=s.top();
s.pop();
res.push_back(node->data);
if(node->left!=NULL)
s.push(node->left);
if(node->right!=NULL)
s.push(node->right);

}
reverse(res.begin(),res.end());
return res;
    }
/*
Make Binary Tree From Linked List 
Medium Accuracy: 51.16% Submissions: 21586 Points: 4
Given a Linked List Representation of Complete Binary Tree. The task is to construct the Binary tree.
Note : The complete binary tree is represented as a linked list in a way where if root node is stored at position i, its left, and right children are stored at position
2*i+1, 2*i+2 respectively.
 

*/
void convert(Node *head, TreeNode *&root) {
    if(head==NULL)return;
    root=new TreeNode(head->data);
    queue<TreeNode*>q;

    q.push(root);
    while(!q.empty()){
        TreeNode*temp=q.front();
        q.pop();
        if( head->next){
            temp->left=new TreeNode(head->next->data);
            q.push(temp->left);
            head=head->next;
        }
        if(head->next){
            temp->right=new TreeNode(head->next->data);
             q.push(temp->right);
            head=head->next;
        }
        
    }
    /*
    Count Number of SubTrees having given Sum 
Medium Accuracy: 50.13% Submissions: 25893 Points: 4
Given a binary tree and an integer X. Your task is to complete the function countSubtreesWithSumX() that returns the count of the number of subtress having 
total node’s data sum equal to the value X.
Example: For the tree given below:            

              5
            /    \
        -10     3
        /    \    /  \
      9     8  -4 7

Subtree with sum 7:
             -10
            /      \
          9        8

and one node 7.
    */
  int solve(Node*root,int &count,int X){
    if(root==NULL)return 0;
    int l=solve(root->left,count,X);
    int r=solve(root->right,count,X);
    int sum=l+r+root->data;
    if(sum==X)count++;
    return sum;
}
int countSubtreesWithSumX(Node* root, int X)
{
    int count=0;
    solve(root,count,X);
    return count;

}
/*
Leftmost and rightmost nodes of binary tree 
Medium Accuracy: 50.0% Submissions: 14212 Points: 4
Given a Binary Tree of size N, Print the corner nodes ie- the node at the leftmost and rightmost of each level.


Example 1:

Input :
         1
       /  \
     2      3
    / \    / \
   4   5  6   7    
Output: 1 2 3 4 7
Explanation:
Corners at level 0: 1
Corners at level 1: 2 3
Corners at level 2: 4 7

*/  
 void printCorner(Node *root)
{
    if(!root){
        return;
    }
    vector<int>v;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
         int n=size;
       
        while(size--){
            
            Node*temp=q.front();
            q.pop();
            if(n==1){
                 v.push_back(temp->data);
            }
           if(n>1){
               if(size==0 || size==n-1){
                    v.push_back(temp->data);
                    
               }
               
           }
            if(temp->left){
                q.push(temp->left);
                
            }
            if(temp->right){
                q.push(temp->right);             
            }      
        }
    }
for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
}   
 /*
 Diagonal Traversal of Binary Tree 
Medium Accuracy: 49.87% Submissions: 31020 Points: 4
Given a Binary Tree, print the diagonal traversal of the binary tree.

Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.

Example 1:

Input :
            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13
Output : 8 10 14 3 6 7 13 1 4
 */   
 vector<int> diagonal(Node *root)
{
      vector<int> ans;
if(root==NULL)return ans;
queue<Node*>q;
q.push(root);

while(!q.empty()){

Node* temp = q.front();
q.pop();
while(temp!=NULL){
ans.push_back(temp->data);
if(temp->left)q.push(temp->left);
temp=temp->right;
}}
return ans;
   // your code here
}
/*
Bottom View of Binary Tree 
Medium Accuracy: 45.32% Submissions: 91064 Points: 4
Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.
If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree the output should be 5 10 4 14 25.
*/        
  vector <int> bottomView(Node *root) {
         vector<int>v;
        map<int,int>m;
        if(root==NULL)return v;
        queue<pair<Node*,int>>q;
        q.push({root,0});
         while(!q.empty()){
          
                 Node*temp=q.front().first;
                 int h=q.front().second;
                 q.pop();
                
                     m[h]=temp->data;
                 
                 if(temp->left){
                    q.push({temp->left,h-1}) ;
                 }
                 if(temp->right){
                     q.push({temp->right,h+1});
                 }
             }
         
        for(auto x:m){
            v.push_back(x.second);
        }
      return v;   
     
    }   
           /*
           Vertical Traversal of Binary Tree 
Medium Accuracy: 32.45% Submissions: 100k+ Points: 4
Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Example 1:

Input:
           1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
              \      \
               8      9           
Output: 
4 2 1 5 6 3 8 7 9 
           */ 
  vector<int> verticalOrder(Node *root)
    {
         vector<int>v;
        if(!root)return v;
        queue<pair<Node*,int>>q;
        map<int,vector<int>>m;
        q.push({root,0});
        while(!q.empty()){
            pair<Node*,int>temp=q.front();
            q.pop();
            Node*c=temp.first;
            int h=temp.second;
            m[h].push_back(c->data);
            if(c->left)q.push({c->left,h-1});
            if(c->right)q.push({c->right,h+1});
            
        }
        for(auto x:m){
            vector<int>l=x.second;
            for(auto y:l){
                v.push_back(y);
            }
        }
        return v;
        //Your code here
    }
  /*
  Check if subtree 
Medium Accuracy: 43.66% Submissions: 79673 Points: 4
Given two binary trees with head reference as T and S having at most N nodes. The task is to check if S is present as subtree in T.
A subtree of a tree T1 is a tree T2 consisting of a node in T1 and all of its descendants in T1.

Example 1:

Input:
T:      1          S:   3
      /   \            /
     2     3          4
   /  \    /
  N    N  4
Output: 1 
Explanation: S is present in T
  */   
  bool solve(Node*t,Node*s){
     if(!t and !s)return true;
     if(!t || !s)return false;
     if(t->data!=s->data){
         return false;
     }
     if(solve(t->left,s->left)&& solve(t->right,s->right)){
         return true;
     }
     return false;
 }
    //Function to check if S is a subtree of tree T.
    bool isSubTree(Node* T, Node* S) 
    {
        if(!T  and !S){
            return true;
        }
        if(T!=NULL){
        if(isSubTree(T->left,S)|| isSubTree(T->right,S)||solve(T,S))return true;
        }
        return  false;
     
    }          
