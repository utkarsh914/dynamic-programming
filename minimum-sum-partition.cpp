/*
https://practice.geeksforgeeks.org/problems/minimum-sum-partition/0

Given an array, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer 'N' denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.


Output:
In each seperate line print minimum absolute difference.


Constraints:
1<=T<=200
1<=N<=50
1<=A[i]<=200


Example:
Input:
2
4
1 6 5 11
4
36 7 46 40

Output : 
1
23

Explaination :
Testcase 1:
Subset1 = {1, 5, 6} ; sum of Subset1 = 12
Subset2 = {11} ;	   sum of Subset2 = 11

Testcase 2:
Subset1 = {7, 46} ;   sum = 53
Subset2 = {36, 40} ; sum = 76
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

// Returns minimum possible difference between sums 

int findMin(int arr[], int n, int sum1, int sum2, int dp[51][11001]) {
	// n is index, so if it went neagtive, means computation is completed
	if (n < 0)
		return abs(sum1-sum2);
	
	if (dp[n][sum1] != -1)
		return dp[n][sum1];
	
	// include current element in sum1 or not include(include in sum2)
	int include = findMin(arr, n-1, sum1+arr[n], sum2, dp);
	int exclude = findMin(arr, n-1, sum1, sum2+arr[n], dp);
	dp[n][sum1] = min(include, exclude);
	
	return dp[n][sum1];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		int a[n];
		for (int i=0; i<n; i++) cin>>a[i];
	
		int dp[51][11001];
		memset(dp, -1, sizeof (dp));
		cout<<findMin(a,n-1,0,0,dp)<<el;
	}
}