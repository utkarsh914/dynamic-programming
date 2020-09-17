/*
https://practice.geeksforgeeks.org/problems/minimum-cost-to-make-two-strings-identical1107/1

Given two strings X and Y, and two values costX and costY, the task is to find the minimum cost required to make the given two strings identical. You can delete characters from both the strings. The cost of deleting a character from string X is costX and from Y is costY. The cost of removing all characters from a string is the same.

Example 1:

Input: X = "abcd", Y = "acdb", costX = 10 
       costY = 20.
Output: 30
Explanation: For Making both strings 
identical we have to delete character 
'b' from both the string, hence cost 
will be = 10 + 20 = 30.
Example 2:

Input : X = "ef", Y = "gh", costX = 10
        costY = 20.
Output: 60
Explanation: For making both strings 
identical, we have to delete 2-2 
characters from both the strings, hence 
cost will be = 10 + 10 + 20 + 20 = 60.
Your Task:
You don't need to read or print anything. Your task is to complete the function findMinCost() which takes both strings and the costs as input parameters and returns the minimum cost.

Expected Time Complexity: O(|X|*|Y|)
Expected Space Complexity: O(|X|*|Y|)

Constraints:
1 ≤ |X|, |Y| ≤ 1000

*/

class Solution{

	public:
	int findMinCost(string X, string Y, int costX, int costY) {
		
		int dp[X.length()+1][Y.length()+1];
		// if both string are empty
		dp[0][0] = 0;
		// if first string is 0 length
		for (int i=1; i<=Y.length(); i++)
			dp[0][i] = dp[0][i-1]+costY;

		// if second string is 0 length
		for (int i=1; i<=X.length(); i++)
			dp[i][0] = dp[i-1][0]+costX;

		for (int i=1; i<=X.length(); i++) {
			for (int j=1; j<=Y.length(); j++) {
				if (X[i-1]==Y[j-1])
					dp[i][j] = dp[i-1][j-1];
				else {
					// delete char from 1st and 2nd strings, so add its cost
					// then take min of both operations
					int cost1 = costX + dp[i-1][j];
					int cost2 = costY + dp[i][j-1];
					dp[i][j] = min(cost1, cost2);
				}
			}
		}

		return dp[X.length()][Y.length()];

	}
  
};