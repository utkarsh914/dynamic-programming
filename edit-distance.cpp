/*
https://practice.geeksforgeeks.org/problems/edit-distance/0/

Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1′ into ‘str2′.

Insert
Remove
Replace
All of the above operations are of cost=1.
Both the strings are of lowercase.

Input:
The First line of the input contains an integer T denoting the number of test cases. Then T test cases follow. Each tese case consists of two lines. The first line of each test case consists of two space separated integers P and Q denoting the length of the strings str1 and str2 respectively. The second line of each test case coantains two space separated strings str1 and str2 in order.

Output:
Corresponding to each test case, pirnt in a new line, the minimum number of operations required.

Constraints:
1 <= T <= 50
1 <= P <= 100
1 <= Q <= 100

Example:
Input:
1
4 5
geek gesek

Output:
1

Explanation:
Testcase 1: One operation is required to make 2 strings same i.e. removing 's' from str2
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, int m, int n) {
	int dp[m+1][n+1];
	for (int i=0; i<=m; i++) {
		for (int j=0; j<=n; j++) {
			if (i==0 || j==0)
				dp[i][j] = max(i,j);
			else if (s1[i-1]==s2[j-1])
				dp[i][j] = dp[i-1][j-1];
			else {
				int a1 = dp[i-1][j] + 1;
				int a2 = dp[i][j-1] + 1;
				int a3 = dp[i-1][j-1] + 1;
				dp[i][j] = min(min(a1,a2),a3);
			}
		}
	}
	return dp[m][n];
}

int main() {
	int t; cin>>t;
	while (t--) {
		int m,n; cin>>m>>n;
		string s1, s2;
		cin>>s1; cin>>s2;
		cout << lcs(s1, s2, m, n) << endl;
	}
}