/*
https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence/0/

Given an array of positive integers. Find the maximum length of Bitonic subsequence. 
A subsequence of array is called Bitonic if it is first increasing, then decreasing.
 

Example 1:

Input: nums = [1, 2, 5, 3, 2]
Output: 5
Explanation: The sequence {1, 2, 5} is
increasing and the sequence {3, 2} is 
decreasing so merging both we will get 
length 5.

Example 2:

Input: nums = [1, 11, 2, 10, 4, 5, 2, 1]
Output: 6
Explanation: The bitonic sequence 
{1, 2, 10, 4, 2, 1} has length 6.
 

Your Task:
Your don't need to read or print anything. Your task is to complete the function LongestBitonicSequence() which takes the array nums[] as input parameter and returns the maximum length of bitonic subsequence.
 

Expected Time Complexity: O(n2)
Expected Space Complexity: O(n)
 

Constraints:
1 <= length of array <= 200
1 <= arr[i] <= 1000000

*/

class Solution{
	public:
	int LongestBitonicSequence(vector<int>a)
	{
	
		int n=a.size();
	
		int inc[n+1]; // strictly inc
		int dec[n+1]; // strictly dec
		// initial values
		for (int i=0; i<n; i++)
			inc[i]=dec[i]=1;

		// calculate greatest sum inc subsequence from front to last
		for (int i=1; i<n; i++) {
			for (int j=0; j<i; j++) {
				if (a[i]>a[j] && 1+inc[j]>inc[i]) {
					inc[i] = 1+inc[j];
				}
			}
		}
		// calculate greatest sum inc subsequence from last to front
		// i.e. greatest sum dec subseq from that position onwards
		for (int i=n-2; i>=0; i--) {
			for (int j=n-1; j>i; j--) {
				if (a[i]>a[j] && 1+dec[j]>dec[i]) {
					dec[i] = 1+dec[j];
				}
			}
		}

		int ans=INT_MIN;
		for (int i=0; i<n; i++) {
			ans = max(ans, inc[i]+dec[i]-1);
		}

		return ans;
	
	}
};