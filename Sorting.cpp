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
	
	
