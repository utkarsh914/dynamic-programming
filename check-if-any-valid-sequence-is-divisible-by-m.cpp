/*
https://practice.geeksforgeeks.org/problems/check-if-any-valid-sequence-is-divisible-by-m/0/

Given an array of N integers, using ‘+’ and ‘-‘ between the elements check if there is a way to form a sequence of numbers which evaluate to a number divisible by M.

Input:
The first line contains T, the number of test cases.For each test case, the first line contains an integer n denoting the size of the array A. Next line contains n-space separated integers and next line contains an integer m denoting the number from which divisibility needs to be checked. 

Output:
For each test case, the output is 1 if divisible else 0.

Constraints:
1<=T<=100
1<=n<=50
1<=m<=10
Note: Sum of elements should be less than 1000.

Example:
Input
2
5
1 2 3 4 6
4
3
1 3 9
2
Output
1
0

Explanation:
1.There is a valid sequence i. e., (1 - 2 + 3 + 4 + 6), which evaluates to 12 that is divisible by 4.
2.There is no sequence which evaluates to a number divisible by 2.

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

int cal(int arr[], int dp[51][1001], int n, int ind, int sum, int mod) {
	// mod the sum first
	sum = sum % mod;
	// base case (all possibilities are already calculated)
	// now if the sum is 0 after taking its mod above
	// it means it is divisible;
	if (ind==n)
		return (sum==0) ? 1 : 0;
		
	if (dp[ind][sum] != -1)
		return dp[ind][sum];
	
	// either add the curr element or subtract it
	int add = cal(arr, dp, n, ind+1, sum+arr[ind], mod);
	int sub = cal(arr, dp, n, ind+1, sum-arr[ind], mod);
	dp[ind][sum] = add || sub;

	return dp[ind][sum];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		int a[n];
		for (int i=0; i<n; i++) cin>>a[i];
		int m; cin>>m;
		
		int dp[51][1001];
		memset(dp, -1, sizeof(dp));
		cout << cal(a, dp, n, 1, a[0], m) << el;
	}
}