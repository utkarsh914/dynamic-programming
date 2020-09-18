/*
https://practice.geeksforgeeks.org/problems/minimum-steps-to-delete-a-string2956/1

Given string s containing characters as integers only, the task is to delete all characters of this string in a minimum number of steps wherein one step you can delete the substring which is a palindrome. After deleting a substring remaining parts are concatenated.

Example 1:

Input: s = "2553432"
Output: 2
Explanation: In first step remove "55", 
then string becomes "23432" which is a 
palindrome.
Example 2:
Input: s = "1234"
Output: 4
Explanation: Remove each character in 
each step

Your Task:  
You don't need to read input or print anything. Complete the function minStepToDeleteString() which string s as input parameters and returns the integer value

Expected Time Complexity: O(|s|2)
Expected Auxiliary Space: O(|s|2)

Constraints:
1 ≤ |s| ≤ 10^3

*/

class Solution{
	public:
		int minStepToDeleteString(string s);
};

int Solution::minStepToDeleteString(string s) {
	int N = s.length();
	int dp[N+1][N+1] = {{0}};

	for (int len=1; len<=N; len++)
	for (int i=0, j=len-1; j<N; i++, j++)
	{
		if (len==1) {
			dp[i][j] = 1;
			continue;
		}

		dp[i][j] = 1 + dp[i+1][j];

		if (s[i]==s[i+1])
			dp[i][j] = min(dp[i][j], 1 + dp[i+2][j]);

		for (int k=i+2; k<=j; k++) {
			if (s[i]==s[k])
				dp[i][j] = min(dp[i][j], dp[i+1][k-1] + dp[k+1][j]);
		}

	}

	return dp[0][N-1];
}