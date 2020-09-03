/*
https://practice.geeksforgeeks.org/problems/boolean-parenthesization/0

Given a boolean expression with following symbols.

Symbols
	'T' ---> true
	'F' ---> false

And following operators filled between symbols

Operators
	&   ---> boolean AND
	|   ---> boolean OR
	^   ---> boolean XOR

Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

For Example:
The expression is "T | T & F ^ T", it evaluates true
in 4 ways ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T)
and (T|((T&F)^T)).

Return No_of_ways Mod 1003.

Input:
First line contains the test cases T.  1<=T<=500
Each test case have two lines
First is length of string N.  1<=N<=100
Second line is string S (boolean expression).
Output:
No of ways Mod 1003.
 

Example:
Input:
2
7
T|T&F^T
5
T^F|F

Output:
4
2

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

int dp[205][205][2];

int solve(string s, int start, int end, int torf) {
	
	if (start > end)
		return 0;
	
	if (start == end) {
		if (torf==1)
			return (s[start] == 'T');
		else
			return (s[start] == 'F');
	}
	
	// if pre computed
	if (dp[start][end][torf]!=-1)
		return dp[start][end][torf];
	
	// recur for substring on left and right of operator
	// and calculate left true/false, and right true/false
	int ans = 0;
	int lt, lf, rt, rf;
	for (int opr=start+1; opr < end; opr+=2) {
		// for left true count
		if (dp[start][opr-1][1] != -1)
			lt = dp[start][opr-1][1];
		else {
			lt = solve(s, start, opr-1, 1);
			dp[start][opr-1][1] = lt;
		}
		// for left false count
		if (dp[start][opr-1][0] != -1)
			lf = dp[start][opr-1][0];
		else {
			lf = solve(s, start, opr-1, 0);
			dp[start][opr-1][0] = lf;
		}
		// for right true count
		if (dp[opr+1][end][1] != -1)
			rt = dp[opr+1][end][1];
		else {
			rt = solve(s, opr+1, end, 1);
			dp[opr+1][end][1] = rt;
		}
		// for right false count
		if (dp[opr+1][end][0] != -1)
			rf = dp[opr+1][end][0];
		else {
			rf = solve(s, opr+1, end, 0);
			dp[opr+1][end][0] = rf;
		}

		int tot = (lt*rt)+(lt*rf)+(lf*rt)+(lf*rf);
		
		if (s[opr]=='&') {
			if (torf == 1) ans += (lt*rt) % 1003;
			else ans += (tot-lt*rt) % 1003;
		}
		else if (s[opr]=='|') {
			if (torf == 1) ans += (tot-lf*rf) % 1003;
			else ans += (lf*rf) % 1003;
		}
		else if (s[opr]=='^') {
			if (torf == 1) ans += (lt*rf)+(lf*rt) % 1003;
			else ans += ((lt*rt)+(lf*rf)) % 1003;
		}
		ans = ans  % 1003;
	}
	
	dp[start][end][torf] = ans;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; cin>>t;
	while (t--) {
		int n; string s; cin>>n>>s;
		memset(dp, -1, sizeof(dp));
		cout << solve(s,0,n-1,1) <<el;
	}
}

/*
************************** ALTERNATE(Same approach) LESS OPTIMIZED *******************************

#include<bits/stdc++.h>
#include<iostream>
#define el "\n"
#define ll long long int
#define pb push_back
#define u_m unordered_map
#define u_s unordered_set
#define p_q priority_queue
using namespace std;

int dp[1005][1005][2];
// declare functions
pair<int,int> solveforall(string s, int start, int end);
pair<int,int> solve(string s, int start, int end, int opr);

pair<int,int> solve(string s, int start, int end, int opr) {
	
	// recur for substring on left and right of operator
	// and calculate left true/false, and right true/false
	pair<int,int> left = solveforall(s, start, opr-1);
	pair<int,int> right = solveforall(s, opr+1, end);
	
	int lt=left.first, lf=left.second;
	int rt=right.first, rf=right.second;
	int tot = (lt*rt)+(lt*rf)+(lf*rt)+(lf*rf);
	
	int t,f;
	if (s[opr]=='&') {
		t = lt*rt;
		f = tot-lt*rt;
	}
	else if (s[opr]=='|') {
		t = tot-lf*rf;
		f = lf*rf;
	}
	else if (s[opr]=='^') {
		t = (lt*rf)+(lf*rt);
		f = (lt*rt)+(lf*rf);
	}
	
	return make_pair(t,f);
}

// runs above func by taking all the operators one by one 
// and sums up the result
pair<int,int> solveforall(string s, int start, int end) {
	
	if (start == end) {
		if (s[start] == 'T') {
			dp[start][end][0] = 1;
			dp[start][end][1] = 0;
		}
		else if (s[start] == 'F') {
			dp[start][end][0] = 0;
			dp[start][end][1] = 1;
		}
		return make_pair(dp[start][end][0], dp[start][end][1]);
	}
	
	if (dp[start][end][0]!=-1 && dp[start][end][1]!=-1)
		return make_pair(dp[start][end][0], dp[start][end][1]);

	// recur for all operators one by one
	// and calculate true/false, and sum them
	int t=0, f=0;
	for (int i=start+1; i<end; i+=2) {
		pair<int,int> result = solve(s,start,end,i);
		t += result.first % 1003;
		f += result.second % 1003;
		t = t  % 1003;
		f = f % 1003;
	}

	dp[start][end][0] = t;
	dp[start][end][1] = f;

	return make_pair(dp[start][end][0], dp[start][end][1]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; cin>>t;
	while (t--) {
		int n; string s; cin>>n>>s;
		memset(dp, -1, sizeof(dp));
		pair<int,int> r = solveforall(s,0,n-1);
		cout << r.first <<el;
	}
}

*/



/*

************************** BOTTOM UP APPROACH *******************************

int MOD = 1003;
char OR = '|', AND = '&', XOR = '^';

int booleanParenthesization(string s, int n) {
	int T[n][n], F[n][n];

	for (int i = 0; i < n; i += 2) {
		T[i][i] = s[i] == 'T' ? 1: 0;
		F[i][i] = s[i] == 'T'? 0: 1;
	}

	for (int l = 2; l < n; l += 2) {
		for (int i = 0; i < n - l; i += 2) {
			int j = i + l;
			T[i][j] = 0;
			F[i][j] = 0;
			for (int k = i; k < j; k += 2) {
				char ch = s[k + 1];
				int totalIK = T[i][k] + F[i][k];
				int totalKJ = T[k + 2][j] + F[k + 2][j];
				if (ch == OR) {
					T[i][j] += (totalIK * totalKJ - F[i][k] * F[k + 2][j]) % MOD;
					F[i][j] += (F[i][k] * F[k + 2][j]) % MOD;
				} else if (ch == AND) {
					T[i][j] += (T[i][k] * T[k + 2][j]) % MOD;
					F[i][j] += (totalIK * totalKJ - T[i][k] * T[k + 2][j]) % MOD;
				} else if (ch == XOR) {
					T[i][j] += (T[i][k] * F[k + 2][j] + F[i][k] * T[k + 2][j]) % MOD;
					F[i][j] += (T[i][k] * T[k + 2][j] + F[i][k] * F[k + 2][j]) % MOD;
				} else {
					return 0;
				}
			}
		}
	}
	
	return T[0][n - 1] % MOD;
}
*/
