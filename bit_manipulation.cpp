/*
Set kth bit 
Basic Accuracy: 65.04% Submissions: 9664 Points: 1
Given a number N and a value K. From the right, set the Kth bit in the binary representation of N. The position of Least Significant Bit(or last bit) is 0, the second last bit is 1 and so on. 

Example 1:

Input:
N = 10 
K = 2
Output:
14
Explanation:
Binary representation of the given number
10 is: 1 0 1 0, number of bits in the 
binary reprsentation is 4. Thus 2nd bit
from right is 0. The number after changing
this bit to 1 is: 14(1 1 1 0).

*/
 int setKthBit(int N, int K)
    {
      int c=1<<K;
      return N|c;
    }
    /*
    Swap two nibbles in a byte 
Basic Accuracy: 74.26% Submissions: 5354 Points: 1
Given a number N, swap the two nibbles in it and find the resulting number. 
 

Example 1:

Input:
N = 100
Output:
70
Explanation:
100 in binary is 01100100, 
two nibbles are (0110) and (0100)
If we swap the two nibbles, we get
01000110 which is 70 in decimal. 
    */
 int swapNibbles(unsigned char x){
        unsigned char y=x<<4;
       return y;
        unsigned char z=x>>4;
       
        return y|z;
        
    }

/*
Power of 2 
Basic Accuracy: 50.29% Submissions: 47278 Points: 1
Given a non-negative integer N. The task is to check if N is a power of 2. More formally, check if N can be expressed as 2x for some x.
 

Example 1:

Input: N = 1
Output: true
Explanation:
1 is equal to 2 raised to 0 (20 = 1).

*/
 bool isPowerofTwo(long long n){
        if(n==0)return false;
    if(!(n&(n-1))){
       return true;
    }
    return false;
       
        // Your code here    
        
    }
/*
Replace the Bit 
Basic Accuracy: 42.07% Submissions: 751 Points: 1
Given two numbers N and K, change the Kth bit from left of the number N to '0' if it is  '1', else return the number N itself.

Example 1:

Input:
N = 13, K = 2
Output: 9
Explanation: Binary representation of 13 is
1101. The 2nd bit from left is 1, we make
it 0 and result is 1001 = 9 (decimal).
*/
 int replaceBit (int n, int k)
    {
           int limit = log2(n)+1;
       if(k>limit)
           return n;
       int i=limit-k;
       if(n&(1<<i))
           return n&(~(1<<i));
       else
           return n;
   
    //code here.
    }
/*
Sum of two numbers without using arithmetic operators 
Easy Accuracy: 75.23% Submissions: 10313 Points: 2
Given two integers a and b. Find the sum of two numbers without using arithmetic operators.

Example 1:

Input:
a = 5, b = 3
Output: 8
Explanation :
5 + 3 = 8
*/
int sum(int a , int b)
    {
           while(b!=0){
           int sum=a^b;
           int carry = (a&b)<<1;
           a=sum;
           b=carry;
       }
       return a;
   }
/*
Longest Consecutive 1's 
Easy Accuracy: 57.61% Submissions: 20627 Points: 2
Given a number N. Find the length of the longest consecutive 1s in its binary representation.

Example 1:

Input: N = 14
Output: 3
Explanation: 
Binary representation of 14 is 
1110, in which 111 is the longest 
consecutive set bits of length is 3.
*/
    int maxConsecutiveOnes(int N)
    {
        // code here]
        int c=0;
        while(N){
            N=N&(N<<1);
            c++;
        }
        return c;
    }
/*
Kth LSB 
Easy Accuracy: 69.15% Submissions: 1305 Points: 2
A number N is given. Find its ‘K’th Least Significant Bit.

Example 1:

Input: N = 10, K = 4
Output: 1
Explanation: Binary Representation 
of 10 is 1010. 4th LSB is 1.
*/
int KthLSB(long long int n, int k){
	 long long res=n>>(k-1);
	 return res&1;
	    //complete the function here
	    
	}
/*
Josephus problem 
Easy Accuracy: 52.47% Submissions: 52370 Points: 2
Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle in a fixed direction.

The task is to choose the safe place in the circle so that when you perform these operations starting from 1st place in the circle, 
you are the last one remaining and survive.

Example 1:

Input:
n = 3 k = 2
Output: 3
Explanation: There are 3 persons so 
skipping 1 person i.e 1st person 2nd 
person will be killed. Thus the safe 
position is 3.

*/
int josephus(int n, int k)
{
    if(n==1)return 1;
    else{
        return (josephus(n-1,k)+k-1)%n+1;
    }
   //Your code here
}
/*
Generate Grey Code Sequences 
Easy Accuracy: 50.62% Submissions: 5512 Points: 2
Given a number N, your task is to complete the function which generates all n-bit grey code sequences, a grey code sequence is a sequence 
such that successive patterns in it differ by one bit.

Example 1:

Input:
N = 2
Output: 00 01 11 10
Explanation: All 2-bit gray codes are
00, 01, 11, 10 such that successive
patterns in it differ by one bit.

*/
 vector <string> generateCode(int N)
    {
        vector<string>v;
        queue<pair<string,int>>q;
        q.push({"0",0});
        q.push({"1",1});
        while(N>1){
            int size=q.size();
            while(size--){
       pair<string,int>p=q.front();
        q.pop();
        if(p.second==0){
q.push({p.first+"0",0});
q.push({p.first+"1",1});

}
if(p.second==1){
q.push({p.first+"1",0});
q.push({p.first+"0",1});

}
/*
Even Subsets 
Easy Accuracy: 46.61% Submissions: 5527 Points: 2
As we mentioned earlier, bitwise operations can be used to find number of subsets. Here, we will use that.

Given an array arr of N elements. The task is to count all the subsets whose sum is even.

Example:

Input:
N = 3
arr[] = 1 2 3
Output:
3
Explanation:
Three subsets are there whose sum of elements 
is even. Subsets are (3, 2, 1), (1, 3), (2).
*/	
int countt=0;
void func(int arr[],int cur,int n,int taken,int sum)
{
if(cur>n)
return ;
func(arr,cur+1,n,0,sum);
if((sum+arr[cur])%2==0)
countt++;
func(arr,cur+1,n,1,sum+arr[cur]);
}
int countSumSubsets(int arr[], int N){

// Your code here
countt=0;
func(arr,0,N-1,0,0);
return countt;
}
	/*
	Game of XOR 
Easy Accuracy: 58.85% Submissions: 1964 Points: 2
Given an array A[] of size N. The value of an array is denoted by the bit-wise XOR of all elements it contains. Find the bit-wise XOR of the values of all subarrays of A[].

Example 1:

Input: N = 3, A[] = {1,2,3} 
Output: 2
Explanation:
xor[1] = 1, 
xor[1, 2] = 3
xor[2, 3] = 1
xor[1, 2, 3] = 0
xor[2] = 2
xor[3] = 3
Result : 1 ^ 3 ^ 1 ^ 0 ^ 2 ^ 3 = 2
	*/	    
		    
		 int gameOfXor(int N , int A[]) {
        int res=0;
        if(N%2==0){
        return 0;
        }
        else{
            for(int i=0;i<N;i++){
                if(i%2==0){
                    res=res^A[i];
                }
            }
            return res;
        }
        // code here
    }		    
