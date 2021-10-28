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
