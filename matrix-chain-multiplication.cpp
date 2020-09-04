/*
https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication/0

Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications. There are many options to multiply a chain of matrices because matrix multiplication is associative i.e. no matter how one parenthesize the product, the result will be the same.

Example:
 if you had four matrices A, B, C, and D, you would have:

	(ABC)D = (AB)(CD) = A(BCD) = ....
However, the order in which one parenthesize the product affects the number of simple arithmetic operations needed to compute the product, or the efficiency.

For example:

A: 10 × 30 matrix
B : 30 × 5 matrix
C : 5 × 60 matrix
Then,
	 (AB)C = (10×30×5) + (10×5×60) 
		   = 1500 + 3000 
		   = 4500 operations
	 A(BC) = (30×5×60) + (10×30×60) 
		   = 9000 + 18000 
		   = 27000 operations.
Given an array arr[] which represents the chain of matrices such that the ith matrix Ai is of dimension arr[i-1] x arr[i]. Your task is to write a function that should print the minimum number of multiplications needed to multiply the chain.

  Input: p[] = {40, 20, 30, 10, 30}   
  Output: 26000  
  There are 4 matrices of dimensions 40x20, 
  20x30, 30x10 and 10x30. Let the input 4 
  matrices be A, B, C and D.  The minimum 
  number of multiplications are obtained 
  by putting parenthesis in following way
  (A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30

  Input: p[] = {10, 20, 30, 40, 30} 
  Output: 30000 
  There are 4 matrices of dimensions 10x20, 
  20x30, 30x40 and 40x30. Let the input 4 
  matrices be A, B, C and D.  The minimum 
  number of multiplications are obtained by 
  putting parenthesis in following way
  ((AB)C)D --> 10*20*30 + 10*30*40 + 10*40*30
Input:
The first line of the input contains an integer T, denoting the number of test cases. Then T test case follows. The first line of each test case contains an integer N, denoting the number of elements in the array.
Then next line contains N space separated integers denoting the values of the element in the array.

Output:
For each test case the print the minimum number of operations needed to multiply the chain.

Constraints:
1<=T<=100
2<=N<=100
1<=A[]<=500

Example:
Input:
2
5
1 2 3 4 5
3
3 3 3
Output:
38
27

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

int dp[101][101];

int solve(int a[], int start, int end) {
	// base case
	if (start==end) {
		dp[start][end] = 0;
		return 0;
	}

	if (start > end)
		return 0;
	
	if (dp[start][end] != -1)
		return dp[start][end];
		
	int ans = INT_MAX;
	
	for (int i=start; i<=end-1; i++) {
		int left = solve(a, start, i);
		int right = solve(a, i+1, end);
		int sum = left + right + (a[start] * a[i+1] * a[end+1]);
		ans = min(ans, sum);
	}
	
	dp[start][end] = ans;
	
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		int a[n];
		for (int i=0; i<n; i++) cin>>a[i];
		memset(dp, -1, sizeof(dp));
		cout << solve(a,0,n-2) << el;
	}
}