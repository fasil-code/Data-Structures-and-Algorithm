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
