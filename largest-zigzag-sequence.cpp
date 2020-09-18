/*
https://practice.geeksforgeeks.org/problems/largest-zigzag-sequence/0/

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

int M[101][101];
int N;

int largest() {

	int dp[N+1][N+1];
	int ans=INT_MIN;

	for (int i=0; i<N; i++) {
		dp[N-1][i]=M[N-1][i];
	}

	for (int i=N-2; i>=0; i--) {
		for (int j=N-1; j>=0; j--) {
			int max_=INT_MIN;
			for (int k=N-1; k>=0; k--) {
				if (k==j)
					continue;
				max_= max(max_, dp[i+1][k]);
			}
			dp[i][j] = M[i][j] + max_;
		}
	}

	// find max in first row
	for (int i=0; i<N; i++) {
		ans = max(ans, dp[0][i]);
	}

	return ans;

}

int main() {
	furr;
	int t; cin>>t;
	while (t--) {
		cin>>N;
		for (int i=0; i<N; i++)
			for (int j=0; j<N; j++)
				cin>>M[i][j];

		cout << largest() <<el;
	}
}