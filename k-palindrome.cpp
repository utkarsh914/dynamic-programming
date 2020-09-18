/*
https://practice.geeksforgeeks.org/problems/k-palindrome/1/

A string is k palindrome if it can be transformed into a palindrome on removing at most k characters from it. Your task is to complete the function is_k_palin which takes two arguments a string str and a number N . Your function should return true if the string is k palindrome else it should return false.

Input:
The first line of input is an integer T denoting the number of test cases . Then T test cases follow . Each test case  contains a string str and an integer N separated by space.  

Output:
The output will be 1 if the string is  k palindrome else 0 .

Constraints:
1<=T<=100
1<=length of str<=100
1<=N<=20

Example:
Input
2
abcdecba 1
acdcb  1
Output
1
0

*/

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

bool is_k_palin(string s,int k)
{
	string s2 = s;
	reverse(s2.begin(), s2.end());
	int l = s.length();
	return (l-lcs(s,s2,l,l))<=k;
}