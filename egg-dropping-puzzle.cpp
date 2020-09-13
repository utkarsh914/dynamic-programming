/*
https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0

Suppose you have N eggs and you want to determine from which floor in a K-floor building you can drop an egg such that it doesn't break. You have to determine the minimum number of attempts you need in order find the critical floor in the worst case while using the best strategy.There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
For more description on this problem see wiki page

Input:
The first line of input is  T denoting the number of testcases.Then each of the T lines contains two positive integer N and K where 'N' is the number of eggs and 'K' is number of floor in building.

Output:
For each test case, print a single line containing one integer the minimum number of attempt you need in order find the critical floor.

Constraints:
1<=T<=30
1<=N<=10
1<=K<=50

Example:
Input:
2
2 10
3 5

Output:
4
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

/*
k ==> Number of floors
  n ==> Number of Eggs
  eggDrop(n, k) ==> Minimum number of trials needed to find the critical
					floor in worst case.
  eggDrop(n, k) = 1 + min{max(eggDrop(n - 1, x - 1), eggDrop(n, k - x)): 
				 x in {1, 2, ..., k}}
*/

int drop(int e, int f) {
	int dp[e+1][f+1];
	// fill out base conditions
	// if no eggs, then 0
	for (int i=0; i<=f; i++)
		dp[0][i]=0;
	// if no floors, then 0
	for (int i=0; i<=e; i++)
		dp[i][0]=0;
	// if only 1 floors and eggs>0, then 1
	for (int i=1; i<=e; i++)
		dp[i][1]=1;
	// if only one egg, then eq to no. of floor
	for (int i=1; i<=f; i++)
		dp[1][i]=i;
	
	for (int i=2; i<=e; i++) {
		// int ans=0;
		for (int j=2; j<=f; j++) {
			// now simulate dropping from all floors
			// with the given amount of eggs and floors
			dp[i][j] = INT_MAX;
			for (int k=1; k<=j; k++) {
				int notbroke = dp[i][j-k];
				int broke = dp[i-1][k-1];
				int temp = 1 + max(notbroke, broke);
				dp[i][j] = min(dp[i][j], temp);
			}
		}
	}
	return dp[e][f];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; cin>>t;
	while (t--) {
		int e, f; cin>>e>>f;
		cout << drop(e, f) << el;
	}
}