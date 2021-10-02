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
    
