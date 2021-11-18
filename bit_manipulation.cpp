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
		    
            }
            N--;
        
        }
        while(!q.empty()){
            v.push_back(q.front().first);
            q.pop();
        }
        return v;
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
/*
Reverse Bits 
Easy Accuracy: 49.14% Submissions: 5106 Points: 2
Given a 32 bit number X, reverse its binary form and print the answer in decimal.

Example 1:

Input:
X = 1
Output:
2147483648 
Explanation:
Binary of 1 in 32 bits representation-
00000000000000000000000000000001
Reversing the binary form we get, 
10000000000000000000000000000000,
whose decimal value is 2147483648.

*/
  long long reversedBits(long long X) {
          long long ans=0;
   long long n=X;
   for(int i=0;i<32;i++){
       ans=(ans<<1)|(n&1);
       n=n>>1;
       }
   return ans;
           
    }	
/*
Power Set 
Easy Accuracy: 48.41% Submissions: 14704 Points: 2
Given a string S find all possible subsequences of the string in lexicographically-sorted order.

Example 1:

Input : str = "abc"
Output: a ab abc ac b bc c
Explanation : There are 7 substrings that 
can be formed from abc.

*/	
		    	void func(vector<string>&v,int curr,string s,string res){
	    if(curr==s.size()){
	           if(res.length()>0)
	        v.push_back(res);
	        return;
	    }
	    func(v,curr+1,s,res);
	  
	    func(v,curr+1,s,res+s[curr]);
	    
	}
		vector<string> AllPossibleStrings(string s){
		   vector<string>v;
		   string p="";
		   func(v,0,s,p);
		   sort(v.begin(),v.end());
	return v;
		}
		    
/*
Bit Difference 
Hard Accuracy: 46.07% Submissions: 11130 Points: 8
We define f (X, Y) as number of different corresponding bits in binary representation of X and Y. For example, f (2, 7) = 2,
since binary representation of 2 and 7 are 010 and 111, respectively. The first and the third bit differ, so f (2, 7) = 2.

You are given an array A of N integers, A1, A2 ,…, AN. Find sum of f(Ai, Aj) for all ordered pairs (i, j) such that 1 ≤ i, j ≤ N. Return the answer modulo 109+7.

Example 1:

Input: N = 2
A = {2, 4}
Output: 4
Explaintion: We return 
f(2, 2) + f(2, 4) + 
f(4, 2) + f(4, 4) = 
0 + 2 + 
2 + 0 = 4.
*/
class Solution{
public:
const int p = 1000000007;
#define lli long long int
    int countBits(int N, long long int arr[])
    {
          lli res = 0;
    
    for(int i = 0; i < 32; i++){
        lli counton = 0;
        for(int j = 0; j < N; j++){
            if(arr[j] & (1 << i))
                counton++;
        }
        
        lli countoff = (N - counton);
        res += (2 * (counton * countoff)) % p;
    }
    return res % p;
       
    }
/*
Minimum X (xor) A 
Hard Accuracy: 41.04% Submissions: 939 Points: 8
Given two integers A and B, the task is to find an integer X such that (X XOR A) is minimum possible and the count of set bit in X is equal to the count of set bits in B.

Example 1:

Input: 
A = 3, B = 5
Output: 3
Explanation:
Binary(A) = Binary(3) = 011
Binary(B) = Binary(5) = 101
The XOR will be minimum when x = 3
i.e. (3 XOR 3) = 0 and the number
of set bits in 3 is equal
to the number of set bits in 5.

*/
	 int getSetBits(int b)
    {
        int count=0;
        while(b)
        {
            b = b & (b-1);
            count++;
        }
        return count;
    }
    int minVal(int a, int b) {
        
    
        // code here
        int setBits = getSetBits(b);
        //cout<<setbits<<"hello\n";<br>
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            int mask = 1 << i;
            bool set = a & mask;
            if (set && setBits > 0) {
                ans |= (1 << i);
                setBits--;
            }
        }

        //cout<<setbits<<"hi\n";<br>
        if(setBits>0)
        {
            for(int i=0;i<32;i++)
            {
                int mask = 1 << i;
                bool set = ans & mask;

                if(!set && setBits)
                {
                    ans|=(1<<i);
                    setBits--;
                    }
            }
        }
     
        return ans;
    
