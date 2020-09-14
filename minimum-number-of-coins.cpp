/*
https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins/0

Given a value N, total sum you have. You have to make change for Rs. N, and there is infinite supply of each of the denominations in Indian currency, i.e., you have infinite supply of { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000} valued coins/notes, Find the minimum number of coins and/or notes needed to make the change for Rs N.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case consist of an Integer value N denoting the amount to get change for.

Output:
Print all the denominations needed to make the change in a separate line.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 106

Example:
Input:
1
43

Output:
20 20 2 1

Explanation:
Testcase 1: Sum of Rs 43 can be changed with minimum of 4 coins/ notes 20, 20, 2, 1.

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void greedy(int n, int c[]) {
	for (int i=9; i>=0 && n>0; ) {
		if (n>=c[i]) {
			n-=c[i];
			cout << c[i] << " ";
		}
		else i--;
	}
	cout << endl;
}


void dynamic(int N, int coins[]) {

	int dp[10][N+1];

	for (int i=0; i<=N; i++)
		dp[0][i]=i;

	// fill the table
	for (int i=1; i<10; i++) {
		for (int j=0; j<=N; j++) {
			if (j>=coins[i])
				dp[i][j] = min(dp[i-1][j], 1+dp[i][j-coins[i]]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}

	// print the coins
	int i=9, j=N;
	while (i>=0 && j>0) {
		if (dp[i][j] == dp[i-1][j])
			i--;
		else {
			cout << coins[i] << " ";
			j -= coins[i];
		}
	}
	cout << "\n";

}


int main() {
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		int c[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
		greedy(n, c);
	}
	return 0;
}