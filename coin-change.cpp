/*
https://practice.geeksforgeeks.org/problems/coin-change/0/

Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins. The order of coins doesn’t matter. For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer 'M' denoting the size of array. The second line contains M space-separated integers A1, A2, ..., AN denoting the elements of the array. The third line contains an integer 'N' denoting the cents.

Output:
Print number of possible ways to make change for N cents.

Constraints:
1 ≤ T ≤ 50
1 ≤ N ≤ 300
1 ≤ A[i] ≤ 300

Example:
Input:
2
3
1 2 3
4
4
2 5 3 6
10

Output:
4
5

Explanation:
Testcase 1: The possiblities are as such: {1, 1, 1, 1}, {1, 1, 2}, {1, 3}, {2, 2}.

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
	every time we have a choice of using the current coin
	and not using it.
	if using it, then subtract the val of coin from total amount,
	and ans is the ans for total-coin val
	when not using it, ans is for previously used coins
	add both answers to get ans with current coin
*/

int change(int coins[], int m, int n) {

	int dp[m+1][n+1];
	// 1 way for making change for 0 amount
	for (int i=0; i<=m; i++) dp[i][0]=1;
	// no ways if no coins are given
	for (int i=1; i<=n; i++) dp[0][i]=0;

	for (int i=1; i<=m; i++) {
		for (int j=1; j<=n; j++) {
			// use the curr coin -> dp[i][j-coins[i-1]]
			int temp = j-coins[i-1];
			if (temp>=0) temp = dp[i][temp];
			else temp=0;
			// don't use curr coin -> dp[i-1][j]
			// total is addition of both
			dp[i][j] = dp[i-1][j] + temp;
		}
	}
	return dp[m][n];
}

// ============ ALTERNATIVE EFFICIENT SOLUTION ==========

int count( int S[], int m, int n ) 
{ 
	// table[i] will be storing the number of solutions for 
	// value i. We need n+1 rows as the table is constructed 
	// in bottom up manner using the base case (n = 0) 
	int table[n+1]; 

	// Initialize all table values as 0 
	memset(table, 0, sizeof(table)); 

	// Base case (If given value is 0) 
	table[0] = 1; 

	// Pick all coins one by one and update the table[] values 
	// after the index greater than or equal to the value of the 
	// picked coin 
	for(int i=0; i<m; i++) 
		for(int j=S[i]; j<=n; j++) 
			table[j] += table[j-S[i]];

	return table[n]; 
} 


int main() {
	int t; cin>>t;
	while (t--) {
		int m; cin>>m;
		int coins[m];
		for (int i=0; i<m; i++) cin>>coins[i];
		int n; cin>>n;
		cout << change(coins, m, n) << endl;
	}
}