/*
https://practice.geeksforgeeks.org/problems/buying-vegetables/0/

Rahul wanted to purchase vegetables mainly brinjal, carrot and tomato. There are N different vegetable sellers in a line. Each vegetable seller sells all three vegetable items, but at different prices. Rahul, obsessed by his nature to spend optimally, decided not to purchase same vegetable from adjacent shops. Also, Rahul will purchase exactly one type of vegetable item (only 1 kg) from one shop. Rahul wishes to spend minimum money buying vegetables using this strategy. Help Rahul determine the minimum money he will spend.

Input:
First line indicates number of test cases T. Each test case in its first line contains N denoting the number of vegetable sellers in Vegetable Market. Then each of next N lines contains three space separated integers denoting cost of brinjal, carrot and tomato per kg with that particular vegetable seller.

Output:
For each test case, output the minimum cost of shopping taking the mentioned conditions into account in a separate line.

Constraints:
1 <= T <= 10
1 <= N <= 100000
Cost of each vegetable(brinjal/carrot/tomato) per kg does not exceed 10^4

Example
Input:
1
3
1 50 50
50 50 50
1 50 50
Output:
52
Explanation:
There are two ways, each one gives 52 as minimum cost. One way is buy brinjals from first shop, carrots from second shop and brinjals from third shop or he can buy brinjals from first shop, tomatoes from second shop and brinjals from third shop.
Both ways , cost comes up to 1 + 50 + 1 = 52
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int dp[100000+1][3];

int buy(int a[][3], int length, int n, int m) {
	if (n>=length) return 0;
	
	if (dp[n][m]!=-1) return dp[n][m];

	int min_ = INT_MAX;
	for (int i=0; i<3; i++) {
		if (i!=m)
			min_= min(min_, a[n][i] + buy(a, length, n+1, i));
	}

	dp[n][m] = min_;
	return dp[n][m];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		int a[n][3];
		for (int i=0; i<n; i++)
			for (int j=0; j<3; j++)
				cin>>a[i][j];

	memset(dp, -1, sizeof(dp));
	int min_ = INT_MAX;
	for (int i=0; i<3; i++) {
		min_= min(min_, buy(a, n, 0, i));
	}
		cout << min_ << "\n";
	}
}