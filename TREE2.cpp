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
   /*
   Construct Binary Tree from Parent Array 
Medium Accuracy: 45.96% Submissions: 23829 Points: 4
Given an array of size N that can be used to represents a tree. The array indexes are values in tree nodes and array values give the parent node of that particular index (or node). The value of the root node index would always be -1 as there is no parent for root. Construct the standard linked representation of Binary Tree from this array representation.


Example 1:

Input:
N = 7
parent[] = {-1,0,0,1,1,3,5}
Output: 0 1 2 3 4 5 6
Explanation: the tree generated
will have a structure like 
          0
        /   \
       1     2
      / \
     3   4
    /
   5
 /
6
   
   */         
Node *createTree(int parent[], int N)
    {
        unordered_map<int,Node*>mp;
        for(int i=0;i<N;i++){
            Node*temp=new Node(i);
            mp[i]=temp;
        }
        Node*root;
        Node*rooot;
        for(int i=0;i<N;i++){
            if(parent[i]==-1){
                rooot=mp[i];
                
            }
            else{
                Node*temp=mp[i];
                int val=parent[i];
                root=mp[val];
                if(!root->left){
                    root->left=temp;
                }
                else{
                    root->right=temp;
                }
            }
        }
        return rooot;
        // Your code here
    }
            /*
            Preorder Traversal and BST 
Medium Accuracy: 58.03% Submissions: 5042 Points: 4
Given an array arr[ ] of size N consisting of distinct integers, write a program that returns 1 if given array can represent preorder traversal of a possible BST, else returns 0.

Example 1:

Input:
N = 3
arr = {2, 4, 3}
Output: 1
Explaination: Given arr[] can represent
preorder traversal of following BST:
               2
                \
                 4
                /
               3
            */
     int canRepresentBST(int pre[], int n) {
         stack<int> s;
       int root = INT_MIN;
       for (int i=0; i<n; i++)
       {
           if (pre[i] < root)
               return 0;
   
           while (!s.empty() && s.top()<pre[i])
           {
               root = s.top();
               s.pop();
           }
           s.push(pre[i]);
       }
       return 1;
        // code here
    }
/*
traversal of BST. The task is to print its postorder traversal.

Example 1:

Input:
N = 5
arr[]  = {40,30,35,80,100}
Output: 35 30 100 80 40
Explanation: PreOrder: 40 30 35 80 100
InOrder: 30 35 40 80 100
Therefore, the BST will be:
              40
           /      \
         30       80
           \        \   
           35      100
Hence, the postOrder traversal will
be: 35 30 100 80 40
*/        
Node*solve(Node*&root,int x){
    if(root==NULL){
        return root=newNode(x);
    }
    if(root->data>x){
        root->left=solve(root->left,x);
    }
    else{
        root->right=solve(root->right,x);
    }
    return root;
}
Node* post_order(int pre[], int size)
{
    Node*root=NULL;
    for(int i=0;i<size;i++){
        solve(root,pre[i]);
    }
    return root;
   
}
 /*
 Clone a Binary Tree 
Medium Accuracy: 55.34% Submissions: 15640 Points: 4
Given a special binary tree having random pointers along with the usual left and right pointers. Clone the given tree.


Example 1:

Input:
 */           
 void insertmid(Node *root)
{
if(!root)
return;

Node*temp= new Node(root->data);
temp->left=root->left;
temp->right=root->right;
root->left=temp;

insertmid(temp->left);
insertmid(temp->right);
}
void random(Node *root)
{
if(!root)
return;

root->left->random=(root->random)?root->random->left:NULL;

random(root->left->left);
random(root->left->right);
}
void restore (Node *root)
{
if(!root)
return;

Node*copy=root->left;
root->left=copy->left;
root->right=copy->right;

copy->left=(root->left)?root->left->left:NULL;
copy->right=(root->right)?root->right->left:NULL;

restore(root->left);
restore(root->right);
}
Node* cloneTree(Node* root)
{
insertmid(root);
random(root);

Node* cloneroot=root->left;
restore(root);

return cloneroot;
}
/*
Construct Tree from Preorder Traversal 
Medium Accuracy: 50.68% Submissions: 13694 Points: 4
Construct a binary tree of size N using two given arrays pre[] and preLN[]. Array pre[] represents preorder traversal of a binary tree. Array preLN[] has only two possible values ‘L’ and ‘N’. The value ‘L’ in preLN[] indicates that the corresponding node in Binary Tree is a leaf node and value ‘N’ indicates that the corresponding node is a non-leaf node.
Note: Every node in the binary tree has either 0 or 2 children.

Example 1:

Input :      
N = 5
pre[] = {10, 30, 20, 5, 15}
preLN[] = {N, N, L, L, L}

Output:
          10
        /    \
      30      15
     /  \     
   20    5   
*/      
 struct Node *constructTree(int n, int pre[], char preLN[])
{
    Node*root=new Node(pre[0]);
    stack<Node*>s;
    s.push(root);
    int i=1;
    while(i<n){
        Node*temp=s.top();
        if(temp->left==NULL){
            temp->left=new Node(pre[i]);
            if(preLN[i]=='N'){
                s.push(temp->left);
                
            }
             i++;
        }
             else if(temp->right==NULL){
            temp->right=new Node(pre[i]);
            if(preLN[i]=='N'){
                s.push(temp->right);
            }
            i++;
        }
        
        else{
            s.pop();
        }

    }
   return root; 
 }
            /*
   Serialize and Deserialize a Binary Tree 
Medium Accuracy: 47.46% Submissions: 35481 Points: 4
Serialization is to store a tree in an array so that it can be later restored and Deserialization is reading tree back from the array. Now your task is to complete the function serialize which stores the tree into an array A[ ] and deSerialize which deserializes the array to the tree and returns it.
Note: The structure of the tree must be maintained. Multiple nodes can have the same data.

Example 1:

Input:
      1
    /   \
   2     3
Output: 2 1 3         
            
            */
    void solve(Node*root,vector<int>&v){
        if(root==NULL){
            v.push_back(-1);
            return;
        }
        v.push_back(root->data);
        solve(root->left,v);
        solve(root->right,v);
        
    }
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {vector<int>v;
    solve(root,v);
    return v;
        
        //Your code here
    }
    
    //Function to deserialize a list and construct the tree.
  Node* deSerializeUtil(vector<int> &A,int &pointer)
{
if(A[pointer]==-1){
pointer++;
return NULL;
}
Node *root = new Node(A[pointer]);
pointer++;
root->left = deSerializeUtil(A,pointer);
root->right = deSerializeUtil(A,pointer);

return root;
}

Node * deSerialize(vector<int> &A)
{
//Your code here
int pointer=0;
return deSerializeUtil(A,pointer);
} 
   
         
