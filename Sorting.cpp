Sorting :
/*
CHECK IF TWO ARRAYS ARE EQUAL
Given two arrays A and B of equal size N, the task is to find if given arrays are equal or not. 
Two arrays are said to be equal if both of them contain same set of elements, arrangements (or permutation) of elements may be different though.
Note : If there are repetitions, then counts of repeated elements must also be same for two array to be equal.

Example 1:

Input:
N = 5
A[] = {1,2,5,4,0}
B[] = {2,4,5,0,1}
Output: 1
Explanation: Both the array can be 
rearranged to {0,1,2,4,5}
*/
bool check(vector<ll> A, vector<ll> B, int N) {
        if(A.size()!=B.size())return false;
        unordered_map<ll,ll>mp;
       for(ll i=0;i<A.size();i++){
           mp[A[i]]++;
           mp[B[i]]--;
           
       } 
       for(auto x:mp){
           if(x.second!=0){
               return false;
           }
       } 
       return true;
        //code here
    }
/*
MAXIMUM PRODUCT OF TWO NUMBERS
Given an array Arr of size N with all elements greater than or equal to zero. Return the maximum product of two numbers possible.

Example 1:

Input: 
N = 6
Arr[] = {1, 4, 3, 6, 7, 0}  
Output: 42
*/
int maxProduct(int arr[], int n) {
	    
        int maxi1 = INT_MIN;
        int maxiIndex;
        
        for(int i = 0; i < n; i++)
        {
            if(arr[i] > maxi1)
            {
                maxi1 = arr[i];
                maxiIndex = i;
            }
        }
        
        int maxi2 = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            if(maxiIndex != i && arr[i] > maxi2)
            {
                maxi2 = arr[i];
            }
        }
        
        return (maxi1 * maxi2);
    }
/*
Given an array arr[] of N distinct integers, output the array in such a way that the first element is first maximum and the second element is the first minimum, and so on.
 
ALTERNATIVE SORT
Example 1:

Input: N = 7, arr[] = {7, 1, 2, 3, 4, 
                                5, 6}
Output: 7 1 6 2 5 3 4
Explanation:The first element is first 
maximum and second element is first 
minimum and so on.


*/
	vector<int> alternateSort(int arr[], int N)
	{
	    sort(arr,arr+N);
	    vector<int>res;
	   int i=0;
	   int j=N-1;
	   while(i<=N/2 && j>=N/2){
	        if(i!=j)
	       res.push_back(arr[j]);
	       j--;
	      
	       res.push_back(arr[i]);
	       i++;
	   }
	   return res;
	    // Your code goes here
	}


/*
FIND TRIPLETS FAMILY
Given an array A of integers. Find three numbers such that sum of two elements equals the third element and return the triplet in a container result, 
if no such triplet is found return the container as empty.
3
5
1 2 3 4 5
3
3 3 3
6
8 10 16 6 15 25
*/
sort(arr, arr + n);
    
    for(int i = n - 1; i >= 2; i--)
    {
        int start = 0, end = i - 1;
        
        while(start <  end)
        {
            if(arr[start] + arr[end] == arr[i])
            {
                result.push_back(arr[start]);
                result.push_back(arr[end]);
                result.push_back(arr[i]);
                
                return result;
            }
            
            if(arr[start] + arr[end] > arr[i])
            {
                end--;
            }
            else
            {
                start++;
            }
        }
    }
    
    return result;
}
/*
SORTING EMPLOYEE
You have records of employee name as string (Ename) and salary as positive integer (S).
You have to sort the records on the basis of employee salary, if salary is same then use employee name for comparison.

Example 1:

Input: N = 2
arr[] = {{xbnnskd, 100}, {geek, 50}}
Output: {geek 50}, {xbnnskd 100}
Explanation: geek has lowest salary 
as 50 and xbnnskd has more salary.
*/

static bool comparator(node &a,node &b)
	{
	    return (a.salary<b.salary || (a.salary==b.salary && a.name<=b.name));
	}
	void sortRecords(node arr[], int n)
	{
	    sort(arr,arr+n,comparator);
	}
	    // code here
