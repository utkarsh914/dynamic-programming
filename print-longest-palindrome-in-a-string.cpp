/*
https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0

Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index ).

NOTE: Required Time Complexity O(n2).

Input:
The first line of input consists number of the testcases. The following T lines consist of a string each.

Output:
In each separate line print the longest palindrome of the string given in the respective test case.

Constraints:
1 ≤ T ≤ 100
1 ≤ Str Length ≤ 104

Example:
Input:
1
aaaabbaa

Output:
aabbaa

Explanation:
Testcase 1: The longest palindrome string present in the given string is "aabbaa".

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void lcs(string s, int n) {
	bool dp[n+1][n+1] = {false};
	for (int i=0; i<n; i++)
		dp[i][i]=true;
		
	int max_=1, start=0;
	bool flag=false;
	
	for (int i=0; i<n-1; i++) {
		if (s[i]==s[i+1]) {
			dp[i][i+1] = true;
			if (!flag) {
				max_=2, start=i;
				flag=true;
			}
		}
	}
	// k is length
	for (int k=3; k<=s.length(); k++) {
		for (int i=0; i<=s.length()-k; i++) {
			int j = i+k-1;
			if (s[i]==s[j] && dp[i+1][j-1]==true) {
				dp[i][j] = true;
				if (k > max_) {
					max_ = k;
					start = i;
				}
			}
		}
	}
	
	cout << s.substr(start, max_) <<endl;
}

int main()
 {
	int t; cin>>t;
	while (t--) {
		string s1; cin>>s1;
		lcs(s1, s1.length());
	}
	return 0;
}