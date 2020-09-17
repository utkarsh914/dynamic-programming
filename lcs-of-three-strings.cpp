/*
https://practice.geeksforgeeks.org/problems/lcs-of-three-strings/0/

Given 3 strings X, Y and Z, the task is to find the longest common sub-sequence in all three given sequences.

 

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains integers n, m and k denoting the length of strings X, Y and Z respectively.

The second line of each test case contains the three strings X, Y and Z. The string consists of only lower case english alphabets.

Output:

Print the length of the longest common sub- sequence of the three strings for each test case in a new line.


Constraints:
1<= T <=100
1<= N, M, K <=100


Example:
Input:
1
5 8 13
geeks geeksfor geeksforgeeks

Output:
5

Explanation:
All the 3 strings given have "geeks" as the longest subsequence present which has a length of 5.
geeks geeksfor geeksforgeeks

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

int triple_lcs(string s1, string s2, string s3, int l1, int l2, int l3) {

	int dp[l1+1][l2+1][l3+1];

	for (int i=0; i<=l1; i++)
	for (int j=0; j<=l2; j++)
	for (int k=0; k<=l3; k++) {
		if (i==0 || j==0 || k==0)
			dp[i][j][k] = 0;
		else if (s1[i-1]==s2[j-1] && s2[j-1]==s3[k-1])
			dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
		else {
			dp[i][j][k] = max( max(dp[i-1][j][k], dp[i][j-1][k]), dp[i][j][k-1]);
			// int arr[6];
			// arr[0] = dp[i][j][k-1];
			// arr[1] = dp[i][j-1][k];
			// arr[2] = dp[i][j-1][k-1];
			// arr[3] = dp[i-1][j][k];
			// arr[4] = dp[i-1][j][k-1];
			// arr[5] = dp[i-1][j-1][k];
			
			// dp[i][j][k] = arr[0];
			// for (int x=1; x<6; x++)
			// 	dp[i][j][k] = max(dp[i][j][k], arr[x]);
		}
	}

	return dp[l1][l2][l3];

}

int main() {
	furr;
	int t; cin>>t;
	while (t--) {
		int l1,l2,l3; cin>>l1>>l2>>l3;
		string s1, s2, s3; cin>>s1>>s2>>s3;
		cout<<triple_lcs(s1,s2,s3,l1,l2,l3)<<el;
	}
}