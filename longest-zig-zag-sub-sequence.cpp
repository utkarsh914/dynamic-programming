/*
https://practice.geeksforgeeks.org/problems/longest-zig-zag-sub-sequence/0/

Given an array A of N positive integers. The task is to find the longest Zig-Zag subsequence problem such that all elements of this are alternating (Ai-1 < Ai > Ai+1).

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case contains an integer N which denotes the number of elements in the array A. Next line contains space separated n elements in the array A.​

Output:
Print the length of the longest such subsequence.

Constraints:
1 <= T <= 200
1 <= N <= 103
1 <= Ai <= 105

Example:
Input:
2
6
5 5 10 100 10 5
3
1 2 3

Output:
3
2

Explanation:
Testcase 1: 5, 10, 5 is the longest common subsequence with elements alternating.

*/

#include<bits/stdc++.h>
#include<iostream>
#define furr			ios_base::sync_with_stdio(false); cin.tie(NULL)
#define el				"\n"
#define ll				long long int
#define pb				push_back
#define mp				make_pair
#define ff				first
#define ss				second
#define u_m				unordered_map
#define u_s				unordered_set
#define p_q				priority_queue
using namespace		std;

int signum(int n) {
	if (n==0)
		return 0;
	return (n>0) ? 1 : -1;
}

int las(int a[], int n) {
	// n is length
	int ans = 1;
	int prevSign = 0;
	for (int i=1; i<n; i++) {
		int currsign = signum(a[i]-a[i-1]);
		if (currsign != prevSign and currsign != 0)
			ans++, prevSign=currsign;
	}

	return ans;
}

int main() {
	furr;
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		int a[n];
		for (int i=0; i<n; i++) cin>>a[i];
		cout << las(a,n) <<el;
	}
}