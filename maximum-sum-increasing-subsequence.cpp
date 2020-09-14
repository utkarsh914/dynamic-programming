/*
MAXIMUM SUM INCREASING SUBSEQUENCE BY DYNAMIC PROGRAMMING
https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0/

Given an array A of N positive integers. Find the sum of maximum sum increasing subsequence of the given array.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N(the size of array). The second line of each test case contains array elements.

Output:
For each test case print the required answer in new line.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 106
1 ≤ Ai ≤ 106

Example:
Input:
2
7
1 101 2 3 100 4 5
4
10 5 4 3

Output:
106
10

Explanation:
Testcase 1: All the increasing subsequences are : (1,101); (1,2,3,100); (1,2,3,4,5). Out of these (1, 2, 3, 100) has maximum sum,i.e., 106.
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ================= ALTERNATE ===============
class Solution{
	public:
	int maxSumIS(int a[], int n)  
	{
		int dp[n+1];
		for (int i=0; i<n; i++)
			dp[i]=a[i];
		
		int ans=dp[0];
		for (int i=1; i<n; i++) {
			for (int j=0; j<i; j++) {
				if (a[i] > a[j])
					dp[i] = max(dp[i], dp[j]+a[i]);
			}
			ans=max(ans, dp[i]);
		}
		return ans;
	}  
};

int lis(int arr[], int pos) {
	int dp[pos+1];
	// max sum of subsequence of first ele is itself
	dp[0] = arr[0];

	for (int i=1; i<=pos-1; i++) {
		int maxx = 0;
		for (int j=0; j<i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[j] > maxx) maxx = dp[j];
			}
		}
		dp[i] = arr[i] + maxx;
	}

	// find the max element in dp
	int max_ = INT_MIN;
	for (int i=0; i<pos; i++) max_ = max(max_, dp[i]);
	return max_;
}

int main() {
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		int arr[n];
		for (int i=0; i<n; i++) cin>>arr[i];
		int ans = lis(arr, n);
		cout << ans << endl;
	}
}