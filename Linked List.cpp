LINKED LIST:


DELETE ALTERNATE NODES
CHECKING CIRCULAR LINKED LIST
DELETE NODE IN DOUBLY LINKED LIST
IMPLEMENT STACK IN LINKED LIST
DELETE WITHOUT HEAD POINTER
MULTI -LINKED LIST
REVERSE DOUBLY LINKED LIST
DELETE MIDDLE OF LINKED LIST
REVERSE A LINKED LIST
REMOVE DUPLICATES (UNSORTED)
FIND LENGTH OF LOOP
INSERT IN A SORTED LINKED LIST
PAIRWISE SWAP ELEMENTS OF LINKED LIST
DELETION AND REVERSE IN CIRCULAR LINKED LIST
FUNCTION TO REVERSE A CIRCULAR LINKED LIST
SORTED INSERTION CIRCULAR LINKED LIST
CHECK IF LINKED LIST IS PALINDROME
DELETE N NODES AFTER M NODES OF LINKED LIST
ADD TWO NUMBERS 
LINKED LIST IN ZIGZAG FASHION
QUICKSORT FOR LINKED LIST
INTERSECTION OF LINKED LIST(Y-SHAPED)
ROTATE A LINKED LIST
REMOVE LOOP IN LINKED LIST
REVERSE ALTERNATE NODES IN LINKED LIST
FLATTENING OF LINKED LIST
INSERTION SORT FOR LINKED LIST
SWAP KTH NODE FROM BEGINNING AND END
REVERSE A LINKED LIST IN GROUPS OF GIVEN SIZE
REVERSE A SUBLIST OF A LINKED LIST
CLONE A LINKED LIST WITH NEXT AND RANDOM POINTER
MERGE K SORTED LINKED LISTS



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
Let's give it a try! You have a linked list and you have to implement the functionalities push and pop of stack using this given linked list. 
Your task is to use the class as shown in the comments in the code editor and complete the functions push() and pop() to implement a stack. 

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
    /*
    Check if Linked List is Palindrome 
Easy Accuracy: 39.25% Submissions: 100k+ Points: 2
Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Example 1:

Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.
    */    
  bool isPalindrome(Node *head)
    { int length=0;
        Node*curr=head;
        while(curr!=NULL){
           length++;
           curr=curr->next;
        }
        stack<int>s;
        Node*slow=head;
        Node*fast=head;
        while(slow && fast && fast->next){
            s.push(slow->data);
            slow=slow->next;
            fast=fast->next->next;
        }
       
        if(length%2==1)
        slow=slow->next;
        while(slow!=NULL){
        
            if(slow->data==s.top()){
                s.pop();
                slow=slow->next;
            }
            else{
                return 0;
            }
        }
        return 1;
    }
       
        /*
        Delete N nodes after M nodes of a linked list 
Easy Accuracy: 37.19% Submissions: 34904 Points: 2
Given a linked list, delete N nodes after skipping M nodes of a linked list until the last of the linked list.

Input:
First line of input contains number of testcases T.
For each testcase, first line of input contains number of elements in the linked list and next M and N respectively space separated.
The last line contains the elements of the linked list.

Output:
Function should not print any output to stdin/console.

User Task:
The task is to complete the function linkdelete() which should modify the linked list as required.

Example:
Input:
2
8
2 1
9 1 3 5 9 4 10 1
6
6 1
1 2 3 4 5 6

Output: 
9 1 5 9 10 1
1 2 3 4 5 6
        
        */
   void linkdelete(struct Node  *head, int M, int N)
    {
        unsigned int m=M-1, n=N;
        Node *itr=head;
        while(itr)
        {
            if(!m)
            {
                Node *temp=itr;
                while(n-- && temp)
                    temp=temp->next;
                if(itr && temp)
                  itr->next=temp->next;
                else
                    itr->next=nullptr;
                n=N;
                m=M;
            }
            m--;
            itr=itr->next;
        }
    } 
        
