/*
https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix/0/

Given a binary matrix, find out the maximum size square sub-matrix with all 1s.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is n and m,n is the number of rows and m is the number of columns.
The second line of each test case contains array C[n][m] in row major form.

Output:

Print maximum size square sub-matrix.

Constraints:

1 ≤ T ≤ 100
1 ≤ n,m ≤ 50
0 ≤ C[n][m] ≤ 1

Example:

Input:
3
5 6
0 1 0 1 0 1 1 0 1 0 1 0 0 1 1 1 1 0 0 0 1 1 1 0 1 1 1 1 1 1
2 2
1 1 1 1
2 2
0 0 0 0

Output:
3
2
0

*/


#include<bits/stdc++.h>
#include<iostream>
#define furr ios_base::sync_with_stdio(false); cin.tie(NULL)
#define el "\n"
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define u_m unordered_map
#define u_s unordered_set
#define p_q priority_queue
using namespace std;

int M[51][51];
int R,C;

/*

0 0 1 1 0
0 1 1 1 1
0 0 0 1 1
1 1 1 1 1

0 0 1 1
0 0 1 1
1 1 0 0
0 1 1 1
1 1 1 1

*/

int findsquare() {

	int dp[R+1][C+1];
	int ans = 0;
	// copy first row and col as it is
	for (int i=0; i<=C; i++)
		dp[0][i]=M[0][i];
	for (int i=0; i<=R; i++)
		dp[i][0]=M[i][0];

	for (int i=1; i<=R; i++) {
		for (int j=1; j<=C; j++) {
			if (M[i][j]==0)
				dp[i][j] = 0;
			else
				dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
		}
	}

	for (int i=0; i<=R; i++) {
		for (int j=0; j<=C; j++) {
			ans = max(ans, dp[i][j]);
		}
	}

	return ans;
}

int main() {
	furr;
	int t; cin>>t;
	while (t--) {
		cin>>R>>C;
		R--, C--;
		for (int i=0; i<=R; i++) {
			for (int j=0; j<=C; j++)
				cin>>M[i][j];
		}
		cout << findsquare() <<el;
	}
}