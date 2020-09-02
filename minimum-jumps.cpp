/*
https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0/

Given an array of integers where each element represents the max number of steps that can be made forward from that element. The task is to find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then cannot move through that element.

Input: 
The first line contains an integer T, depicting total number of test cases.  Then following T lines contains a number n denoting the size of the array. Next line contains the sequence of integers a1, a2, ..., an.

Output:
For each testcase, in a new line, print the minimum number of jumps. If answer is not possible print "-1"(without quotes).

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
0 <= ai <= 107

Example:
Input:
2
11
1 3 5 8 9 2 6 7 6 8 9
6
1 4 3 2 6 7
Output:
3
2

Explanation:
Testcase 1: First jump from 1st element, and we jump to 2nd element with value 3. Now, from here we jump to 5h element with value 9. and from here we will jump to last
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int minJumps(vector<int> &dp, int arr[], int pos, int n) {
	// if result is already computed, return it
	if (dp[pos] != -1) return dp[pos];
	// base conditions
	if (pos>=n) return INT_MAX;
	if (pos==n-1) return 0;

	int maxjump=arr[pos];
	int minvalue = INT_MAX;
	for (int i=1; i<=maxjump; i++) {
		minvalue = min(minvalue, minJumps(dp, arr, pos+i, n));
	}

	// if none of the option takes us ahead, then minvalue will be INT_MAX. So don't increase it
	if (minvalue==INT_MAX)
		dp[pos] = INT_MAX;
	else
		dp[pos] = minvalue + 1;
	return dp[pos];
}

int main() {
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		int arr[n];
		for (int i=0; i<n; i++) cin>>arr[i];
		vector<int> dp(n+1, -1);
		int ans = minJumps(dp, arr, 0, n);
		// if no jumps possible
		if (ans == INT_MAX) ans = -1;
		cout << ans << endl;
	}
}