/*
https://practice.geeksforgeeks.org/problems/minimum-insertions-to-sort-an-array/0/

Given an array of integer numbers, we need to sort this array in a minimum number of steps where in one step we can insert any array element from its position to any other position.

 

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer N denoting the size of array A.

The second line of each test case contains N space separated integers denoting elements of the array A[ ].


Output:

Output the minimum steps needed to sort the array. Print the answer for each test case in a new line.


Constraints:

1<= T <=100

1<= N <=1000

1<= A[ ] <=1000


Example:

Input:

1

7

2 3 5 1 4 7 6

Output:

3
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

int lis(int arr[], int pos) {
	vector<int> dp(pos+2, 1);
	int ans = 1;
	for (int i=1; i<=pos; i++) {
		for (int j=0; j<i; j++) {
			if (arr[i] >= arr[j]) {
				dp[i] = max(dp[i], dp[j]+1);
				ans = max(ans, dp[i]);
			}
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		int a[n];
		for (int i=0; i<n; i++) cin>>a[i];
		cout<<n-lis(a,n-1)<<el;
	}
}