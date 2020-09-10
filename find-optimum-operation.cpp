/*
https://practice.geeksforgeeks.org/problems/find-optimum-operation/0/

You are given a number N. You have to find the number of operations required to reach N from 0. You have 2 operations available:

Double the number
Add one to the number
Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer N.

Output:
For each test case, in a new line, print the minimum number of operations required to reach N from 0.

Constraints:
1<=T<=100
1<=N<=104

Example:
Input:
2
8
7
Input:
4
5

Explanation:
Testcase1:
Input  : N = 8
Output : 4
0 + 1 = 1, 1 + 1 = 2, 2 * 2 = 4, 4 * 2 = 8
Testcase2:
Input  : N = 7
Output : 5
0 + 1 = 1, 1 + 1 = 2, 1 + 2 = 3, 3 * 2 = 6, 6 + 1 = 7

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

int reach(int N) {
	int dp[N+1]={0};
	dp[0]=0; dp[1]=1;

	for (int i=2; i<=N; i++) {
		
		int prev=INT_MAX-1;
		if (i%2==0 && i/2>0)
			prev=dp[i/2];
		dp[i]=min(prev+1, dp[i-1]+1);
	}
	return dp[N];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		cout << reach(n) <<el;
	}
}