/*
Add two numbers represented by linked lists 
Easy Accuracy: 30.12% Submissions: 100k+ Points: 2
Given two numbers represented by two linked lists of size N and M. The task is to return a sum list.

The sum list is a linked list representation of the addition of two input numbers from the last.

Example 1:

Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).
*/
 Node*reverse(Node *h){
        Node *r=NULL;
        Node* p=h;
        Node* q=NULL;
        while(p){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        return q;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node*l1=reverse(first);
        Node*l2=reverse(second);
        Node*dummy=new Node(0);
        Node*temp=dummy;
        int c=0;
        while(l1!=NULL || l2!=NULL ||c){
            int sum=0;
               if(l1!=NULL){
            sum+=l1->data;
            l1=l1->next;
        }
        if(l2!=NULL){
            sum+=l2->data;
            l2=l2->next;
        }
        sum+=c;
            c=sum/10;
            Node*sumi=new Node(sum%10);
            temp->next=sumi;
            temp=temp->next;
        }
     Node*ans=reverse(dummy->next);
        return ans;
    }
   /*
   Linked List in Zig-Zag fashion 
Easy Accuracy: 51.51% Submissions: 11145 Points: 2
Given a Linked list, rearrange it such that converted list should be of the form a < b > c < d > e < f .. 
where a, b, c are consecutive data node of linked list and such that
the order of linked list is sustained.
For example: In 11 15 20 5 10 we consider only 11 20 5 15 10 because it satisfies the above condition and 
the order of linked list. 5 20 11 15 10 is not considered as it does not follow the order of linked list.

To maintain the order, keep swapping the adjacent nodes of the linked list (whenever required) to get the desired output.  

Example 1:

Input:
LinkedList: 1->2->3->4 
Output: 1 3 2 4
   */     
      void swap(Node *a,Node *b){
        int t = a->data;
        a->data = b->data;
        b->data = t;
    }
    Node *zigZag(Node* head)
    {
     // your code goes here
     Node *temp = head;
     int bit = 0;
     while(temp->next){
         if(bit){
             if(temp->data < temp->next->data) 
             swap(temp,temp->next);
             bit = 0;
         }
         else{
             if(temp->data > temp->next->data) swap(temp,temp->next);
             bit = 1;
         }
         temp = temp->next;
     }
     return head;
    }   
 //QUICK SORT LINKED LIST
    struct node*pivot(struct node*low,struct node*high){
   struct node* pvt = low, *curr = low->next, *prev= low;
   while(curr!=high->next){
       if(pvt->data>curr->data){
        
           swap(prev->next->data,curr->data);
              prev=prev->next;
       }
       curr=curr->next;
   }
   swap(prev->data,pvt->data);
   return prev;
}
void solve(node*low,node*high){
    if(!low || !high ||low==high){
        return;
    }
    node*pvt=pivot(low,high);
    solve(low,pvt);
    solve(pvt->next,high);
}
void quickSort(struct node **head) {
    if(!(*head)|| !(*head)->next)return ;
    struct node*high=*head;
    while(high->next)high=high->next;
    solve(*head,high);    
}
 /*
 Intersection Point in Y Shapped Linked Lists 
Medium Accuracy: 49.55% Submissions: 100k+ Points: 4
Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.
example 1:

Input:
LinkList1 = 3->6->9->common
LinkList2 = 10->common
common = 15->30->NULL
Output: 15
Explanation:
Y ShapedLinked List
 */       
  int intersectPoint(Node* head1, Node* head2)
{
    int length1=0;
    int length2=0;
    Node*p=head1;
    Node*q=head2;
    while(p!=NULL){
        length1++;
        p=p->next;
    }
    while(q!=NULL){
        length2++;
        q=q->next;
    }
    
    int res=abs(length1-length2);
    if(length1>length2){
        p=head1;
        q=head2;
    }
    else{
        p=head2;
        q=head1;
    }
    for(int i=0;i<res;i++){
        p=p->next;
    }
    while(p!=NULL && q!=NULL){
        if(p==q)return p->data;
        else{
            p=p->next;
            q=q->next;
        }
    }
    return -1;  
}      
/*
Rotate a Linked List 
Medium Accuracy: 33.33% Submissions: 100k+ Points: 4
Given a singly linked list of size N. 
The task is to left-shift the linked list by k nodes, where k is a given positive integer smaller than or equal to length of the linked list.

Example 1:

Input:
N = 5
value[] = {2, 4, 7, 8, 9}
k = 3
Output: 8 9 2 4 7
Explanation:
Rotate 1: 4 -> 7 -> 8 -> 9 -> 2
Rotate 2: 7 -> 8 -> 9 -> 2 -> 4
Rotate 3: 8 -> 9 -> 2 -> 4 -> 7
*/
 Node* rotate(Node* head, int k)
    {
        Node*ptr=head;
        if(head==NULL|| head->next==NULL)
        return head;
      for(int i=1;i<k;i++){
        ptr=ptr->next;
      }
      Node*curr=ptr;
      while(ptr->next!=NULL){
          ptr=ptr->next;
      }
      ptr->next=head;
      head=curr->next;
      curr->next=NULL;
    return head;
        // Your code here
    }       
/*
Remove loop in Linked List 
Medium Accuracy: 47.96% Submissions: 100k+ Points: 4
Given a linked list of N nodes such that it may contain a loop.

A loop here means that the last node of the link list is connected to the node at position X. If the link list does not have any loop, X=0.

Remove the loop from the linked list, if it is present.  


Example 1:

Input:
N = 3
value[] = {1,3,4}
X = 2
Output: 1
Explanation: The link list looks like
1 -> 3 -> 4
     ^    |
     |____|    
A loop is present. If you remove it 
successfully, the answer will be 1. 
*/
  void removeLoop(Node* head)
    {
        Node*slow=head;
        Node*fast=head;
        while(slow && fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)break;
        }
        if(slow==head){
            
            while(fast->next!=head){
                fast=fast->next;
            }
            fast->next=NULL;
        }
        else if(slow==fast){
            slow=head;
            while(slow->next!=fast->next){
                slow=slow->next;
                fast=fast->next;
            }
            fast->next=NULL;
            
        }
      /*
      Reverse alternate nodes in Link List 
Medium Accuracy: 50.78% Submissions: 11632 Points: 4
Given a linked list, you have to perform the following task:

Extract the alternative nodes starting from second node.
Reverse the extracted list.
Append the extracted list at the end of the original list.
â€‹Example 1:

Input:
LinkedList = 10->4->9->1->3->5->9->4
Output: 10 9 3 9 4 5 1 4
Explanation: Reversing the alternative
nodes from the given list, and then
appending them to the end of the list
results in a list with 
      */ 
       void rearrange(struct Node *odd)
    {
        struct Node *t=odd,*m=t->next,*r=t->next;
while(t && t->next && t->next->next!=NULL)
{
t->next=t->next->next;
t=t->next;
m->next=t->next;
m=t->next;
}
t->next=NULL;
m=r;
struct Node *next,*prev=NULL;
while(m!=NULL)
{
next=m->next;
m->next=prev;
prev=m;
m=next;

}
t->next=prev;
       }
      /*
      Flattening a Linked List 
Medium Accuracy: 33.91% Submissions: 69318 Points: 4
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
Note: The flattened list will be printed using the bottom pointer instead of next pointer.

 

Example 1:

Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation:
The resultant linked lists has every 
node in a single level.
(Note: | represents the bottom pointer.)
      */
      Node* merge(Node* a,Node*b)
    {
        if(a==NULL)
        return b;
        if(b==NULL)
        return a;
        if(a->data<b->data)
        {
            a->bottom=merge(a->bottom,b);
            return a;
        }
        else
        {
            b->bottom=merge(a,b->bottom);
            return b;
        }
    }
Node *flatten(Node *root)
{
    if(root==NULL|| root->next==NULL)
    return root;
    return merge(root,flatten(root->next));
   // Your code here
}
/*
  Insertion Sort for Singly Linked List 
  */
      // Your code
      Node* insertionSort(struct Node* head)
    {
        //code here
        Node *dummy=new Node(-1);
        Node*curr=head;
        while(curr!=NULL){
            Node *temp=curr->next;
            Node*prev=dummy;
            Node *nxt=dummy->next;
            while(nxt!=NULL){
                if(nxt->data>curr->data){
                    break;
                }
                prev=nxt;
                nxt=nxt->next;
            }
            curr->next=nxt;
            prev->next=curr;
            curr=temp;
            
        }
        return dummy->next;
    }
/*
Swap Kth nodes from ends 
Medium Accuracy: 46.75% Submissions: 26826 Points: 4
Given a singly linked list of size N, and an integer K. You need to swap the Kth node from the beginning and Kth node from the end of the linked list. 
Swap the nodes through the links. Do not change the content of the nodes.
Example 1:

Input:
N = 4,  K = 1
value[] = {1,2,3,4}
Output: 1
Explanation: Here K = 1, hence after
swapping the 1st node from the beginning
and end thenew list will be 4 2 3 1.

*/
      Node *swapkthnode(Node* head, int num, int K)
{
    
    if(K>num){
        return head;
    }
    int res=num-K;
    Node*first=head;
    Node*second=head;
    Node*prev=NULL;
    Node*prev2=NULL;
    for(int i=1;i<K;i++){
        prev=first;
        first=first->next;
    }
   // cout<<first->data<<endl;
    
    for(int i=0;i<res;i++){
        prev2=second;
        second=second->next;
    }
    if(K==1){
    second->next=first->next;
    prev2->next=first;
    first->next=NULL;
    head=second;
    }
    else if(K==num){
        prev->next=second;
        first->next=second->next;
         second->next=NULL;
        head=first;
        return head;
    }
  else{
    
      prev->next=second;
       prev2->next=first;
      Node*temp=first->next;
       first->next=second->next;
       second->next=temp;
       return head;
      
  }
    return head;
    // Your Code here
}
/*
Reverse a Linked List in groups of given size. 
Medium Accuracy: 45.83% Submissions: 100k+ Points: 4
Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list. 
If the number of nodes is not a multiple of k then left-out nodes, in the end, should be considered as a group and must be reversed (See Example 2 for clarification).

Example 1:

Input:
LinkedList: 1->2->2->4->5->6->7->8
K = 4
Output: 4 2 2 1 8 7 6 5 
Explanation: 
The first 4 elements 1,2,2,4 are reversed first 
and then the next 4 elements 5,6,7,8. Hence, the 
resultant linked list is 4->2->2->1->8->7->6->5.
*/
      // Your Code
      struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        struct node*p=head,*q=NULL,*r=NULL;
        int count=0;
        while(p && count<k){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
            count++;
        }
        //struct node*next=p;
        if(p){
        head->next=reverse(p,k);
        }
        return q;
    }
