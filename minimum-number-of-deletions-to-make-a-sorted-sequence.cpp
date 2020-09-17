/*
https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-to-make-a-sorted-sequence3248/1

Given an array arr of size N, the task is to remove or delete the minimum number of elements from the array so that when the remaining elements are placed in the same sequence order form an increasing sorted sequence.

Example 1:

Input: N = 5, arr[] = {5, 6, 1, 7, 4}
Output: 2
Explanation: Removing 1 and 4
leaves the remaining sequence order as
5 6 7 which is a sorted sequence.
 
Example 2:
Input: N = 3, arr[] = {1, 1, 1}
Output: 2
Explanation: Remove 2 1's


Your Task:  
You don't need to read input or print anything. Complete the function minDeletions() which takes N and array arr as input parameters and returns the integer value

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 103

*/

class Solution{
	public:
		int lis(int arr[], int pos) {
			vector<int> dp(pos+2, 1);
			int ans = 1;
			for (int i=1; i<=pos; i++) {
				for (int j=0; j<i; j++) {
					if (arr[i] > arr[j]) {
						dp[i] = max(dp[i], dp[j]+1);
						ans = max(ans, dp[i]);
					}
				}
			}
			return ans;
		}

		int minDeletions(int a[], int n) {
			return n-lis(a,n-1);
		}
};