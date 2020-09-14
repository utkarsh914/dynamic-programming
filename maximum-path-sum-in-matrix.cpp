/*
https://practice.geeksforgeeks.org/problems/path-in-matrix/0

Given a NxN matrix of positive integers. There are only three possible moves from a cell Matrix[r][c].

Matrix [r+1] [c]
Matrix [r+1] [c-1]
Matrix [r+1] [c+1]
​Starting from any column in row 0, return the largest sum of any of the paths up to row N-1.


Example 1:

Input: N = 2
Matrix = {{348, 391},
		  {618, 193}}
Output: 1009
Explaination: The best path is 391 -> 618. 
It gives the sum = 1009.

Example 2:

Input: N = 2
Matrix = {{2, 2},
		  {2, 2}}
Output: 4
Explaination: No matter which path is 
chosen, the output is 4.

Your Task:
You do not need to read input or print anything. Your task is to complete the function maximumPath() which takes the size N and the Matrix as input parameters and returns the highest maximum path sum.


Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(N*N)


Constraints:
1 ≤ N ≤ 100
1 ≤ Matrix[i][j] ≤ 1000

*/

class Solution{
public:
	int maximumPath(int N, vector<vector<int>> Matrix)
	{
		int dp[N+1][N+1];
		N--; // N is last index
		
		for (int i=N; i>=0; i--) {
			for (int j=N; j>=0; j--) {
				int a=INT_MIN, b=INT_MIN, c=INT_MIN;
				if (i+1 <= N) a = dp[i+1][j];
				if (i+1 <= N && j-1>=0) b = dp[i+1][j-1];
				if (i+1 <= N && j+1<=N) c = dp[i+1][j+1];
				int max_ = max(a, max(b,c));
				if (max_==INT_MIN) max_=0;
				dp[i][j] = Matrix[i][j] + max_;
			}
		}
		
		// select max from first row
		int ans=INT_MIN;
		for (int i=0; i<=N; i++)
			ans=max(ans, dp[0][i]);
		
		return ans;
	}
};