/*
Sort an array of 0s, 1s and 2s
Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.
Example 1:

Input: 
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated 
into ascending order.
*/

 void sort012(int a[], int n)
    {
       int i=0;
       int j=n-1;
        int mid=0;
       while(mid<=j){
           if(a[mid]==0){
               swap(a[mid],a[i]);
               i++;
               mid++;
           }
           else if(a[mid]==2){
               swap(a[mid],a[j]);
               j--;
           }
           else{
               mid++;
           }
       }   
    }
    // Counting sort
int Max(string arr,int n){
        int max=INT_MIN;
        for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
        }
        return max;
    }
    string countSort(string A){
        // code here
        int n=A.size();
        int max = Max(A, n);
 
    // Create count array
    int* count = new int [max + 1];
 
    // Initialize count array with 0
    for (int i=0; i<max+1; i++){
        count[i] = 0;
    }
 
    // Update count array values based on A values
    for (int i=0; i<n; i++){
        count[A[i]]++;
    }
 
    // Update A with sorted elements
    int i = 0;
    int j = 0;
    while (j < max+1){
        if (count[j] > 0){
            A[i++] = j;
            count[j]--;
        } else {
            j++;
        }
    }
  return A;
    // Delete heap memory
    delete [] count;
}
/*
UNION OF TWO LINKED LISTS

*/
struct Node* makeUnion(struct Node* head1, struct Node* head2)
{
    
    set<int>s;
Node*temp1=head1;
Node*temp2=head2;
while(temp1!=NULL){
    s.insert(temp1->data);
    temp1=temp1->next;
}
   while(temp2!=NULL){
    s.insert(temp2->data);
    temp2=temp2->next;
} 
struct Node*res=new Node(0);
struct Node*ptr=res;

for(auto x:s){
    Node*temp=new Node(x);
    res->next=temp;
    res=temp;
}
ptr=ptr->next;
return ptr;   // code here
}
/*Top K Frequent Elements in Array -
Given a non-empty array of integers, find the top k elements which have the highest frequency in the array. 
If two numbers have the same frequency then the larger number should be given preference. 

Example 1:

Input:
nums = {1,1,1,2,2,3},
k = 2
Output: {1, 2}

*/

  vector<int> topK(vector<int>& nums, int k) {
        unordered_map<int,int>v;
        for(int i=0;i<nums.size();i++){
            v[nums[i]]++;
        }
        vector<pair<int,int>>s;
        for(auto x:v){
        s.push_back({x.second,x.first});
        }
        sort(s.begin(),s.end());
    vector<int>res;
    for(int i=s.size()-1;i>=0;i--){
        if(k>0)
        res.push_back(s[i].second);
        k--;
    }
    return res;
        // Code here
    }	
Selection Sort :
in selection sort the concept is to find minimum element or maximum element in each iteration.
it is your choice to though.Now lets select maximum element strategy
her we traverse reverse and select first element we check is there any element behind it which is greater than it .
if we found we return its index and swap maximum element with current element.
  int select(int arr[], int i)
    {
         int maxi=i;
        
    for( i-1;i>=0;i--){
        if(arr[i]>arr[maxi]){
            maxi=i;
        }
    }
    return maxi;
    // code here such that selecionSort() sorts arr[]
}
 
    void selectionSort(int arr[], int n)
    {
        
    for(int i=n-1;i>=0;i--){
        int res=select(arr,i);
        swap(arr[i],arr[res]);
    }
     
    }
	
/*
 
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.
Example: 
First Pass: 
( 5 1 4 2 8 ) –> ( 1 5 4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1. 
( 1 5 4 2 8 ) –>  ( 1 4 5 2 8 ), Swap since 5 > 4 
( 1 4 5 2 8 ) –>  ( 1 4 2 5 8 ), Swap since 5 > 2 
( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ), Now, since these elements are already in order (8 > 5), algorithm does not swap them.
Second Pass: 
( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ) 
( 1 4 2 5 8 ) –> ( 1 2 4 5 8 ), Swap since 4 > 2 
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 
( 1 2 4 5 8 ) –>  ( 1 2 4 5 8 ) 
Now, the array is already sorted, but our algorithm does not know if it is completed. The algorithm needs one whole pass without any swap to know it is sorted.
Third Pass: 
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 
 
*/

