/*
A tree is  a non linear data structure in which  one node points to different nodes 

Terms:

Root:A node with no parents or a node which cxannot cannot be derive from
any other node.

Edge : A link from parent to child nodes.

Leaf Nodes:A node with no children

Siblings:children of same parent 

Ancestor:A node q is said to be ancestor of node p if there exists a path from, root to p amd q comes in between.

Depth:distance of node from root;

Level:Set of nodes having same depth

Height:the height of node from deepest node

Skew Trees: If	every node in a	tree has only one child(except	leaf nodes)	
then we	call such trees skew trees.	If every node has only left	child then we call them	left.
skew trees.or node having only right child form right skew trees

Binary tree:A tree is said to be binaryif each node has either one two or no child .Empty trees are also valid binary trees

Types of  binary trees:

 Strict	Binary	Tree:A	binary	tree	is called	strict	binary	tree 
if	each node  has	exactly	two children or	no children.

Full binary tree:A binary tree is said to be full bvinary tree if each node has exactly two children and all leaf nodes are at same level.(2^(h+1)-1)

Complete binary tree:if h is height,then a binary tree is complete if leaf nodes are at height h o h-1.

 No of leaf nodes in full binary  tree is 2^h

No of Null nodes in com plete binary tree is h+1.

General structure of binary tree :
struct Node{
    int data;
    struct Node*left;
    struct Node*right;
}
*/
//Count Leaves in Binary Tree
int countLeaves(Node* root)
{
  if(root==NULL)return 0;
  if(root->left==NULL && root->right==NULL)return 1;
  else{
      return countLeaves(root->left)+countLeaves(root->right);
  }
}
//Minimum element in BST
int minValue(Node* root) {
    
    if(root==NULL)return -1;
    if(root->left==NULL)return root->data;
    else{
      return minValue(root->left) ; 
    }
}
//Size of Binary Tree 
int getSize(Node* node)
{
   if(node==NULL)return 0;
   else{
       return 1+getSize(node->left)+getSize(node->right);
   }
}
//INOTRDER TRAVERSAL
  void solve(Node*root,vector<int>&v){
        if(root==NULL)return;
        else{
            solve(root->left,v);
            v.push_back(root->data);
            solve(root->right,v);
        }
    }
    vector<int> inOrder(Node* root) {
        vector<int>v;
        solve(root,v);
        return v;   
    }
//POSTORDER TRAVERSAL
void fun(Node*root,vector<int>&v){
    if(root!=NULL){
        fun(root->left,v);
        fun(root->right,v);
        v.push_back(root->data);
    }
}
vector <int> postOrder(Node* root)
{
    vector<int>v;
    fun(root,v);
    return v;
  // Your code here
}
//preorder
void fun(Node*root,vector<int>&v){
    if(root!=NULL){
          v.push_back(root->data);
    fun(root->left,v);
    fun(root->right,v);
    }
  
}

//Function to return a list containing the preorder traversal of the tree.
vector <int> preorder(Node* root)
{
    vector<int>v;
    fun(root,v);
    return v;
}
// MIRROR TREE Given a Binary Tree, convert it into its mirror.
 void mirror(Node* node) {
        if(node==NULL)return;
        mirror(node->left);
        mirror(node->right);
        swap(node->left,node->right);
    }
/*
Expression Tree 
Easy Accuracy: 55.88% Submissions: 24149 Points: 2
Given a full binary expression tree consisting of basic binary operators (+ , – ,*, /) and some integers, Your task is to evaluate the expression tree.

Example 1:

Input: 
              +
           /     \
          *       -
        /  \    /   \
       5    4  100  20 

Output: 100

Explanation:
((5 * 4) + (100 - 20)) = 100
*/
int evalTree(node* root) {
  //  if(root==NULL)return 0;
     if(!root->left and !root->right) return  stoi(root->data);
        
    
        int l=evalTree(root->left);
        int r=evalTree(root->right);
        if(root->data=="+"){
            return l+r;
        }
        else if(root->data=="*"){
            return l*r;
        }
        else if(root->data=="-"){
            return l-r;
        }
        else{
            return (l/r);
        }    // Your code here
    }
/*
K distance from root 
Easy Accuracy: 55.52% Submissions: 53384 Points: 2
Given a Binary Tree of size N and an integer K. Print all nodes that are at distance k from root (root is considered at distance 0 from itself).
Nodes should be printed from left to right. If k is more that height of tree, nothing should be printed.

For example, if below is given tree and k is 2. Output should be 4 5 6.

          1
       /     \
     2        3
   /         /   \
  4        5    6 
     \
      8

Example 1:

Input:
K = 0
      1
    /   \
   3     2
Output: 1

*/
void solve(Node*root,vector<int>&v,int k){
    if(root==NULL)return;
    if(k==0){
        v.push_back(root->data);
    }
    else{
        solve(root->left,v,k-1);
        solve(root->right,v,k-1);
    }
}
vector<int> Kdistance(struct Node *root, int k)
{
    vector<int>v;
solve(root,v,k);
return v;
}
/*
Odd even level difference 
Easy Accuracy: 53.67% Submissions: 22445 Points: 2
Given a Binary Tree. Find the difference between the sum of node values at even levels and the sum of node values at the odd levels.

Example 1:

Input:
            1
          /   \
         2     3

Output: -4

Explanation:
sum at odd levels - sum at even levels
= (1)-(2+3) = 1-5 = -4
*/
 int getLevelDiff(Node *root)
    {
      if(root==NULL)return 0;
      int sum=0;
      int lvl=1;
      int oddsum=0;
      int evensum=0;
      queue<Node*>q;
      q.push(root);
      while(!q.empty()){
          int size=q.size();
          while(size--){
              Node*temp=q.front();
              sum+=temp->data;
              q.pop();
              if(temp->left){
                  q.push(temp->left);
              }
              if(temp->right){
                  q.push(temp->right);
              }
          }
      
          if(lvl%2==1){
              oddsum+=sum;
              
          }
          else{
              evensum+=sum;
          }
        lvl++;
          sum=0;
          
      }
      return oddsum-evensum;
      
    }
/*
Minimum Depth of a Binary Tree 
Easy Accuracy: 52.43% Submissions: 38063 Points: 2
Given a binary tree, find its minimum depth.

Example 1:

Input:
            1
          /   \
         3     2
        /
       4           

Output: 2

Explanation:
Minimum depth is between nodes 1 and 2 since
minimum depth is defined as  the number of 
nodes along the shortest path from the root 
node down to the nearest leaf node.
*/
  int minDepth(Node *root) {
        if(root==NULL)return 0;
        else if(root->left==NULL){
            return (1+minDepth(root->right));
        }
        else if(root->right==NULL){
           return (1+minDepth(root->left));  
        }
        else{
            return min(1+minDepth(root->left),1+minDepth(root->right));
        }
    }
/*
Determine if Two Trees are Identical 
Easy Accuracy: 52.24% Submissions: 100k+ Points: 2
Given two binary trees, the task is to find if both of them are identical or not. 


Example 2:

Input:
     1          1
   /   \      /   \
  2     3    2     3
Output: Yes
Explanation: There are two trees both
having 3 nodes and 2 edges, both trees
are identical having the root as 1,
left child of 1 is 2 and right child
of 1 is 3.
*/
 bool isIdentical(Node *r1, Node *r2)
    {
        if(r1==NULL && r2==NULL)return true;
        if(r1==NULL || r2==NULL)return false;
        if(r1->data!=r2->data){
            return false;
        }
        else{
            return isIdentical(r1->left,r2->left)&& isIdentical(r1->right,r2->right);
        }}
