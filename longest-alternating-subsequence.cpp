/*
https://practice.geeksforgeeks.org/problems/longest-alternating-subsequence/0/

A sequence {x1, x2, .. xn} is alternating sequence if its elements satisfy one of the following relations :

x1 < x2 > x3 < x4 > x5..... or  x1 >x2 < x3 > x4 < x5.....

Your task is to find the longest such sequence.

 

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer N denoting the size array A.

The second line of each test case contains N space separated integers denoting elements of the array A[ ].


Output:

Print the length of the longest alternating subsequence for each testcase in a new line.


Constraints:

1<= T <=100

1<= N <=1000

1<= A[ ] <=1000


Example:

Input:

2

3

1 5 4

8

10 22 9 33 49 50 31 60

Output:

3

6

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

// ============== O(N^2) time, O(n) space ===========

int las(int arr[], int n) {
	// n is length
	int dp[n][2] = {{0}};
	dp[0][0] = 1;
	dp[0][1] = 1;

	int ans = 1;
	for (int i=1; i<n; i++) {
		for (int j=0; j<i; j++) {
			if (arr[i] < arr[j]) {
				dp[i][0] = max(dp[i][0], dp[j][1]+1);
			}
			if (arr[i] > arr[j]) {
				dp[i][1] = max(dp[i][1], dp[j][0]+1);
			}
			ans = max(ans, max(dp[i][0], dp[i][1]));
		}
	}
	return ans;
}

/*
=============== O(n) time, O(1) space ============
*/
int signum(int n) {
	if (n==0)
		return 0;
	return (n>0) ? 1 : -1;
}

int lass(int a[], int n) {
	// n is length
	int len1 = 1, len2=1;
	int prevSign = 0;
	for (int i=1; i<n; i++) {
		int currsign = signum(a[i]-a[i-1]);
		if (currsign != prevSign and currsign != 0)
			len1++, prevSign=currsign;
	}
	
	prevSign=0;
	for (int i=1; i<n; i++) {
		int currsign = signum(a[i-1]-a[i]);
		if (currsign != prevSign and currsign != 0)
			len2++, prevSign=currsign;
	}

	return max(len1, len2);
}


int main() {
	furr;
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		int a[n];
		for (int i=0; i<n; i++) cin>>a[i];
		cout << lass(a,n) <<el;
	}
}