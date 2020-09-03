/*
LONGEST INCREASING SUBSEQUENCE BY DYNAMIC PROGRAMMING

https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0

*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lis(int arr[], int pos) {
	vector<int> dp(pos+2, 1);
	int ans = 1;
	for (int i=1; i<=pos; i++) {
		for (int j=0; j<i; j++) {
			if (arr[i] > arr[j]) {
			    dp[i] = max(dp[i], dp[j]+1);
				ans = max(ans, dp[i]);
			}
		}
	}
	return ans;
}

int main() {
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		int arr[n];
		for (int i=0; i<n; i++) cin>>arr[i];
		int ans = lis(arr, n-1);
		cout << ans << endl;
	}
}