void bubbleSort(int arr[], int n)
{
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
/*
GIven two different arrays A and B of size N and M, the task is to merge the two arrays which are unsorted into another array which is sorted.
Example 1:
Input: N = 3, M = 3
A[] = {10, 5, 15}
B[] = {20, 3, 2}
Output: 2 3 5 10 15 20
Explanation: After merging both the 
array's and sorting it with get the 
desired output.  
*/	
	void sortedMerge(int a[], int b[], int res[],int n, int m)
	{
	 sort(a,a+n);
	    sort(b,b+m);
	    int i=0;
	    int j=0;
	    int c=0;
	    while(i<n && j<m){
	        if(a[i]<=b[j]){
	            res[c++]=a[i++];
	        }
	        else{
	            res[c++]=b[j++];
	        }
	    }
	    while(i<n){
	        res[c++]=a[i++];
	    }
	     while(j<m){
	        res[c++]=b[j++];
	     }
	}
/*Intersection of two sorted Linked lists 
Easy Accuracy: 29.44% Submissions: 53587 Points: 2
Given two lists sorted in increasing order, create a new list representing the intersection of the two lists. The new list should be made with its own memory — the original lists should not be changed.
Note: The list elements are not necessarily distinct.

Example 1:

Input:
L1 = 1->2->3->4->6
L2 = 2->4->6->8
Output: 2 4 6
Explanation: For the given first two
linked list, 2, 4 and 6 are the elements
in the intersection.	
	*/
Node* findIntersection(Node* head1, Node* head2)
{
    Node*temp1=head1;
    Node*temp2=head2;
    Node*head=new Node(0);
    Node*ptr=head;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data==temp2->data){
             Node*gif=new Node(temp1->data);
           head->next=gif;
           head=gif;
           temp1=temp1->next;
             temp2=temp2->next;
        }
        else if(temp1->data>temp2->data){
           
            temp2=temp2->next;
        }
        else{
           temp1=temp1->next; 
        }
    }
  return ptr->next;
    // Your Code Here
}	
/*
Given two sorted matrices mat1 and mat2 of size N x N of elements. Given a value x. The problem is to count all pairs from both matrices whose sum is equal to x.

Note: The pair has an element from each matrix. Matrices are strictly sorted which means that matrices are sorted in a way such that all elements in a row are sorted in increasing order and for row ‘i’, where 1 <= i <= n-1, the first element of row 'i' is greater than the last element of row 'i-1'.

Example 1:

Input: 
N = 3, x = 21
mat1 = { {1 5 6}
         {8 10 11}
         {15 16 18} }
mat2 = { {2 4 7}
         {9 10 12}
         {13 16 20} }
OUTPUT: 4
Explanation: The pairs are (1, 20),
            (5, 16), (8, 13), (11, 10).
*/
     int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	     int i,j;
	    int k,l;
	    i = j = 0;
	    k = l = n - 1;
	    int ret = 0;
	    while(i < n and k >= 0){
	       if(arr[i][j] + arr1[k][l] == x){
	           ret++;
	           j++;
	       } 
	       else if(arr[i][j] + arr1[k][l] > x){
	           l--;
	       }
	       else if(arr[i][j] + arr1[k][l] < x){
	           j++;
	       }
	      if(j == n){
	           j = 0;
	           i++;
	       }
	       if(l < 0){
	           l =  n - 1;
	           k--;
	       }
	    }
	    return ret;
	}	
	/*
	Largest Even Number 
	Given an integer S. Find the largest even number that can be formed by rearranging the digits of S.

Note: In case the number does not contain any even digit then output the largest odd number possible.
	*/
	  string LargestEven(string S){
        sort(S.begin(),S.end());
        reverse(S.begin(),S.end()); //Sort the string and check the last digit and if it's odd then swap with a even digit and again sort left portion. 
                                      //If no even digit present then finds the largest odd number by sorting the string
            if(S[S.size()-1]%2!=0){
                int j=S.size()-1;
                while(j>=0){
                    if(S[j]%2==0){
                        swap(S[S.size()-1],S[j]);
                        break;
                    }
                    else{
                        j--;
                    }
                    
                }
            }
        sort(S.begin(),S.end()-1,greater<int>());
    
        return S; 
    }  
	
	/*
	Shop in Candy Store 
	In a candy store, there are N different types of candies available and the prices of all the N different types of candies are provided to you.
You are now provided with an attractive offer.
You can buy a single candy from the store and get at most K other candies ( all are different types ) for free.
Now you have to answer two questions. Firstly, you have to find what is the minimum amount of money you have to spend to buy all the N different candies.
Secondly, you have to find what is the maximum amount of money you have to spend to buy all the N different candies.
In both the cases you must utilize the offer i.e. you buy one candy and get K other candies for free.
Input:
N = 4
K = 2
candies[] = {3 2 1 4}

Output:
3 7

Explanation:
As according to the offer if you buy 
one candy you can take at most two 
more for free. So in the first case, 
you buy the candy which costs 1 and 
takes candies worth 3 and 4 for free, 
also you buy candy worth 2 as well.
So min cost : 1+2 =3.
In the second case, you can buy the 
candy which costs 4 and takes candies 
worth 1 and 2 for free, also you need 
to buy candy worth 3 as well. 
So max cost : 3+4 =7.
	*/'
  vector<int>v;
        sort(candies,candies+N);
       int n=N; 
    int mini=0,ans=0;
    for(int i=0;i<N;i++){
        ans+=candies[i];
        N=N-K;
    }
    v.push_back(ans);
    int j=0;
       for(int i=n-1;i>=j;i--){
        mini+=candies[i];
        j=j+K;
    }   
        
         v.push_back(mini); 
         return v;	
}

