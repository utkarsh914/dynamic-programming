/*
https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0/
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

int lcs(string s1, string s2, int m, int n) {
	
	if (m<0 || n<0) return 0;
	// if result exists already
	if (dp[m][n] != -1) return dp[m][n];
	
	// if last characters are equal
	if (s1[m]==s2[n])
		dp[m][n] = 1 + lcs(s1, s2, m-1, n-1);
	// otherwise
	else {
		dp[m][n] = max(lcs(s1, s2, m-1, n), lcs(s1, s2, m, n-1));
	}
	
	return dp[m][n];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; cin>>t;
	while (t--) {
		int l1, l2; cin>>l1>>l2;
		string s1, s2; cin>>s1>>s2;
		memset(dp, -1, sizeof(dp));
		cout<<lcs(s1, s2, l1-1, l2-1)<<el;
	}
}