        // code here
    }
};		    
/*
Bleak Numbers 
Medium Accuracy: 52.64% Submissions: 2407 Points: 4
Given an integer, check whether it is Bleak or not.

A number ‘n’ is called Bleak if it cannot be represented as sum of a positive number x and set bit count in x, i.e., 
x + countSetBits(x) is not equal to n for any non-negative number x.

Example 1:

Input: 4
Output: 1
Explanation: There is no any possible x
such that x + countSetbit(x) = 4

*/
int countSetBits(int x){
if(x==0){
return 0;
}else{
return 1+countSetBits(x&(x-1));
}
}
	int is_bleak(int n)
	{
	  
	    
	       for(int i=1;i<n;i++){
	           int y=countSetBits(i);
	           if(i+y==n){
	               return 0;
	           }
	       }
	       return 1;
	    
	    // Code here.
	}		    
/*
Given is an array A[] of size N, find all the subsequence which when multiplied results in a number which is Power of 2.

 

Example 1:

Input:
N = 3
A[] = {1, 6, 2}
Output:
3
Explanation:
The subsequence that 
can be chosen is {1},
{2} and {1,2}.
*/
 long long numberOfSubsequences(int N, long long A[]){
     
       long long count=0;
        for(int i=0; i<N; i++)
        if((A[i]&(A[i]-1))==0) count++;
        return (long)(pow(2, count)) - 1;
    
    }
/*
Maximum AND Value 
Medium Accuracy: 44.82% Submissions: 22253 Points: 4
Given an array arr[] of N positive elements. The task is to find the Maximum AND Value generated by any pair(arri, arrj) from the array such that i != j.
Note: AND is bitwise '&' operator.


Example 1:

Input: 
N = 4
arr[] = {4, 8, 12, 16}
Output: 8
Explanation:
Pair (8,12) has the Maximum AND Value 8.
*/
int checkBit(int pattern, int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if ((pattern & arr[i]) == pattern)
            count++;
    return count;
}

// Function for finding maximum and value pair
int maxAND (int arr[], int n)
{
    int res = 0, count;

    // iterate over total of 30bits from msb to lsb
    for (int bit = 31; bit >= 0; bit--)
    {
        // find the count of element having set  msb
        count = checkBit(res | (1 << bit),arr,n);

        // if count >= 2 set particular bit in result
        if ( count >= 2 )        
            res |= (1 << bit);        
    }

    return res;
}
/*

Count total set bits 
Medium Accuracy: 45.48% Submissions: 53800 Points: 4
You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).

Example 1:

Input: N = 4
Output: 5
Explanation:
For numbers from 1 to 4.
For 1: 0 0 1 = 1 set bits
For 2: 0 1 0 = 1 set bits
For 3: 0 1 1 = 2 set bits
For 4: 1 0 0 = 1 set bits
Therefore, the total set bits is 5.

*/
int countSetBits(int n)
{ if(n==0)return 0;
int x=(log2(n));
return((pow(2,x-1)*x)+(n-pow(2,x)+1)+countSetBits(n-pow(2,x)));
}
/*
Is Binary Number Multiple of 3 
Medium Accuracy: 34.24% Submissions: 6842 Points: 4
Given a binary number, Find, if given binary number is a multiple of 3. The given number can be big upto 2^10000.
It is recommended to finish the task using one traversal of input binary string.

Example 1:

Input: S = "011"
Output: 1
Explanation: "011" decimal equivalent
is 3, which is divisible by 3.

*/
	int isDivisible(string s){
	    long long int ret = 0;
int mod = 1e9 + 7;
int od = 0;
int ev = 0;
int j = 1;
for(int i = s.length() - 1;i >= 0 ;i --){
if(s[i] == '1' and j % 2 == 0)
{
ev++;
}
else if(s[i] == '1' and j % 2 != 0)
{
od++;
}
j++;
}
if(abs(ev-od) % 3 == 0)
return 1;
return 0;   
	}
/*
Find element occuring once when all other are present thrice 
Medium Accuracy: 67.74% Submissions: 1844 Points: 4
Given an array of integers arr[] of length N, every element appears thrice except for one which occurs once.
Find that element which occurs once.


Example 1:

Input:
N = 4
arr[] = {1, 10, 1, 1}
Output:
10
Explanation:
10 occurs once in the array while the other
element 1 occurs thrice.
*/
 int singleElement(int arr[] ,int n) {
        
          int count[32] = {};
        
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < 32; j++) {

                if(arr[i] & (1 << j))

                    count[j]++;

            }

        }
        
        int ans = 0;
    
        for(int i = 0; i < 32; i++) {

            if(count[i] % 3 == 1)

                ans |= (1 << i);

        }

        return ans
    }
};
