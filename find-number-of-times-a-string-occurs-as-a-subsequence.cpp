/*
https://practice.geeksforgeeks.org/problems/find-number-of-times-a-string-occurs-as-a-subsequence3020/1

Given two strings S1 and S2, find the number of times the second string occurs in the first string, whether continuous or discontinuous.


Example 1:

Input: 
S1 = geeksforgeeks
S2 = gks
Output: 4
Explaination: For the first 'g' there 
are 3 ways and for the second 'g' there 
is one way. Total 4 ways.

Your Task:
You don't need to read input or print anything. Your task is to complete the function countWays() which takes the string S1 and S2 as input parameters and returns the number of ways.


Expected Time Complexity: O(n*m)		[n and m are length of the strings]
Expected Auxiliary Space: O(n*m)


Constraints:
1 ≤ n, m ≤ 500

*/

// geeksforgeeks
// gks

class Solution{
public:
	// n1 n2 are lengths
	// ============ RECURSIVE ============
	int c(string s, string key, int n1, int n2) {
		if ((n1==0 && n2==0) or (n2==0))
			return 1;
		if (n1 == 0)
			return 0;
		
		if (s[n1-1]==key[n2-1])
			return c(s, key, n1-1, n2-1) + c(s, key, n1-1, n2);
		// if key not found
		return c(s, key, n1-1, n2);
	}

	// =============== BOTTOM-UP DP ================
	int countWays(string s1, string s2){

		int dp[s1.length()+1][s2.length()+1];

		for (int i = 0; i <= s1.length() ; i++) {
			for (int j = 0; j <=s2.length(); j++) {
				if ((i==0 and j==0) or (j==0))
					dp[i][j]=1;
				else if (i==0)
					dp[i][j]=0;
				else if(s1[i-1]==s2[j-1])
					dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
				else
					dp[i][j] = dp[i-1][j];
			}
		}

		return dp[s1.length()][s2.length()];
	}
};