/*
https://practice.geeksforgeeks.org/problems/champagne-overflow/0/

There is a stack of water glasses in a form of pascal triangle and a person wants to pour the water at the topmost glass, but the capacity of each glass is 1 unit. Overflow takes place in such a way that after 1 unit, 1/2 of remaining unit gets into bottom left glass and other half in bottom right glass.Now the pours K units of water in the topmost glass and wants to know how much water is there in the jth glass of the ith row.

Note: Assume that there are enough glasses in the triangle till no glass overflows. 

Input:
First line of the input contains an integer T denoting the number of test cases and each test case consists of three lines. First line contain an integer K, second line contains an integer i and third line contains an integer j.

Output:
Corresponding to each test case output the remaining amount of water in jth cup of the ith row correct to 6 decimal places.

Constraints:
1 <= T<=20
1 <= K <= 1000
1 <= i <= K
1 <= j<= K

Example:
Input:
1
3 
2
1

Output:
1

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

// r,c should be indices of the required glass
double pour(int amount, int r, int c) {
	double m[1002][1002];
	memset(m, 0.0, sizeof(m));
	m[0][0] = (double) amount;
	// start from topmost glass, calculate extra amount at that glass
	// divide extra amount into 2 parts and add them to the 2 lower glasses
	for (int i=0; i<=r; i++) {
		for (int j=0; j<=i; j++) {
			double extra = (m[i][j] - 1.0)/2.0;
			if (extra > 0) {
				m[i+1][j] += extra;
				m[i+1][j+1] += extra;
			}
		}
	}
	return (m[r][c]>1.0) ? 1.0 : m[r][c];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; cin>>t;
	while (t--) {
		int amount,i,j; cin>>amount>>i>>j;
		double ans = pour(amount, i-1, j-1);
		cout << fixed << setprecision(6) << ans << el;
	}
}