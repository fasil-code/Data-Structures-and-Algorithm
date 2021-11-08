AVL TREE INSERTION
class Solution{
  public:
    /*You are required to complete this method */
    int height(Node*root){
        if(root==NULL){
            return 0;
        }
        return root->height;
    }
    int bf(Node*root){
        if(root==NULL)return 0;
        return height(root->left)-height(root->right);
    }
    Node*right(Node*root){
     Node*x=root->left;
     Node*T2=x->right;
     root->left=T2;
     x->right=root;
        root->height=max(height(root->left),height(root->right))+1;
     x->height=max(height(x->left),height(x->right))+1;
  
     return x;
    }
    Node*left(Node*root){
        Node*y=root->right;
        Node*T2=y->left;
         root->right=T2;
          y->left=root;
root->height=max(height(root->left),height(root->right))+1;
      
y->height=max(height(y->left),height(y->right))+1;
    
     return y;
    }
    Node*create(int k){
        Node*temp=new Node(k);
        temp->left=NULL;
        temp->right=NULL;
        temp->height=1;
        return temp;
    }
    Node* insertToAVL(Node* root, int data)
    {
        if(root==NULL)return create(data);
        if(root->data>data){
            root->left=insertToAVL(root->left,data);
        }
        else if(root->data<data){
            root->right=insertToAVL(root->right,data);
        }
        else{
            return root;
            
        }
        root->height=max(height(root->left),height(root->right))+1;
         int bal = bf(root);
         
         if(bal>1 && root->left->data>data){
             return right(root);
         }
         if(bal<-1 && root->right->data<data){
             return left(root);
         }
          if(bal>1 && root->left->data<data){
              root->left=left(root->left);
             return right(root);
         }
          if(bal<-1 && root->right->data>data){
              root->right=right(root->right);
             return left(root);
         }
         return root;
        //Your code here
    }
};
/*
AVL Tree Deletion 
Hard Accuracy: 37.18% Submissions: 6161 Points: 8
Given a AVL tree and N values to be deleted from the tree. Write a function to delete a given value from the tree.

Example 1:

Tree = 
        4
      /   \
     2     6
    / \   / \  
   1   3 5   7

N = 4
Values to be deleted = {4,1,3,6}

Input: Value to be deleted = 4
Output:
        5    
      /   \
     2     6
    / \     \  
   1   3     7

Input: Value to be deleted = 1
Output:
        5    
      /   \
     2     6
      \     \  
       3     7

Input: Value to be deleted = 3
Output:
        5    
      /   \
     2     6
            \  
             7

Input: Value to be deleted = 6
Output:
        5    
      /   \
     2     7

*/
void inorder(Node*root,vector<int>&v, int data){
    if(root==NULL){
        return;
    }
    inorder(root->left,v,data);
    if(root->data!=data){
        v.push_back(root->data);
    }
    inorder(root->right,v,data);
    }
    Node*build(vector<int>v,int start,int end){
        if(start>end){
            return NULL;
        }
        int mid=(start+end)/2;
        Node*temp=new Node(v[mid]);
        temp->left=build(v,start,mid-1);
        temp->right=build(v,mid+1,end);
        return temp;
    }
Node* deleteNode(Node* root, int data)
{
vector<int>v;
inorder(root,v,data);
return build(v,0,v.size()-1);
  
}
