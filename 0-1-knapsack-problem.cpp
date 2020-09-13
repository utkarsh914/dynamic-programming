/*
https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0

You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of four lines.
The first line consists of N the number of items.
The second line consists of W, the maximum capacity of the knapsack.
In the next line are N space separated positive integers denoting the values of the N items,
and in the fourth line are N space separated positive integers denoting the weights of the corresponding items.

Output:
For each testcase, in a new line, print the maximum possible value you can get with the given conditions that you can obtain for each test case in a new line.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 1000
1 ≤ W ≤ 1000
1 ≤ wt[i] ≤ 1000
1 ≤ v[i] ≤ 1000

Example:
Input:
2
3
4
1 2 3
4 5 1
3
3
1 2 3
4 5 6
Output:
3
0
Explanation:
Test Case 1: With W = 4, you can either choose the 0th item or the 2nd item. Thus, the maximum value you can generate is the max of val[0] and val[2], which is equal to 3.
Test Case 2: With W = 3, there is no item you can choose from the given list as all the items have weight greater than W. Thus, the maximum value you can generate is 0

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

/*
There are 2 cases for every item : either it is included in the bag or excluded.
Therefore, the maximum value that can be obtained from n items is max of following two values.
1) Maximum value obtained by n-1 items and W weight (excluding nth item).
2) Value of nth item plus maximum value obtained by n-1 items and W minus weight of the nth item (including nth item).
Iterate the DP array for all of W and N, store the value at DP[w][n] as max of above 2 conditions.
Return DP[W][N].
*/

int knapsack(int val[], int wt[], int N, int W) {
	
	int dp[N+1][W+1];
	// fill with zero
	for (int i=0; i<=N; i++)
		dp[i][0]=0;

	for (int i=1; i<=W; i++)
		dp[0][i]=0;
	
	int ans;
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=W; j++) {
			// if curr item wt is greater, don't include it
			if (wt[i-1] > j)
				dp[i][j] = dp[i-1][j];
			// else, take max of including it and not includeing it
			else {
				int include = val[i-1] + dp[i-1][j-wt[i-1]];
				int notinclude = dp[i-1][j];
				dp[i][j] = max(include, notinclude);
			}
		}
	}
	
	return dp[N][W];
}

// =================== RECURSIVE ====================
int recur_knapsack(int val[], int wt[], int N, int W) {
	if (N==0 or W==0)
		return 0;
	
	if (wt[N-1] > W)
		return recur_knapsack(val, wt, N-1, W);
	
	else {
		int v1 = val[N-1] + recur_knapsack(val, wt, N-1, W-wt[N-1]);
		int v2 = recur_knapsack(val, wt, N-1, W);
		return max(v1, v2);
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; cin>>t;
	while (t--) {
		int N,W; cin>>N>>W;
		int val[N], wt[N];
		for (int i=0; i<N; i++) cin>>val[i];
		for (int i=0; i<N; i++) cin>>wt[i];
		cout<<knapsack(val, wt, N, W)<<el;
	}
}