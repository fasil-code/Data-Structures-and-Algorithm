/*
Binary search : Time complexity:O(N)  Space Complexity:O(1)
*/
int binarysearch(int arr[], int x, int n)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2; //Finding mid
        if (arr[mid] == x)
        {
            return mid;      // Value found 
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;     //Searching in right half
        }
        else
        {
            high = mid - 1;    //Searching in left half 
        }
    }
    return -1;         //No match 
}

/*

Linear search T.C O(N)   S.C O(1)
*/
int Linear search(int arr[],int n,int x){
    for(int i=0;i<n;i++){
    if(arr[i]==x){
    return i;   //found
    }
    }
    return -1;  //Not found
}


/*
Interpolation search :A way to optimise binary search to an certain extent
*/
int binarysearch(int arr[], int x, int n)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid =low + (((x - arr[low]) * (high - low)) / (arr[high] - arr[low]));  //Finding mid
        if (arr[mid] == x)
        {
            return mid;      // Value found 
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;     //Searching in right half
        }
        else
        {
            high = mid - 1;    //Searching in left half 
        }
    }
    return -1;         //No match 
}

/*
Count zeroes in sorted matrix:
Given a N X N binary Square Matrix where each row and column of the matrix is sorted in ascending order. 
Find the total number of zeros present in the matrix.
Input:
N = 3
A = {{0, 0, 0},
     {0, 0, 1},
     {0, 1, 1}}
Output: 6
Explanation: 
The first, second and third row contains 3, 2 and 1
zeroes respectively.
*/
	int countZeros(vector<vector<int>>A)
	{
	    int count=0;
	    int j=A.size()-1;
	    int i=0;
	    while(i<A.size() && j>=0){
	        if(A[i][j]==0){
	           
	               count+=j+1;
	               i++;
	        }
	        else if (A[i][j]==1 ){
	         
	            j--;
	        }
	    }
	    return count;
		//code here
	}


/*
FIRST OCCURENCE OF ANY NUMBER IN ANY ARRAY O(LOG(N))
*/
	int count(int arr[], int N, int K) {
	    int first =-1; // for storing  first occurence
	   
	    int i=0;
    int j=N-1;
    while(i<=j){
    int mid=i+(j-i)/2;
    if(arr[mid]==K){
        first=mid;
   j=mid-1;
        
    }
    else if(arr[mid]>K){
    j=mid-1;
    }
    else{
        i=mid+1;
    }
    }
return first;		
	}

/*
Last OCCURENCE OF ANY NUMBER IN ANY ARRAY O(LOG(N))
*/
int count(int arr[], int N, int K) {
	int second=-1;
	int i=0;
	int j=N-1;
     while(i<=j){
    int mid=i+(j-i)/2;
    if(arr[mid]==K){
        second=mid;
   i=mid+1;
        
    }
    else if(arr[mid]>K){
    j=mid-1;
    }
    else{
        i=mid+1;
    }	
	     return second;
    }   
}
/*
Given an array arr[] of n integers. Check whether it contains a triplet that sums up to zero. 
O(N^2)
Example 1:

Input: n = 5, arr[] = {0, -1, 2, -3, 1}
Output: 1
Explanation: 0, -1 and 1 forms a triplet
with sum equal to 0.
*/
   bool findTriplets(int arr[], int n)
    { 
         sort(arr,arr+n); //Sorting 
      for(int i=0;i<n-1;i++){
          int j=i+1; 
          int k=n-1;
          while(j<k){
              int sum=arr[i]+arr[j]+arr[k];
              if(sum==0){
                  return 1;
              }
              else if(sum>0){
                  k--;
              }
              else{
                  j++;
              }
              
          }
      }
      return 0;
        //Your code here
    }
/*
Given an array of size N consisting of only 0's and 1's. The array is sorted in such a manner that all the 1's are placed first and then they are followed by all the 0's.
Find the count of all the 0's.
O(log(n))
Example 1:

Input:
N = 12
Arr[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}
Output: 3
Explanation: There are 3 0's in the given array.

*/	
	int pos(int arr[],int low,int high){
    int ans=0;
    while(low<=high){
        
        int mid=(low+high)/2;
        if(arr[mid]==0){
        ans= mid;   
        high=mid-1;
        }
        else if(arr[mid]==1){
            low=mid+1;
        }

        
    }
    return ans;
}
int countZeroes(int arr[], int n) {
    
    int l=pos(arr,0,n-1);
    return n-l;
    // code here
}
	
/*
Given an array arr of n elements which is first increasing and then may be decreasing, find the maximum element in the array.
Note: If the array is increasing then just print then last element will be the maximum value.
O(log(N);
MOUNTAIN ARRAY

Example 1:

Input: 
n = 9
arr[] = {1,15,25,45,42,21,17,12,11}
Output: 45
Explanation: Maximum element is 45.
*/
	int findMaximum(int arr[], int n) {
	    int i=0;
	    int j=n-1;
	    while(i<=j){
	        int mid=(i+j)/2;
	        if(arr[mid]>arr[mid-1]  && arr[mid]>arr[mid+1]){
	            return arr[mid];
	        }
	        else if(arr[mid]>arr[mid-1]){
	            i=mid+1;
	        }
	        else{
	            j=mid-1;
	        }
	    }
	    // code here
	}
	
