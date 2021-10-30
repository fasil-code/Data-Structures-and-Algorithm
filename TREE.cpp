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

/*
Perfect Binary Tree 
Easy Accuracy: 49.07% Submissions: 9406 Points: 2
Given a Binary Tree, write a function to check whether the given Binary Tree is a prefect Binary Tree or not. A Binary tree is Perfect Binary Tree in which all internal nodes have two children and all leaves are at same level.

Example 1:

Input: 
          7
      /  \
     4    9
Output: YES
Explanation: 
As the root node 7 has two children and 
two leaf nodes 4 and 9 are at same level 
so it is a perfect binary tree.
*/
int depth(Node*root){
    if(!root)return 0;
    int l=depth(root->left);
    int r=depth(root->right);
    return max(l,r)+1;
    
    
}
bool solve(Node*root,int lvl,int d){
    if(root==NULL)return false;
    if(root->left==NULL && root->right==NULL){
        return (lvl+1==d);
    }
    if(root->left==NULL || root->right==NULL){
        return false;
    }
    else {
        return solve(root->left,lvl+1,d)&& solve(root->right,lvl+1,d);
    }
}
    bool isPerfect(Node *root)
    {
      int d=depth(root);
      return solve(root,0,d);
    }
/*
 Remove Half Nodes 
Easy Accuracy: 51.47% Submissions: 13880 Points: 2
Given A binary Tree. Your task is to remove all the half nodes (which has only one child).

Example 1:

Input:
         7
       /   \
      7     8
     / 
    2
Output: 2 7 8   
       
*/
Node *RemoveHalfNodes(Node *root)
{
    if(root==NULL)return root;
root->left=RemoveHalfNodes(root->left);
root->right=RemoveHalfNodes(root->right);
    if(root->left && !root->right){
        free(root);
        return root->left;
    }
    else if(!root->left && root->right){
        free(root);
        return root->right;
    }
    else{
        return root;
    }
  /*
  Right View of Binary Tree 
Easy Accuracy: 51.66% Submissions: 70878 Points: 2
Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

Right view of following tree is 1 3 7 8.

          1
       /     \
     2        3
   /   \      /    \
  4     5   6    7
    \
     8

Example 1:

Input:
       1
    /    \
   3      2
Output: 1 2
  
  */
vector<int> rightView(Node *root)
    {
        vector<int>v;
        if(root==NULL)return v;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
              v.push_back(q.front()->data);
            while(size--){
                Node*temp=q.front();
                q.pop();
                if(temp->right){
                    q.push(temp->right);
                }
                if(temp->left){
                    q.push(temp->left);
                }
            }
          
            
        }
        return v;
    
    }
 /*
 Vertical sum 
Easy Accuracy: 50.84% Submissions: 20218 Points: 2
Given a Binary Tree, find vertical sum of the nodes that are in same vertical line. Print all sums through different vertical lines starting from left-most vertical line to right-most vertical line.

Example 1:

Input:
       1
    /   \
  2      3
 / \    / \
4   5  6   7
Output: 
Explanation:
The tree has 5 vertical lines
Vertical-Line-1 has only one node
4 => vertical sum is 4
Vertical-Line-2: has only one node
2=> vertical sum is 2
Vertical-Line-3: has three nodes:
1,5,6 => vertical sum is 1+5+6 = 12
Vertical-Line-4: has only one node 3
=> vertical sum is 3
Vertical-Line-5: has only one node 7
=> vertical sum is 7
 */
  void solve(Node*root,int lvl,map<int,int>&mp){
      if(root==NULL)return;
      mp[lvl]+=root->data;
      solve(root->left,lvl-1,mp);
      solve(root->right,lvl+1,mp);
  }
    vector <int> verticalSum(Node *root) {
        vector<int>v;
    map<int,int>mp;
        solve(root,0,mp);
    for(auto x:mp){
        v.push_back(x.second);
    }
    return v;
    }
 //Diagonal Sum In Binary Tree 
 void solve(Node*root,int lvl,map<int,int>&mp){
      if(root==NULL)return;
      mp[lvl]+=root->data;
      solve(root->left,lvl+1,mp);
      solve(root->right,lvl,mp);
  }
   
       
vector <int> diagonalSum(Node* root) {
     vector<int>v;
    map<int,int>mp;
        solve(root,0,mp);
    for(auto x:mp){
        v.push_back(x.second);
    }
    return v;
   
}
//Symmetric Tree
  bool solve(Node*r1,Node*r2){
        if(!r1 && !r2)return true;
          if(!r1&& r2)return false;
          if(r1&& !r2)return false;
            if(r1->data!= r2->data)return false;
            else{
                return solve(r1->left,r2->right)&& solve(r1->right,r2->left);
            }
    }
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node* root)
    {
       return solve(root,root);
	    // Code here
    }
