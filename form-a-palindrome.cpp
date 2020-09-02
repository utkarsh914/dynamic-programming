/*
https://practice.geeksforgeeks.org/problems/form-a-palindrome/0

Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
For Example:
ab: Number of insertions required is 1. bab or aba
aa: Number of insertions required is 0. aa
abcd: Number of insertions required is 3. dcbabcd

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is S.

Output:

Print the minimum number of characters.

Constraints:

1 ≤ T ≤ 50
1 ≤ S ≤ 40

Example:

Input:
3
abcd
aba
geeks

Output:
3
0
3
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
to form a palindrome out of a string we need to insert the same no. of characters
as the no. of characters req to be deleted
to form its longest palindromic subsequence
*/

int lcs(string s1, string s2, int m, int n, int dp[][100]) {
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


int main()
 {
	int t; cin>>t;
	while (t--) {
		string s1; cin>>s1;
		string s2 = s1;
		reverse(s2.begin(), s2.end());
		int l = s1.length();
		int dp[100][100];
		memset(dp, -1, sizeof(dp));
		int lcsresult = lcs(s1, s2, l, l, dp);

		cout << l-lcsresult << endl;
	}
	return 0;
}