/*Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.
 
MOORES VOTING ALGORITHM
Example 1:

Input:
N = 3 
A[] = {1,2,3} 
Output:
-1
Explanation:
Since, each element in 
{1,2,3} appears only once so there 
is no majority element.
*/
int majorityElement(int arr[], int n)
{
        int maj=0;
        int count=1;
        for(int i=1;i<n;i++){
            if(arr[maj]==arr[i]){
                count++;
            }
            else{
                count--;
            }
            if(count==0){
                maj=i;
                count=1;
            }
        }
        
        int f=arr[maj];
        int d=0;
   for(int i=0;i<n;i++){
       if(f==arr[i]){
           d++;
       }
   }
   
   if(d>n/2){
       return f;
   }
   else{
       return -1;
   }
}

/*
Given a sorted array arr[] of size N without duplicates, and given a value x. Floor of x is defined as the largest element K in arr[] such that K is smaller than or equal to x. 
Find the index of K(0-based indexing).

Example 1:

Input:
N = 7, x = 0 
arr[] = {1,2,8,10,11,12,19}
Output: -1
Explanation: No element less 
than 0 is found. So output 
is "-1".
*/
int findFloor(long long int arr[], int N, long long int K) {
    long long high=N-1;
    long long low=0;
int first=-1; //store ans;
    while(low<=high){
        long long mid=(low+high)/2;
        if(arr[mid]<=K){
            first=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return first;
    //Your code here
}

/**
Given an array of distinct elements which was initially sorted. This array is rotated at some unknown point.
The task is to find the minimum element in the given sorted and rotated array. 

Example 1:

Input:
N = 10
arr[] = {2,3,4,5,6,7,8,9,10,1}
Output: 1
Explanation: The array is rotated 
once anti-clockwise. So minium 
element is at last index (n-1) 
which is 1.

*/
    // your code here	
 int minNumber(int arr[], int low, int high)
    {
        while(low<=high){
            int mid=(low+high)/2;
            if(mid==0 || arr[mid]<arr[mid-1]){
                
        return arr[mid];
            }
            
            else if(arr[mid]>arr[high]){
                low=mid+1;
            }
            else{
                high=mid;
                
            }
        }
        
        // Your code here
        
    }
/*
You are given an array of N+2 integer elements. All elements of the array are in range 1 to N. 
Also, all elements occur once except two numbers which occur twice. Find the two repeating numbers.

Example 1:

Input:
N = 4
array[] = {1,2,1,3,4,3}
Output: 1 3
Explanation: In the given array, 
1 and 3 are repeated two times.

*/

// your code here	
vector<int> twoRepeated (int arr[], int N) {
        // Your code here
        vector<int> v;
        for(int i=0;i<N+2;i++){
            if(arr[abs(arr[i])]>0){
                arr[abs(arr[i])]=-arr[abs(arr[i])];
            }
            else {
                v.push_back(abs(arr[i]));
            }
        }
        return v;
    }
/*
You are given heights of consecutive buildings. You can move from the roof of a building to the roof of next adjacent building. 
You need to find the maximum number of consecutive steps you can put forward such that you gain an increase in altitude with each step.

Example 1:

Input:
N = 5
A[] = {1,2,2,3,2}
Output: 1
Explanation: 1, 2 or 2, 3 are the only consecutive 
buildings with increasing heights.
*/
// your code here	
 
int maxStep(int A[], int N)
    {
       int count=0,maxc=0;
       for(int i=0;i<N-1;i++){
           if(A[i+1]-A[i]>0){
               count++;
               maxc=max(count,maxc);
           }
           else{
               
               count=0;
               
           }
               
       }
       return maxc;
}

/*
Given a sorted and rotated array A of N distinct elements which is rotated at some point, and given an element K.
The task is to find the index of the given element K in the array A.

Example 1:

Input:
N = 9
A[] = {5 6,7,8,9,10,1,2,3}
K = 10
Output: 5
Explanation: 10 is found at index 5.
*/

 int minNumber(vector<int>arr, int low, int high)
    {
        while(low<=high){
            int mid=(low+high)/2;
            if( mid==0 ||arr[mid]<arr[mid-1]){
                
        return mid;
            }
            
            else if(arr[mid]>arr[high]){
                low=mid+1;
            }
            else{
                high=mid;
                
            }
        }
        
        return -1;
        
    }
        // Your code here
    int binarysearch(vector<int>v ,int low,int high,int k){
        while(low<=high){
            int mid=(low+high)/2;
            if(v[mid]==k){
                return mid;
            }
            else if(v[mid]>k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return -1;
        
    }

int Search(vector<int> vec, int K) {
    
    int ans=minNumber(vec,0,vec.size()-1);
 //  cout<<ans<<endl;
    if(ans==0){
        return binarysearch(vec,0,vec.size()-1,K);
    }
    if(vec[ans]==K){
        return ans;
    }
    if(vec[0]<=K){
return binarysearch(vec,0,ans-1,K);
    }
    return binarysearch(vec,ans+1,vec.size()-1,K);
    //code here
}
/*
Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
Note: can you take care of the duplicates without using any additional Data Structure?

Example 1:

Input:
n1 = 6; A = {1, 5, 10, 20, 40, 80}
n2 = 5; B = {6, 7, 20, 80, 100}
n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20 80
Explanation: 20 and 80 are the only
common elements in A, B and C.
*/
 vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            int l=INT_MIN;
            vector<int>v;
           int i=0;
           int j=0;
           int k=0;
           while(i<n1 && j<n2 && k<n3){
               if(A[i]==B[j] && A[i]==C[k] && A[i]!=l){
                   v.push_back(A[i]);
                   l=A[i];
                   i++;
                   j++;
                   k++;
               }
               else if(B[j]<C[k] || B[j]<A[i]){
                   j++;
               }
               else if(A[i]<B[j] || A[i]<C[k]){
                   i++;
               }
               
               else{
                   k++;
               }
           }
           return v;
           
           //code here.
        }

/*Smallest greater elements in whole array 
Easy Accuracy: 59.22% Submissions: 1217 Points: 2
Given an array A of N length. We need to calculate the next greater element for each element in a given array. If the next greater element is not available in a given array then we need to fill ‘-10000000’ at that index place.

Example 1:

â€‹Input : arr[ ] = {13, 6, 7, 12}
Output : _ 7 12 13 
Explanation:
Here, at index 0, 13 is the greatest value 
in given array and no other array element 
is greater from 13. So at index 0 we fill 
'-10000000'.*/
int* greaterElement(int arr[], int n)
{
     set<int> x;
    for(int i=0; i<n;i++)
        x.insert(arr[i]);

    for(int i=0; i<n;i++)
    {
        auto it=x.find(arr[i]);
        it++;
        if(it==x.end()){
                arr[i]=-10000000;
            }
            else{
                arr[i]=(*it);
            }
    }
    return arr;
    // Complete the function
}
/*
Missing element of AP 
Easy Accuracy: 38.74% Submissions: 2944 Points: 2
Find the missing element from an ordered array arr[], consisting of N elements representing an Arithmetic Progression(AP).
O(logn)

Example 1:

Input:
N = 6
Arr[] = {2, 4, 8, 10, 12, 14}
Output: 6
Explanation: Actual AP should be 
2, 4, 6, 8, 10, 12, 14.
*/
int pos(int arr[],int low,int high,int diff){
    int mid;
   
    while(low<=high){
        mid=(low+high)/2;
        if((arr[mid]-arr[0])/diff==mid){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return arr[low]-diff;
}
    int findMissing(int arr[], int n) {
          int diff = (arr[n - 1] - arr[0]) / n;
        return pos(arr,0,n-1,diff);
        // code here
    }
 // program to find trailing zeroes of n!
// time Complexity = O(logn)
   int findtailing_zeroes(int n)
        {
       
        int count=0;
        if(n<0)
        return -1;
        for(int i=5;n/i>0;i*=5){
            count+=n/i;
        }
        return count;
        }
/*
Given an integer x, find the square root of x. If x is not a perfect square, then return floor(√x).
O(logn)
Example 1:

Input:
x = 5
Output: 2
Explanation: Since, 5 is not a perfect 
square, floor of square_root of 5 is 2.
*/
 long long int floorSqrt(long long int x) 
    {
        long long low=0;
        long long high=x;
        long long int ans=0;
        while(low<=high){
            long long mid =low+(high-low)/2;
            if(mid*mid<=x){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
        // Your code goes here   
    }

/*

Ternary Search- It is a divide and conquer algorithm that can be used to find an element in an array.
In this algorithm, we divide the given array into three parts and determine which has the key (searched element).
o(logn)
Example 1:

Input:
N = 5, K = 6
arr[] = {1,2,3,4,6}
Output: 1
Exlpanation: Since, 6 is present in 
the array at index 4 (0-based indexing),
output is 1.
*/
int ternarySearch(int arr[], int N, int k) 
    { 
        int low=0;
        int high=N-1;
        while(low<=high){
            int mid1=low+(high-low)/3;
            int mid2=high-(high-low)/3;
            if(arr[mid1]==k){
                return 1;
            }
            else if(arr[mid2]==k){
                return 1;
            }
           else if(k<arr[mid1]){
        high=mid1-1;
            }
            else if(k>arr[mid2]){
                low=mid2+1;
            }
            else{
                low=mid1+1;
                high=mid2-1;
            }
            
        }
        return -1;
       // Your code here
    }
