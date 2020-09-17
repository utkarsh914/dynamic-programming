/*
https://practice.geeksforgeeks.org/problems/count-of-strings-that-can-be-formed-using-a-b-and-c-under-given-constraints/0

Given a length n, count the number of strings of length n that can be made using ‘a’, ‘b’ and ‘c’ with at-most one ‘b’ and two ‘c’s allowed.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer N denoting the length of the string.

Output:
Output the count of the strings that can be formed under the given constraint.

Constraints:

1<= T <=100
1<= N <=1000

Example:

Input:
2
1
3

Output:
3
19

Explanation:
Test Case 1: N = 1
Possible strings are: "a", "b" and "c"

Test Case 2: N = 3
Number of strings with 3 occurrances of a: 1
2-a and 1-b: 3
2-a and 1-c: 3
1-a, 1-b and 1-c: 6
1-a and 2-c: 3
1-b and 2-c: 3
Hence, total number of strings of length 3 = 1 + 3 + 3 + 6 + 3 + 3 = 19

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

// ============= RECURSIVE SOLUTION ==============
int form(int n, int b, int c) {
	if (n==0)
		return 1;
	if (b==0 && c==0)
		return 1;
	
	int x=0, y=0, z=0;
	x = form(n-1, b, c);
	if (b>0)
		y = form(n-1, b-1, c);
	if (c>0)
		z = form(n-1, b, c-1);
	return x+y+z;
}


// ============== BOTTOM-UP DP ==============
int form(int n) {

	int dp[n+1][2][3];

	for (int i=0; i<=1; i++)
		for (int j=0; j<=2; j++)
			dp[0][i][j]=1;

	for (int i=1; i<=n; i++) {
		for (int j=0; j<=1; j++) {
			for (int k=0; k<=2; k++) {
				if (j==0 && k==0) {
					dp[i][0][0]=1;
					continue;
				}
				int ans=dp[i-1][j][k];
				if (j>0) ans+=dp[i-1][j-1][k];
				if (k>0) ans+=dp[i-1][j][k-1];
				dp[i][j][k] = ans;
			}
		}
	}

	return dp[n][1][2];
}

int main() {
	furr;
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		// cout<<form(n,1,2)<<el;
		cout<<form(n)<<el;
	}
}