/*
https://practice.geeksforgeeks.org/problems/convert-to-strictly-increasing-array/0

Given an array A of N positive integers. Find the minimum number of operations (change a number to greater or lesser than original number) in array so that array is strictly increasing (A[i] < A[i+1]).

Note : The array should remain array of integers.  For example, consider {6, 9, 7}, we cannot insert 6.x between and 7.

Input:
First line consists of T test cases. First line of every line test case consists of N, denoting number of elements in array. Second line of every test case consists of array elements.

Output:
Single line output, print the minimum operations to be done to make it strictly increasing.

Constraints:
1 <= T <= 106
1 <= N <= 106
1 <= Ai <= 108

Example:
Input:
2
6
1 2 3 6 5 4
7
1 2 3 4 5 6 7
Output:
2
0
Explanation:
Testcase 1: Only 5 and 4 need to changed to some larger value to make the array strictly increasing.
*/

#include<bits/stdc++.h>
#include<iostream>
#define el "\n"
#define ll long long int
#define pb push_back
#define u_m unordered_map
#define u_s unordered_set
#define p_q priority_queue
using namespace std;

/*
If any two elements are in increasing order then
the diff of those elements should be greater than or equal to
diff b/w their indexes (i.e. arr[i]-arr[j]>=i-j)
to make Strictly increasing.

Ans = n-LIS
*/

int strictlyinc(int arr[], int n) {
	vector<int> dp(n+1, 1);
	int ans = 1;
	for (int i=1; i<=n-1; i++) {
		for (int j=0; j<i; j++) {
			if (arr[i]-arr[j] >= i-j) {
				dp[i] = max(dp[i], dp[j]+1);
				ans = max(ans, dp[i]);
			}
		}
	}
	return n-ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		int a[n];
		for (int i=0; i<n; i++) cin>>a[i];
		
		cout << strictlyinc(a,n) <<el;
	}
}