/* I want to be the very best like no one ever was */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, int m, int n, int dp[][1000]) {
	if (m==0 || n==0) return 0;
	// if result exists already
	if (dp[m-1][n-1] != -1) return dp[m-1][n-1];

	// if last characters are equal
	if (s1[m-1] == s2[n-1]) {
		int temp = lcs(s1, s2, m-1, n-1, dp) + 1;
		dp[m-1][n-1] = temp;
		return temp;
	}
	// otherwise
	int lcs1 = lcs(s1, s2, m-1, n, dp);
	int lcs2 = lcs(s1, s2, m, n-1, dp);
	dp[m-1][n-1] = max(lcs1, lcs2);
	return dp[m-1][n-1];
}

int main() {
	string s1, s2;
	cin>>s1; cin>>s2;
	int m = s1.length();
	int n = s2.length();
	int maximum = max(m, n);
	// make a container to dp results;
	int dp[maximum][1000];
	memset(dp, -1, sizeof(dp));

	cout << lcs(s1, s2, m, n, dp) << endl;
}