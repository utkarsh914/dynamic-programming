/* I want to be the very best like no one ever was */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int collect(int a[6][5], int r, int c, int N, int M, int dp[][1000]) {
	if (r>=N || r<0 || c>=M || c<0) return 0;
	if (dp[r][c]!=-1) return dp[r][c];

	int max_ = INT_MIN;
	for (int col=c-1; col<=c+1; col++)
		max_ = max(max_, collect(a, r+1, col, N, M, dp));
	dp[r][c] = a[r][c] + max_;
	return dp[r][c];
}

int main() {
	int a[6][5] = {
		{4,2,8,5,3},
		{3,2,4,2,2},
		{2,3,3,2,9},
		{3,3,2,6,4},
		{3,2,5,5,5},
		{6,3,8,6,2}
	};
	int dp[1000][1000];
	memset(dp, -1, sizeof(dp));
	// calculate for starting from each element of first row
	int max_coins=0;
	for (int i=0; i<5; i++) {
		max_coins = max(max_coins, collect(a, 0, i, 6, 5, dp));
	}
	cout << max_coins << endl;
}