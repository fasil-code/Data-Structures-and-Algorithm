/*
Delete Alternate Nodes 
Basic Accuracy: 51.7% Submissions: 37885 Points: 1
Given a Singly Linked List of size N, delete all alternate nodes of the list.

Example 1:

Input:
LinkedList: 1->2->3->4->5->6
Output: 1->3->5
Explanation: Deleting alternate nodes
results in the linked list with elements
1->3->5.
*/
void deleteAlt(struct Node *head){
    if(!head || !head->next){
        return;
    }
   
    Node*ptr=head;
    while( ptr && ptr->next!=NULL){
        ptr->next=ptr->next->next;
    ptr=ptr->next;
    } // Code here
}
/*
Check If Circular Linked List 
Basic Accuracy: 50.74% Submissions: 61530 Points: 1
Given head, the head of a singly linked list, find if the linked list is circular or not.
A linked list is called circular if it not NULL terminated and all nodes are connected in the form of a cycle.
An empty linked list is considered as circular.

Example 1:

Input:
LinkedList: 1->2->3->4->5
(the first and last node is connected,
i.e. 5 --> 1)
Output: 1
*/
bool isCircular(struct Node *head){
if(!head)return true;
    struct Node*temp=head;
    while(temp!=NULL){
        temp=temp->next;
        if(temp==head){
            return true;
        }
    }
    return false;
    //code here
}
/*
Delete node in Doubly Linked List 
Basic Accuracy: 48.28% Submissions: 35329 Points: 1
Given a doubly linked list and a position. The task is to delete a node from given position in a doubly linked list.

Example 1:

Input:
LinkedList = 1 <--> 3 <--> 4 
x = 3
Output: 1 3  
Explanation: After deleting the node at
position 3 (position starts from 1),
the linked list will be now as 1->3.
*/
 Node* deleteNode(Node *head, int x)
    {
        if(head==NULL)return head;
        if(head->next==NULL)return NULL;
       
        if(x==1){
            head->next->prev=NULL;
            head=head->next;
            return head;
        }
        else{
            Node*temp=head;
            for(int i=0;i<x-2;i++){
                temp=temp->next;
            }
            Node*temp2=temp->next;
            if(temp2->next==NULL){
                temp->next=NULL;
            }
            else{
                temp->next=temp2->next;
                temp2->next->prev=temp;
            }
            free(temp2);
            return head;
        }
        
      //Your code here
    }
/*
Implement Stack using Linked List 
Basic Accuracy: 49.96% Submissions: 57521 Points: 1
Let's give it a try! You have a linked list and you have to implement the functionalities push and pop of stack using this given linked list. Your task is to use the class as shown in the comments in the code editor and complete the functions push() and pop() to implement a stack. 

Example 1:

Input: 
push(2)
push(3)
pop()
push(4) 
pop()
Output: 3 4
Explanation: 
push(2)    the stack will be {2}
push(3)    the stack will be {2 3}
pop()      poped element will be 3,
           the stack will be {2}
push(4)    the stack will be {2 4}
pop()      poped element will be 4
*/
void MyStack ::push(int x) 
{
    StackNode*temp=new StackNode(x);
    temp->next=top;
    top=temp;
    // Your Code
}

//Function to remove an item from top of the stack.
int MyStack ::pop() 
{if(top==NULL)return -1;
    int x=top->data;
top=top->next;
return x;
    // Your Code
}
/*
Delete without head pointer 
Easy Accuracy: 69.01% Submissions: 100k+ Points: 2
You are given a pointer/ reference to the node which is to be deleted from the linked list of N nodes. The task is to delete the node. Pointer/ reference to head node is not given. 
Note: No head reference is given to you. It is guaranteed that the node to be deleted is not a tail node in the linked list.

Example 1:

Input:
N = 2
value[] = {1,2}
node = 1
Output: 2
Explanation: After deleting 1 from the
linked list, we have remaining nodes
as 2.
*/
void deleteNode(Node *del)
    {
            Node*temp=del->next;
            del->data=temp->data;
            del->next=temp->next;
        
       // Your code here
    }
/*
Given a Matrix mat of N*N size, the task is to complete the function constructLinkedMatrix(), 
that constructs a 2D linked list representation of the given matrix.

Input : 2D matrix 
1 2 3
4 5 6
7 8 9

Output :
1 -> 2 -> 3 -> NULL
|    |    |
v    v    v
4 -> 5 -> 6 -> NULL
|    |    |
v    v    v
7 -> 8 -> 9 -> NULL
|    |    |
v    v    v
NULL NULL NULL
*/
Node*solve(int mat[MAX][MAX],int i,int j,int n){
    if(i>=n || j>=n)return NULL;
    Node*res=new Node(mat[i][j]);
    res->right=solve(mat,i,j+1,n);
    res->down=solve(mat,i+1,j,n);
    return res;
}
Node* constructLinkedMatrix(int mat[MAX][MAX], int n)
{
return solve(mat,0,0,n);
}
//Rotate doubly Linked List 
struct node*update(struct node*start,int p)
{
  node*temp=start;
  node*hex=start;
  for(int i=0;i<p-1;i++){
     temp=temp->next;
  }

start=temp->next;
start->prev=NULL;
temp->next=NULL;
node*q=start;
while(q->next!=NULL){
    q=q->next;
}
  hex->prev=q;
   q->next=hex;
   return start;
}
//REVERSE DOUBLY LINKED LIST
Node* reverseDLL(Node * head)
{
     if(head==NULL || head->next==NULL)
   return head;
  Node*curr=head;
  Node*pre=NULL;
  Node*nex=head->next;
  while(curr!=NULL){
      curr->prev=curr->next;
      curr->next=pre;
      pre=curr;
      curr=curr->prev;
  }
     return  pre;
}
    //Delete Middle of Linked List 
    Node* deleteMid(Node* head)
{
      if(head==NULL || head->next==NULL)
        return NULL;
    Node*slow=head;
    Node*fast=head;
    Node*prev=NULL;
    while(fast && fast->next){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    prev->next=slow->next;
    return head;
}
//Reverse a linked list
 struct Node* reverseList(struct Node *head)
    {
        if(!head && !head->next)return head;
        Node*curr=head;
        Node*nex=head;
        Node*prev=NULL;
        while(curr!=NULL){
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
        }
        return prev;
    }
    /*
    Remove duplicates from an unsorted linked list 
Easy Accuracy: 49.19% Submissions: 84542 Points: 2
Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted Linked List. 
When a value appears in multiple nodes, the node which appeared first should be kept, all others duplicates are to be removed.

Example 1:

Input:
N = 4
value[] = {5,2,2,4}
Output: 5 2 4
Explanation:Given linked list elements are
5->2->2->4, in which 2 is repeated only.
So, we will delete the extra repeated
elements 2 from the linked list and the
resultant linked list will contain 5->2->4
Example 2:

Input:
N = 5
value[] = {2,2,2,2,2}
Output: 2
Explanation:Given linked list elements are
2->2->2->2->2, in which 2 is repeated. So,
we will delete the extra repeated elements
2 from the linked list and the resultant
linked list will contain only 2.
    */
 Node * removeDuplicates( Node *head) 
    { if(head->next==NULL)
     return head;
        unordered_map<int,int>mp;
        Node*temp=head;
        Node*pre=NULL;
        while(temp!=NULL){
            if(mp.find(temp->data)!=mp.end()){
                pre->next=temp->next;
            }
            else{
                  mp[temp->data]++;
                   pre=temp;
            }
          
            temp=temp->next;
        }
        return head;
    }
