/*
Print Binary Tree levels in sorted order 
Medium Accuracy: 55.08% Submissions: 1401 Points: 4
Given an array arr[] which contains data of N nodes of Complete Binary tree in level order fashion. The task is to print the level order traversal in sorted order.

Example 1:

Input:
N = 7
arr[] = {7 6 5 4 3 2 1}
Output:
7
5 6
1 2 3 4
Explanation: The formed Binary Tree is:
             7
          /      \
        6         5
      /  \      /   \
     4    3    2     1
Example 2:

Input:
N = 6
arr[] = {5 6 4 9 2 1}
Output:
5
4 6
1 2 9
Explanation: The formed Binary Tree is:
             5
          /     \
        6        4
      /  \      /    
     9    2    1    
*/
  vector <vector <int>> binTreeSortedLevels (int arr[], int n)
    {vector<vector<int>> ans;
        int height= log2(n);
        priority_queue<int,vector<int>, greater<int>> pq;
        
        int idx=0;
        for(int i=0;i<=height;i++)
        {
            vector<int> temp;
            for(int j=0;j<pow(2,i) && idx < n;j++)
            {
                pq.push(arr[idx]);
                idx++;
            }
            while(pq.size() > 0)
            {
                temp.push_back(pq.top());
                pq.pop();
            }
            ans.push_back(temp);
        }
        
        return ans;
        // Your code here
    }
};
/*
Geek and Contest || 
Easy Accuracy: 74.26% Submissions: 1128 Points: 2
Geek hosted a contest and N students participated in it. The score of each student is given by an integer array arr[]. The task is to print the number of each student (indexes) in the order they appear on the scoreboard.
A student with a maximum score appears first. If two people have the same score then a higher indexed student appears first.

Example 1:

Input:
N = 5
arr[] = {450, 230, 730, 230, 150}
Output:
3 1 4 2 5
Explanation:
1. The top scorer is at 3rd index, therefore 3 
at the first index.
2. The second-highest scorer is at 1st index therefore
 1 is at the second index.
3. The third-highest scorer is at 4th index therefore
 4 at the thirst index.
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    priority_queue<pair<int,int>>q;
	    for(int i=1;i<=n;i++){
	        int x;
	        cin>>x;
	        q.push({x,i});
	    }
	    while(!q.empty()){
	        cout<<q.top().second<<" ";
	        q.pop();
	    }
	    
	    cout<<endl;
	    
	}
	
	
	return 0;
}
