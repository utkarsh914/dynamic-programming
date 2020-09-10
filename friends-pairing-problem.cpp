/*
https://practice.geeksforgeeks.org/problems/friends-pairing-problem/0/


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
Suppose you have n-1 people and nth person comes then that nth person have follwing choice
1. To be single
2. To get paired with of ( n - 1 ) people.

When the nth person is single then the no of ways to do so is simply dp [ n - 1 ] .
but if the nth person pairs then he have to choose from n -1 friends and hence with have to see combination of ( n - 2 ) people now
hence Dp [ n ] = Dp [ n - 1 ] + ( n - 1 ) * Dp [ n - 2 ] ;

n-2 means exclude the person himslef, and the person he will pair with, and then it is simply dp[n-1];
so he can pair with (n-1) diff person, so (n-1) * dp[n-2];
*/
int pair_frands(int N) {

	ll M = 1000000007;
	ll dp[N+1];

	dp[0]=0; dp[1]=1; dp[2]=2;

	for (int i=3; i<=N; i++) {
		dp[i]=dp[i-1] + dp[i-2]*(i-1);
		dp[i]=dp[i]%M;
	}

	return dp[N];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		cout<<pair_frands(n)<<el;
	}
}