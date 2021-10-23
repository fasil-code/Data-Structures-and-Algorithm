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
/*
Evaluation of Postfix Expression 
Easy Accuracy: 53.28% Submissions: 24951 Points: 2
Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. 
Operators will only include the basic arithmetic operators like *, /, + and -.
Example 1:
Input: S = "231*+9-"
Output: -4
Explanation:
After solving the given expression, 
we have -4 as result.
*/
int evaluatePostfix(string S)
    {
        stack<int>s;
        for(int i=0;i<S.size();i++){
            if(S[i]>='0' && S[i]<='9' ){
                s.push(S[i]-48);
            }
            else{
                int res=0;
                int x=s.top();
                s.pop();
                int y=s.top();
                s.pop();
                if(S[i]=='*'){
                    res=x*y;
                }
                else if(S[i]=='+'){
                    res=x+y;
                }
              else if(S[i]=='/'){
                    res=y/x;
                }  else if(S[i]=='-'){
                    res=y-x;
                }
            s.push(res);
            }
        }
        return s.top();    
    }
//sort a stack
void insert(stack<int>&s,int temp){
    if(s.empty()|| temp>=s.top()){
         s.push(temp);
    }
    else{
        int ptr=s.top();
        s.pop();
        insert(s,temp);
        s.push(ptr);
    }
    
}
void SortedStack :: sort()
{
    if(s.empty()){
        return;
    }
    else{
        int temp=s.top();
        s.pop();
        sort();
        insert(s,temp);
    }
 
}