/*
Equalize an array in minimum operations 
You are given an array of N integers A[0], A[1], …, A[N-1], and an integer k. Your task is to make all the elements of the given array equal in a minimum number of ‘moves’.
All the elements of the array are non-negative. In each ‘move,’ you may add or subtract k from any element of the array. Give the answer modulo 109+7.

Example 1:

Input: N = 4, k = 2
A = {7, 5, 21, 17}
Output: 13
Explaination: We can add k = 2 to A[1] 
once and subtract k = 2 from A[2] seven 
times and from A[3] five times.The 
resulting array would be- 7 7 7 7. 
Number of moves = 1 + 7 + 5 = 13.
*/
int equalizeArray(int N, int k, int arr[]){
        long long  steps=0;
        sort(arr,arr+N);
        int mid=0;
        if(N%2==1){
            mid=N/2;
        }
        else{
            mid=N/2-1;
        }
        for(long long int i=0;i<N;i++){
    
            if(  (abs(arr[i]-arr[mid]))%k!=0){
                return -1;
            }
        }
        for(long long int i=0;i<N;i++){
        long long  diff=abs(arr[i]-arr[mid]);
            steps+=(diff/k)%1000000007;
        }
        return steps%1000000007;
        // code here
    }

/*
Minimum Distinct Ids 
Easy Accuracy: 46.96% Submissions: 1180 Points: 2
Given an array of items, the i'th index element denotes the item id’s and given a number m,
the task is to remove m elements such that there should be minimum distinct id’s left. Print the number of distinct id’s.
*/
// your cod here
int distinctIds(int arr[], int n, int m)
    {
        
         map<int,int>mp;
         vector<pair<int, int>> v;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(auto x:mp){
            v.push_back({x.second, x.first});
        }
        sort(v.begin(),v.end());
        int count=0;
        int size=v.size();
	
        for(int i=0;i<size;i++){
           if (v[i].first <= m) {
            m -= v[i].first;
            count++;
        }
        else return size-count;
        }
        return size-count;
    }
/*
Next Greater Even Number 
Given a positive integer X. The task is to find the smallest even number E such that
E > X and all digits in X and E are same.

Note: All the digits in X should be same with digits in E.

 

Example 1:

Input:
X = 34722641
Output:
34724126
Explanation:
Next greater number with same 
digits as in input is 34724126.
*/
 long long getNextEven(string s)
    {
      long long x = stoll(s);
      while(next_permutation(s.begin(),s.end())){
     int index=s[s.length()-1]-'0';
      if(index%2==0 && stoll(s)>x){
          return stoll(s);
      }
      }
      return -1;
 }
