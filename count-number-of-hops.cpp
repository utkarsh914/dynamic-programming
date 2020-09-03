/*
https://practice.geeksforgeeks.org/problems/count-number-of-hops/0/

A frog jumps either 1, 2 or 3 steps to go to top. In how many ways can it reach the top.

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. Each testcase contains one line of input N denoting the total number of steps.

Output:
For each testcase, in a new line, print the number of ways to reach the top.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 50

Example:
Input:
2
1
5
Output:
1
13

Explanation:
Testcase 1:
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

int dp[51];

int hop(int dist) {
	if (dist < 0) return 0;
	if (dist == 0) return 1;
	if (dp[dist] != -1) return dp[dist];
	
	dp[dist] = hop(dist-1) + hop(dist-2) + hop(dist-3);
	return dp[dist];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		memset(dp, -1, sizeof(dp));
		cout << hop(n) << el;
	}
}