/*
https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence/0

Given a string str, find length of the longest repeating subseequence such that the two subsequence don’t have same string character at same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer N denoting the length of string str.

The second line of each test case contains the string str consisting only of lower case english alphabets.

Output:

Print the length of the longest repeating subsequence for each test case in a new line.


Constraints:

1<= T <=100

1<= N <=1000


Example:

Input:

2

3

abc

5

axxxy

Output:

0

2

*/

#include<bits/stdc++.h>
#include<iostream>
#define furr ios_base::sync_with_stdio(false); cin.tie(NULL)
#define el "\n"
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define u_m unordered_map
#define u_s unordered_set
#define p_q priority_queue
using namespace std;

int lcs(string s, int m, int n) {
	
	int dp[m+1][n+1];
	
	for (int i=0; i<=m; i++) {
		for (int j=0; j<=n; j++) {
			if (i==0 || j==0) dp[i][j]=0;
			else if (s[i-1]==s[j-1] && i!=j) {
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else {
				int l1 = dp[i][j-1];
				int l2 = dp[i-1][j];
				dp[i][j] = max(l1, l2);
			}
		}
	}
	return dp[m][n];
}

int main() {
	furr;
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		string s; cin>>s;
		cout<<lcs(s,n,n)<<el;
	}
}
