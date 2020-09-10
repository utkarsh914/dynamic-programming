/*
https://practice.geeksforgeeks.org/problems/minimum-points-to-reach-destination/0/

Given a grid with each cell consisting of positive, negative or no points i.e, zero points. We can move across a cell only if we have positive points ( > 0 ). Whenever we pass through a cell, points in that cell are added to our overall points. We need to find minimum initial points to reach cell (m-1, n-1) from (0, 0) by following these certain set of rules :
 
1.From a cell (i, j) we can move to (i+1, j) or (i, j+1).
2.We cannot move from (i, j) if your overall points at (i, j) is <= 0.
3.We have to reach at (n-1, m-1) with minimum positive points i.e., > 0.
 
Example:
 
Input: points[m][n] = 
					{ {-2, -3,   3},  
						{-5, -10,  1},  
						{10,  30, -5}  
					};
Output: 7
Explanation:  
7 is the minimum value to reach destination with  
positive throughout the path. Below is the path.
 
(0,0) -> (0,1) -> (0,2) -> (1, 2) -> (2, 2)
 
We start from (0, 0) with 7, we reach(0, 1)  
with 5, (0, 2) with 2, (1, 2) with 5, (2, 2)
with and finally we have 1 point (we needed  
greater than 0 points at the end).

Input:

The first line contains an integer 'T' denoting the total number of test cases.
In each test cases, the first line contains two integer 'R' and 'C' denoting the number of rows and column of array.  
The second line contains the value of the array i.e the grid, in a single line separated by spaces in row major order.


Output:

Print the minimum initial points to reach the bottom right most cell in a separate line.


Constraints:

1 ≤ T ≤ 100
1 ≤ R,C ≤ 100
-1000 ≤ A[i][j] ≤ 1000


Example:

Input:
1
3 3
-2 -3 3 -5 -10 1 10 30 -5
Output:
7
*/

#include<bits/stdc++.h>
#include<iostream>
#define el "\n"
#define ll long long int
#define pb push_back
#define u_m unordered_map
#define u_s unordered_set
#define p_q priority_queue
using namespace std;

int m[101][101];
int r; int c;

int reach() {
	
	int dp[r+1][c+1];
	
	for (int i=r; i>=0; i--) {
		for (int j=c; j>=0; j--) {
			// to reach last col from last col itself
			if (i==r && j==c) {
				int ans = 1-m[r][c];
				if (ans<1) dp[r][c]=1;
				else dp[r][c]=ans;
			}
			else {
				int right=INT_MAX, bottom=INT_MAX;
				if (j+1 <= c) right = -m[i][j] + dp[i][j+1];
				if (i+1 <= r) bottom = -m[i][j] + dp[i+1][j];
				if (right<1) right=1;
				if (bottom<1) bottom=1;
				dp[i][j] = min(right, bottom);
			}
		}
	}
	return dp[0][0];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; cin>>t;
	while (t--) {
		cin>>r>>c;
		r-=1; c-=1;
		for (int i=0; i<=r; i++) {
			for (int j=0; j<=c; j++)
			cin>>m[i][j];
		}
		cout<<reach()<<el;
	}
}