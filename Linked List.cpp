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
/*Find length of Loop 
Easy Accuracy: 43.66% Submissions: 61315 Points: 2
Given a linked list of size N. 
    The task is to complete the function countNodesinLoop() that 
    checks whether a given Linked List contains a loop or not and if the loop is present then return the count of nodes in a loop or else return 0.
        C is the position of the node to which the last node is connected. If it is 0 then no loop.
Example 1:

Input:
N = 10
value[]={25,14,19,33,10,21,39,90,58,45}
C = 4
Output: 7
Explanation: The loop is 45->33. So
length of loop is 33->10->21->39->
90->58->45 = 7. The number 33 is
connected to the last node to form the
loop because according to the input the
4th node from the beginning(1 based
index) will be connected to the last
node for the loop.*/
int countNodesinLoop(struct Node *head)
{
 Node*slow=head;
        Node*fast=head;
        int flag=0;
        while(slow && fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
            flag=1;
            break;
            }
        }
        if(flag==0){
            return 0;
        }
    int l=1;
    slow=slow->next;
    while(slow!=fast){
        l++;
        slow=slow->next;
    }
    return l;
}
/*//Insert in a Sorted List 
Easy Accuracy: 43.83% Submissions: 37881 Points: 2
Given a linked list sorted in ascending order and an integer called data, insert data in the linked list such that the list remains sorted.

Example 1:

Input:
LinkedList: 25->36->47->58->69->80
data: 19
Output: 19 25 36 47 58 69 80
*/
Node *sortedInsert(struct Node* head, int data) {
        Node*temp=new Node(data);
        Node*curr=head;
        Node*prev=NULL;
        if(head==NULL|| head->data>data){
            temp->next=head;
            head=temp;
       return head;
        }
      else
{
while (curr->next != NULL and curr->next->data < temp->data)
{
curr = curr->next;
}

temp->next = curr->next;
curr->next = temp;
return head;
}
  /*
  Pairwise swap elements of a linked list 
Easy Accuracy: 43.06% Submissions: 66985 Points: 2
Given a singly linked list of size N. The task is to swap elements in the linked list pairwise.
For example, if the input list is 1 2 3 4, the resulting list after swaps will be 2 1 4 3.
Note: You need to swap the nodes, not only the data. If only data is swapped then driver will print -1.

Example 1:

Input:
LinkedList: 1->2->2->4->5->6->7->8
Output: 2 1 4 2 6 5 8 7
Explanation: After swapping each pair
considering (1,2), (2, 4), (5, 6).. so
on as pairs, we get 2, 1, 4, 2, 6, 5,
8, 7 as a new linked list.
  */
     Node* pairWiseSwap(struct Node* head) 
    {
        
         if(head==NULL ||head->next==NULL){
           return head;
       }
       Node*temp1=head;
       Node*temp2=temp1->next;
       Node*temp3;
       Node*prev=NULL;
     Node*modified =temp2;
       while(temp1!=NULL && temp1->next!=NULL){
           temp2=temp1->next;
           temp3=temp2->next;
           temp2->next=temp1;
           temp1->next=temp3;
           if(prev!=NULL){
               prev->next=temp2;
           }
           prev=temp1;
           temp1=temp3;
       }
       return modified;
   
    }
    //Deletion and Reverse in Circular Linked List
    void deleteNode(struct Node **head, int key)
{
Node*curr=*head;

if((*head)->data==key){
    Node*temp=*head;

    while(temp->next!=*head){
        temp=temp->next;
    }
    Node*t=(*head)->next;
    temp->next=(*head)->next;
    *head=t;
}
while(curr->next!=*head && curr->data!=key){
    pre=curr;
    curr=curr->next;
}
//cout<<pre->data<<endl;
//cout<<curr->data<<endl;
pre->next=curr->next;

}

/* Function to reverse the linked list */
 void reverse(struct Node** head_ref)
{
    if (*head_ref == NULL)
        return;

    Node* prev = NULL;
    Node* current = *head_ref;
    Node* next;
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != (*head_ref));

    (*head_ref)->next = prev;
    *head_ref = prev;
// Your code goes here
}
//Sorted insert for circular linked list 
    Node *sortedInsert(Node* head, int data)
    {
        
    Node*ptr=new Node(data);
    if(head==NULL){
        return ptr;
    }
    else if(head->data>ptr->data){
        Node*curr=head;
        while(curr->next!=head){
            curr=curr->next;
        }
        curr->next=ptr;
        ptr->next=head;
        head=ptr;
        return head;
        
    }
    else{
    Node*p=head;
    while(p->next->data<ptr->data){
        p=p->next;
    }
    ptr->next=p->next;
    p->next=ptr;
    return head;
    }
        
