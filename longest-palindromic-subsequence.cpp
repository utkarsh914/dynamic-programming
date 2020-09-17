/*
https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence/0/

Given a String, find the longest palindromic subsequence

Input:
The first line of input contains an integer T, denoting no of test cases. The only line of each test case consists of a string S(only lowercase)

Output:
Print the Maximum length possible for palindromic subsequence.

Constraints:
1<=T<=100
1<=|Length of String|<=1000
 

Examples:
Input:
2
bbabcbcab
abbaab
Output:
7
4
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

int lcs(string s1, string s2, int m, int n) {
	
	int dp[m+1][n+1];
	
	for (int i=0; i<=m; i++) {
		for (int j=0; j<=n; j++) {
			if (i==0 || j==0) dp[i][j]=0;
			else if (s1[i-1]==s2[j-1]) {
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
		string s1; cin>>s1;
		string s2=s1;
		reverse(s2.begin(), s2.end());
		cout<<lcs(s1,s2, s1.length(), s2.length())<<el;
	}
}