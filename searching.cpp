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