/*
Transform to Sum Tree 
Easy Accuracy: 50.22% Submissions: 41222 Points: 2
Given a Binary Tree of size N , where each node can have positive or negative values. Convert this to a tree where each node contains the sum of the left and right sub trees of the original tree. The values of leaf nodes are changed to 0.

Example 1:

Input:
             10
          /      \
        -2        6
       /   \     /  \
     8     -4   7    5

Output:
            20
          /    \
        4        12
       /  \     /  \
     0     0   0    0

Explanation:

           (4-2+12+6)
          /           \
      (8-4)          (7+5)
       /   \         /  \
      0     0       0    0
*/
 int fun(Node*root){
      if(root==NULL)return 0;
      int x=root->data;
      root->data=(fun(root->left))+fun((root->right));
      return x+root->data;
  }
    
    void toSumTree(Node *node)
    {
       fun(node);
    }	
	/*
	Lowest Common Ancestor in a BST 
Easy Accuracy: 50.22% Submissions: 77927 Points: 2
Given a Binary Search Tree (with all values unique) and two node values. Find the Lowest Common Ancestors of the two nodes in the BST.

Example 1:

Input:
              5
           /    \
         4       6
        /         \
       3           7
                    \
                     8
n1 = 7, n2 = 8
Output: 7
	*/
	Node* LCA(Node *root, int n1, int n2)
{
  if(root==NULL)return root;
  if((root->data<=n2 && root->data>=n1)||(root->data>=n2 && root->data<=n1)){
      return root;
  }
  else if(root->data<n1 && root->data<n2){
      return LCA(root->right,n1,n2);
  }
  else{
       return LCA(root->left,n1,n2);
  }
}
/*
Check if Tree is Isomorphic 
Easy Accuracy: 50.16% Submissions: 37876 Points: 2
Given two Binary Trees. Check whether they are Isomorphic or not.

Note: 
Two trees are called isomorphic if one can be obtained from another by a series of flips, i.e. by swapping left and right children of several nodes.
Any number of nodes at any level can have their children swapped. Two empty trees are isomorphic.
For example, the following two trees are isomorphic with the following sub-trees flipped: 2 and 3, NULL and 6, 7 and 8.
*/	
bool isIsomorphic(Node *root1,Node *root2)
    {
       if(root1==NULL && root2==NULL){
           return true;
       } 
        if(root1==NULL || root2==NULL)
        return false;
        if(root1->data!=root2->data){
            return false;
        }
        else {
            return ( isIsomorphic(root1->left,root2->left)&& isIsomorphic(root1->right,root2->right))||
    (isIsomorphic(root1->left,root2->right)&& isIsomorphic(root1->right,root2->left));
        }
    //add code here.
    }
	/*
	Check for Balanced Tree 
Easy Accuracy: 50.11% Submissions: 100k+ Points: 2
Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

A height balanced tree
        1
     /     \
   10      39
  /
5

An unbalanced tree
        1
     /    
   10   
  /
5
	*/
	int height(Node*root){
        if(root==NULL)return 0;
        int l=height(root->left);
        int r=height(root->right);
        return max(l,r)+1;
    }
    bool isBalanced(Node *root)
    {
        if(root==NULL)return true;
        int l=height(root->left);
        int h=height(root->right);
        if(abs(l-h)>1){
            return false;
        }
        return isBalanced(root->left)&&isBalanced(root->right);
       // return true;
        //  Your Code here
    }
	/*
Diameter of a Binary Tree 
Easy Accuracy: 50.01% Submissions: 100k+ Points: 2
The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. 
The diagram below shows two trees each with diameter nine, the leaves that form the ends of the longest path are shaded
(note that there is more than one path in each tree of length nine, but no path longer than nine nodes). 
	*/
	int height(Node*root){
      if(root==NULL)return 0;
      int l=height(root->left);
      int r=height(root->right);
      return max(l,r)+1;
  }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        if(root==NULL)return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        int ld=diameter(root->left);
        int rd=diameter(root->right);
    return max(1+lh+rh,max(ld,rd));
      
    }
	/*
	Binary Tree to BST 
Easy Accuracy: 50.0% Submissions: 28915 Points: 2
Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.
 

Example 1:

Input:
      1
    /   \
   2     3
Output: 1 2 3
	
	*/
void inorder(Node*root,vector<int>&v){
      if(root==NULL)return;
      v.push_back(root->data);
      inorder(root->left,v);
      inorder(root->right,v);
  }
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node*bsdk(vector<int>v,int low,int high){
        if(low>high){
            return NULL;
        }
 //       if(root==NULL)return;
        int mid=(low+high)/2;
        Node*new_node=new Node(v[mid]);

        new_node->left=bsdk(v,low,mid-1);
         new_node->right=bsdk(v,mid+1,high);
         return new_node;
    }
    Node *binaryTreeToBST (Node *root)
    {
        if(root==NULL)return root;
        vector<int>v;
      inorder(root,v);
 sort(v.begin(),v.end());
 return bsdk(v,0,v.size()-1);     
    }	
//Sum of Right Leaf Nodes 
	 void solve(Node*root,int &sum){
        if(root==NULL )return;
        if(root->right){
            if(root->right->right==NULL && root->right->left==NULL){
                sum+=root->right->data;
            }
        }
        solve(root->left,sum);
        solve(root->right,sum);
        
    }
    int rightLeafSum(Node* root)
    {
        int sum=0;
    solve(root,sum);
        return sum;
         //Code here
    }
	
