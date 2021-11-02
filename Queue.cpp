QUEUE:
IMPLEMENTING QUEUE USING ARRAY
IMPLEMENT QUEUE USING LINKED LIST
GENERATE BINARY NUMBERS
MINIMUM COST OF ROPES
FIRST NEGATIVE NUMBER IN EVERY WINDOW SIZE OF K
MAXIMUM OF ALL SUBAARAYS OF SIZE K WINDOW
FIRST NON REPEATING CHRACTER IN A STREAM
CIRCULAR TOUR

//IMPLEMENTING QUEUE USING ARRAY
void MyQueue :: push(int x)
{
    cout<<rear<<endl;
arr[rear++]=x;
        // Your Code
}


int MyQueue :: pop()
{
    if(front>=rear){
        return -1;
        
    }
    else{
    return arr[front++];
 
    }
      //IMPLEMENT QUEUE USING LINKED LIST
  void MyQueue:: push(int x)
{ QueueNode*temp=new QueueNode(x);
    if(rear==NULL){
        front=rear=temp;
        return;
    }
   
    rear->next=temp;
    rear=temp;
        // Your Code
}


int MyQueue :: pop()
{
    if(front==NULL)return -1;
    if(front==rear){
        int x=front->data;
        front=rear=NULL;
        return x;
    }
    int res=front->data;
    front=front->next;
    return res;    
}
/*
Generate Binary Numbers 
Basic Accuracy: 58.36% Submissions: 16332 Points: 1
Given a number N. The task is to generate and print all binary numbers with decimal values from 1 to N.

Example 1:

Input:
N = 2
Output: 
1 10
Explanation: 
Binary numbers from
1 to 2 are 1 and 10.
*/  
  vector<string> generate(int N)
{
    vector<string>v;
queue<string>q;
q.push("1");
while(N--){
    string x=q.front();
    v.push_back(q.front());
    string y=x;
    q.pop();
    q.push(x.append("0"));
    q.push(y.append("1"));
    
}
return v;
}
/*
Minimum Cost of ropes 
Easy Accuracy: 50.05% Submissions: 38315 Points: 2
There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths.
The task is to connect the ropes with minimum cost.

Example 1:

Input:
n = 4
arr[] = {4, 3, 2, 6}
Output: 
29
Explanation:
For example if we are given 4
ropes of lengths 4, 3, 2 and 6. We can
connect the ropes in following ways.
1) First connect ropes of lengths 2 and 3.
Now we have three ropes of lengths 4, 6
and 5.
2) Now connect ropes of lengths 4 and 5.
Now we have two ropes of lengths 6 and 9.
3) Finally connect the two ropes and all
ropes have connected.
Total cost for connecting all ropes is 5
+ 9 + 15 = 29. This is the optimized cost
for connecting ropes. Other ways of
connecting ropes would always have same
or more cost. For example, if we connect
4 and 6 first (we get three strings of 3,
2 and 10), then connect 10 and 3 (we get
two strings of 13 and 2). Finally we
connect 13 and 2. Total cost in this way
is 10 + 13 + 15 = 38.
*/  
   long long minCost(long long arr[], long long n) {
long long ans=0;
     priority_queue<long long,vector<long long>,greater<long long>>q;
     for(int i=0;i<n;i++){
      q.push(arr[i]);
     }
while(q.size()!=1){
    long long a=q.top();
    q.pop();
    long long b=q.top();
    q.pop();
    ans+=a+b;
    q.push(a+b);
}
return ans;
       
    }
    /*
    First negative integer in every window of size k 
Easy Accuracy: 54.27% Submissions: 15511 Points: 2
Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

 

Example 1:

Input : 
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output : 
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6
    */
    vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int k) {
        
        vector<long long>v;
        queue<long long >q;
       long long int i=0,j=0;
       while(j<N){
           if(A[j]<0){
               q.push(A[j]);
           }
           if(j-i+1<k){
               j++;
           }
           else if(j-i+1==k){
               if(q.empty()){
                   v.push_back(0);
               }
               else{
                   v.push_back(q.front()); 
                   
               }
               
               if(!q.empty() && A[i]<0){
                   q.pop();
               }
               i++;
               j++;
           }   
       }
         return v; }    
    
    /*
    Maximum of all subarrays of size k 
Medium Accuracy: 44.42% Submissions: 50920 Points: 4
Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.

Example 1:

Input:
N = 9, K = 3
arr[] = 1 2 3 1 4 5 2 3 6
Output: 
3 3 4 5 5 5 6 
Explanation: 
1st contiguous subarray = {1 2 3} Max = 3
2nd contiguous subarray = {2 3 1} Max = 3
3rd contiguous subarray = {3 1 4} Max = 4
4th contiguous subarray = {1 4 5} Max = 5
5th contiguous subarray = {4 5 2} Max = 5
6th contiguous subarray = {5 2 3} Max = 5
7th contiguous subarray = {2 3 6} Max = 6
    */
     vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        deque<int> dq;
        vector<int> res;
        int i = 0, j = 0;
        while(j < n)
        {
            while(!dq.empty() && dq.back() < arr[j])
                dq.pop_back();
                
            dq.push_back(arr[j]);
            
            if(j - i + 1 == k)
            {
            res.push_back(dq.front());
                if(arr[i] == dq.front())
                {
                    dq.pop_front();
                }
                i++;
                j++;
            }
            else j++;
        }
        return res;
       
    }
/*
First non-repeating character in a stream 
Medium Accuracy: 51.34% Submissions: 29493 Points: 4
Given an input stream of A of n characters consisting only of lower case alphabets. The task is to find the first non repeating character, each time a character is inserted to the stream. If there is no such character then append '#' to the answer.
 

Example 1:

Input: A = "aabc"
Output: "a#bb"
Explanation: For every character first non
repeating character is as follow-
"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - first non-repeating character is 'b'
*/
  	string FirstNonRepeating(string A){
		    string s = "";
queue<char> q;
vector<int> v(26, 0);
for (auto i : A) {
q.push(i);
v[i - 'a']++;

while (!q.empty() and v[q.front() - 'a']>1) q.pop();
s += q.empty()?'#':q.front();
}
return s;
		}
  /*
  Circular tour 
Medium Accuracy: 33.91% Submissions: 81187 Points: 4
Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.

Example 1:

Input:
N = 4
Petrol = 4 6 7 4
Distance = 6 5 3 5
Output: 1
Explanation: There are 4 petrol pumps with
amount of petrol and distance to next
petrol pump value pairs as {4, 6}, {6, 5},
{7, 3} and {4, 5}. The first point from
where truck can make a circular tour is
2nd petrol pump. Output in this case is 1
(index of 2nd petrol pump).
  */
    int tour(petrolPump p[],int n)
    {
        int sum=0;
        int negative_sum=0;
           int start=0;
        for(int i=0;i<n;i++){
         
            sum+=p[i].petrol-p[i].distance;
            if(sum<0){
                start=i+1;
                negative_sum+=sum;
                sum=0;
            }
        }
        if(sum+negative_sum>=0){
            return start;
        }
        return -1;
      
    }
    
