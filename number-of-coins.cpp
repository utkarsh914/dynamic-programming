/*
https://practice.geeksforgeeks.org/problems/number-of-coins/0/

Given a value V. You have to make change for V cents, given that you have infinite supply of each of C{ C1, C2, .. , Cm} valued coins. Find the minimum number of coins to make the change.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is V and N, V is the value of cents and N is the number of coins. The second line of each test case contains N input C[i], value of available coins.

Output:
Print the minimum number of coins to make the change, if not possible print "-1".

Constraints:
1 ≤ T ≤ 100
1 ≤ V ≤ 106
1 ≤ N ≤ 106
1 ≤ C[i] ≤ 106

Example:
Input:
1
7 2
2 1

Output:
4

Explanation :
Testcase 1: We can use coin with value 2 three times, and coin with value 1 one times to change a total of 7.
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

ll dp[1000005];

ll change(ll c[], ll n, ll sum) {
	 if (sum==0) return 0;
	 if (sum<0) return INT_MAX;
	
	 if (dp[sum]!=-1) return dp[sum];
	
	 ll ans=INT_MAX;
	 for (ll i=0; i<n; i++) {
		 ll temp = change(c,n,sum-c[i]);
		 if (temp!=INT_MAX && temp+1<ans)
			 ans = temp+1;
	 }
	 return dp[sum]=ans;
}

/*
============== BOTTOM UP ===============

ll change(ll c[], ll n, ll sum) {
	ll dp[n+1][sum+1];
	// for 0 coins, zero ways to make change
	for (ll i=0; i<=sum; i++)
		dp[0][i]=INT_MAX;
	// for 0 sum
	for (ll i=0; i<=n; i++)
		dp[i][0]=0;
		
	for (ll i=1; i<=n; i++) {
		for (ll j=1; j<=sum; j++) {
			if (c[i-1] > j)
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = min(dp[i-1][j], 1+(dp[i][j-c[i-1]]));
		}
	}
	return dp[n][sum];
} */

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll t; cin>>t;
	while (t--) {
		ll v,n; cin>>v>>n;
		ll c[n];
		for (ll i=0; i<n; i++) cin>>c[i];
		memset(dp, -1, sizeof(dp));
		ll ans = change(c,n,v);
		cout<<((ans==INT_MAX) ? -1 : ans)<<el;
	}
}