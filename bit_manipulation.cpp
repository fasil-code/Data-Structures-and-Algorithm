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
