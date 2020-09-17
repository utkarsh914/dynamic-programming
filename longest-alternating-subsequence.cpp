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

int las1(int arr[], int pos) {
	vector<int> dp(pos+2, 1);
	int ans = 1;
	for (int i=1; i<=pos; i++) {
		for (int j=0; j<i; j++) {
			if (dp[j]%2==0 && arr[i]>arr[j]) {
				dp[i] = max(dp[i], dp[j]+1);
			}
			else if (dp[j]%2==1 && arr[i]<arr[j]) {
				dp[i] = max(dp[i], dp[j]+1);
			}
			ans = max(ans, dp[i]);
		}
	}
	return ans;
}

int las2(int arr[], int pos) {
	vector<int> dp(pos+2, 1);
	int ans = 1;
	for (int i=1; i<=pos; i++) {
		for (int j=0; j<i; j++) {
			if (dp[j]%2==1 && arr[i]>arr[j]) {
				dp[i] = max(dp[i], dp[j]+1);
			}
			else if (dp[j]%2==0 && arr[i]<arr[j]) {
				dp[i] = max(dp[i], dp[j]+1);
			}
			ans = max(ans, dp[i]);
		}
	}
	return ans;
}

int c(int a[], int n) {
	if (n==1 or n==2 or n==3)
		return n;
	int ans1=2, ans2=2;
	for (int i=1; i<n-1; i++) {
		if (a[i]<a[i-1] && a[i]<a[i+1])
			ans1++;
	}
	for (int i=1; i<n-1; i++) {
		if (a[i]>a[i-1] && a[i]>a[i+1])
			ans2++;
	}
	return max(ans1, ans2);
}

int main() {
	furr;
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		int a[n];
		for (int i=0; i<n; i++) cin>>a[i];
		// cout << c(a,n) <<el;
		cout << max(las1(a,n-1), las2(a,n-1)) <<el;
	}
}