/*
Reverse a sublist of a linked list 
Hard Accuracy: 78.92% Submissions: 1537 Points: 8
Given a linked list and positions m and n. Reverse the linked list from position m to n.

Example 1:

Input :
N = 10
Linked List = 1->7->5->3->9->8->10
                      ->2->2->5->NULL
m = 1, n = 8
Output : 2 10 8 9 3 5 7 1 2 5 
Explanation :
The nodes from position 1 to 8 
are reversed, resulting in 
2 10 8 9 3 5 7 1 2 5.
*/
       Node* reverseBetween(Node* head, int m, int n)
    {
        
    Node*prev=NULL;
    Node*curr=head;
        int count=0;
    for(int i=1;i<m;i++){
        prev=curr;
        curr=curr->next;
        count++;
    }
   // cout<<prev->data<<endl;
       
    
     
        // next pointers
        Node* current =curr, *next = NULL;
        Node*cu=curr;
     Node*pre=NULL;
  
        while (current != NULL && count<n) {
            // Store next
            next = current->next;
 
            // Reverse current node's pointer
            current->next = pre;
 
            // Move pointers one position ahead.
            pre = current;
            current = next;
            count++;
        }
    
    if(m==1){
        head=pre;
        cu->next=current;
        return head;
    }
    prev->next= pre;
    cu->next=current;
      return head;
        //code here
    }