/*
Rope Cutting 
Easy Accuracy: 77.36% Submissions: 583 Points: 2
You are given N ropes. A cut operation is performed on ropes such that all of them are reduced by the length of the smallest rope. 
Display the number of ropes left after every cut operation until the length of each rope is zero.

Example 1:

â€‹Input : arr[ ] = {5, 1, 1, 2, 3, 5}
Output : 4 3 2
Explanation:
In the first operation, the minimum ropes 
are 1 So, we reduce length 1 from all of 
them after reducing we left with 4 ropes and 
we do the same for rest.
*/
   vector<int> RopeCutting(int arr[], int n)
    {
  sort(arr,arr+n);
int cnt = 1;
int temp = arr[0];
int lcnt = 0;
vector<int> res;
for(int i = 1; i < n; i++)
{
if(temp == arr[i])cnt++;
else
{
res.push_back(n - (cnt+lcnt));
lcnt += cnt;
temp = arr[i];
cnt = 1;
}
}
return res;  
  }
/*
Given Pointer/Reference to the head of a doubly linked list of N nodes, the task is to Sort the given
doubly linked list using Merge Sort in both non-decreasing and non-increasing order.

Example 1:

Input:
N = 8
value[] = {7,3,5,2,6,4,1,8}
Output:
1 2 3 4 5 6 7 8
8 7 6 5 4 3 2 1
Explanation: After sorting the given
linked list in both ways, resultant
matrix will be as given in the first
two line of output, where first line
is the output for non-decreasing
order and next line is for non-
increasing order.
*/

  struct Node*split(Node*head){
    if(head==NULL){
        return head;
    }
    Node*slow=head;
    Node*fast=head;
    while(slow && fast && fast->next && fast->next->next != NULL){
     slow=slow->next;
     fast=fast->next->next;
    }
Node*head2=slow->next;
head2->prev=NULL;
slow->next=NULL;
return head2;

}
Node*merge(Node*first,Node*second){
 if(first==NULL){
     return second;
 }   
if(second==NULL){
     return first;
 }   
   if(first->data<second->data){
         first->next = merge(first->next,second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
   }
   else{
       second->next=merge(first,second->next);
       second->next->prev=second;
       second->prev=NULL;
       return second;
   }
   
   
    
}
struct Node *sortDoubly(struct Node *head)
{
 if(head==NULL || !head->next){
     return head;
 }
 Node*hea=head;
 Node*temp=split(hea);
 hea=sortDoubly(hea);
 temp=sortDoubly(temp);
 
return  merge(hea,temp);

}
/*Minimum Swaps to Sort 
Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.
Example 1:
Input:
nums = {2, 8, 5, 4}
Output:
1
Explaination:
swap 8 with 4.
*/
	int minSwaps(vector<int>&arr)
	{
	    int n=arr.size();
	    vector<pair<int,int>>v;
	    for(int i=0;i<n;i++){
	        v.push_back({arr[i],i});
	    }
	    sort(v.begin(),v.end());
	    int count=0;
	    for(int i=0;i<n;i++){
	     if(v[i].second!=i){
	      swap(v[i], v[v[i].second]);
	      count++; 
	           i--;
	        }
	    }
	    return count;
/*	}
Sorting Elements of an Array by Frequency 
Medium Accuracy: 47.44% Submissions: 26118 Points: 4
Given an array of integers, sort the array according to frequency of elements. That is elements that have higher frequency come first. If frequencies of two elements are same, then smaller number comes first.

Example 1:

Input:
N = 5
A[] = {5,5,4,6,4}
Output: 4 4 5 5 6
Explanation: The highest frequency here is
2. Both 5 and 4 have that frequency. Now
since the frequencies are same then 
smallerelement comes first. So 4 4 comes 
firstthen comes 5 5. Finally comes 6.
The output is 4 4 5 5 6.
*/
		 static  bool comp(pair<int,int>a,pair<int,int>b){
    if(a.first == b.first) 
        {
            return a.second < b.second;
            
        }
         return a.first > b.first;
    }
    vector<int> sortByFreq(int arr[],int n)
    {
       unordered_map<int,int>mp;
       for(int i=0;i<n;i++)
       mp[arr[i]]++;
       vector<pair<int,int>>v;
       for(auto x:mp){
           v.push_back({x.second,x.first});
       }
        
        sort(v.begin(),v.end(),comp);
        vector<int>res;
        for(int i=0;i<v.size();i++){
            while(v[i].first--){
                res.push_back(v[i].second);
            } 
        }
        return res;
    }	
		
		
		
