/*
https://practice.geeksforgeeks.org/problems/cutted-segments/0/

Given an integer N denoting the Length of a line segment. you need to cut the line segment in such a way that the cut length of a line segment each time is integer either x , y or z. and after performing all cutting operation the total number of cutted segments must be maximum. 


Input
First line of input contains of an integer 'T' denoting number of test cases. First line of each testcase contains N . Second line of each testcase contains 3 space separated integers x , y and z.

Output
For each test case print in a new line an integer corresponding to the answer .


Constraints
1<=t<=70
1<=N,x,y,z<=4000
 

Example

Input

2
4
2 1 1
5
5 3 2


Output
4
2

In first test case, total length is 4, and cut lengths are 2, 1 and 1.  We can make maximum 4 segments each of length 1. In secon test case, we can make two segments of lengths 3 and 2.
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
// normal recursion solution
int cut(int len, int cuts[]) {
	if (len < 0) return INT_MIN;
	if (len == 0) return 0;
	
	int cut_x = 1 + cut(len-cuts[0], cuts);
	int cut_y = 1 + cut(len-cuts[1], cuts);
	int cut_z = 1 + cut(len-cuts[2], cuts);
	
	return max(cut_x, max(cut_y, cut_z));
}
*/

int cut(int len, int cuts[], vector<int> &dp) {
    
	if (len < 0) return INT_MIN;
	if (len == 0) return 0;

	if (dp[len] != -1) return dp[len];
	
	int cut_x = cut(len-cuts[0], cuts, dp);
	int cut_y = cut(len-cuts[1], cuts, dp);
	int cut_z = cut(len-cuts[2], cuts, dp);
	dp[len] = 1 + max(cut_x, max(cut_y, cut_z));

	return dp[len];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; cin>>t;
	while (t--) {
		int l; cin>>l;
		int a[3];
		for (int i=0; i<3; i++) cin>>a[i];
		int dp[l+1] = {INT_MIN};
		cout << cut(l, a, dp) <<el;
	}
}