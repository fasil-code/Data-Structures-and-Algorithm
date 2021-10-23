//IMPLEMENT STACK USING ARRAY
void MyStack :: push(int x)
{
    arr[++top]=x;
    // Your Code
}
int MyStack :: pop()
{
    if(top==-1){
        return -1;
    }
    int x=arr[top];
    top=top-1;
    return x;
    // Your Code       
}
//IMPLEMENT STACK USING LINKED LIST
void MyStack ::push(int x) 
{
    StackNode*new_node=new StackNode(x);
    new_node->next=top;
    top=new_node;
}
int MyStack ::pop() 
{
   if(top==NULL){
       return -1;
   } 
   int result=top->data;
   top=top->next;
   return result;
    // Your Code
}
//Queue Reversal 
queue<int> rev(queue<int> q)
{
    stack<int>s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
     while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    return q;
}
