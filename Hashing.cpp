/*
Check if a string is Isogram or not 
Basic Accuracy: 55.24% Submissions: 23754 Points: 1
Given a string S of lowercase alphabets, check if it is isogram or not. An Isogram is a string in which no letter occurs more than once.

Example 1:

Input:
S = machine
Output: 1
Explanation: machine is an isogram
as no letter has appeared twice. Hence
we print 1.
*/
  bool isIsogram(string s)
    {
      int hash[256];
        memset(hash, 0, sizeof(hash));
      for(int i=0;i<s.size();i++){
          hash[s[i]]++;
      }
      for(int i=0;i<256;i++){
          if(hash[i]>1){
              return false;
          }
      }
      return true;
       
    }
/*
Uncommon characters 
Basic Accuracy: 37.25% Submissions: 7863 Points: 1
Given two strings A and B. Find the characters that are not common in the two strings. 

Example 1:

Input:
A = geeksforgeeks
B = geeksquiz
Output: fioqruz
Explanation: 
The characters 'f', 'i', 'o', 'q', 'r', 'u','z' 
are either present in A or B, but not in both.
*/
int hash[256]={0};
        int hash2[256]={0};
        for(int i=0;i<A.size();i++){
            hash[A[i]]++;
        }
        for(int i=0;i<B.size();i++){
            hash2[B[i]]++;
        }
        string res;
        for(int i=0;i<256;i++){
            if(hash[i]!=0 && hash2[i]==0){
                res+=i;
            }
            else if(hash[i]==0 && hash2[i]!=0){
                res+=i;
            }
        }
         return res.size() == 0 ? "-1" : res;
            // code here
        }
/*
Anagram Palindrome 
Given a string S, Check if characters of the given string can be rearranged to form a palindrome. 

Example 1:

Input:
S = "geeksogeeks"
Output: Yes
Explanation: The string can be converted
into a palindrome: geeksoskeeg
*/
int isPossible (string S)
{
    int hash[256]={0};
    int count=1;
    for(int i=0;i<S.size();i++){
        hash[S[i]]++;
    }
    for(int i=0;i<256;i++){
    if(count==1 &&hash[i]%2==1){
        count++;
    }
           else if(count>1 &&hash[i]%2==1)
        return 0;
        
    }
    
    return 1;
    // your code here
}