/*
Clone a linked list with next and random pointer 
Hard Accuracy: 49.62% Submissions: 34115 Points: 8
You are given a special linked list with N nodes where each node has a next pointer pointing to its next node. 
You are also given M random pointers, where you will be given M number of pairs denoting two nodes a and b  i.e. a->arb = b.

Construct a copy of the given list. 
The copy should consist of exactly N new nodes, where each new node has its value set to the value of its corresponding original node.
Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied 
list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the 
copied list, x.random --> y.

Return the head of the copied linked list.

ArbitLinked List1

Example 1:

Input:
N = 4, M = 2
value = {1,2,3,4}
pairs = {{1,2},{2,4}}
Output: 1
Explanation: In this test case, there
are 4 nodes in linked list.  Among these
4 nodes,  2 nodes have arbitrary pointer
set, rest two nodes have arbitrary pointer
as NULL. Second line tells us the value
of four nodes. The third line gives the
information about arbitrary pointers.
The first node arbitrary pointer is set to
node 2.  The second node arbitrary pointer
is set to node 4.
Example 2:

Input:
N = 4, M = 2
value[] = {1,3,5,9}
pairs[] = {{1,1},{3,4}}
Output: 1
Explanation: In the given testcase ,
applying the method as stated in the
above example, the output will be 1.
*/
      Node *copyList(Node *head)
    {
       Node*curr=head;
       while(curr){
          Node*temp=curr->next;
         Node*ptr=new Node(curr->data);
         ptr->next=temp;
         curr->next=ptr;
         curr=temp;
       }
       curr=head;
       while(curr){
           curr->next->arb=curr->arb?curr->arb->next:curr->arb;
           curr=curr->next->next;
       }
       Node*org=head;
       Node*copy=head->next;
       Node*temp=copy;
       while(org && copy){
           org->next=org->next->next;
           if(copy->next){
               copy->next=copy->next->next;
           }
          else{
              copy->next=NULL;
          }
           org=org->next;
           copy=copy->next;
       }
       return temp;
        //Write your code here
    }
      /*
      Merge K sorted linked lists 
Medium Accuracy: 41.42% Submissions: 37852 Points: 4
Given K sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list.

Example 1:

Input:
K = 4
value = {{1,2,3},{4 5},{5 6},{7,8}}
Output: 1 2 3 4 5 5 6 7 8
Explanation:
The test case has 4 sorted linked 
list of size 3, 2, 2, 2
1st    list     1 -> 2-> 3
2nd   list      4->5
3rd    list      5->6
4th    list      7->8
The merged list will be
1->2->3->4->5->5->6->7->8.
      
      */
  Node* merge(Node* a,Node*b)
    {
        if(a==NULL)
        return b;
        if(b==NULL)
        return a;
        if(a->data<b->data)
        {
            a->next=merge(a->next,b);
            return a;
        }
        else
        {
            b->next=merge(a,b->next);
            return b;
        }
    }
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int n)
    {
         Node* result=NULL;
       for(int i=0;i<n;i++)
       {
           result=merge(result,arr[i]);
       }
       return result;
      
    }   
