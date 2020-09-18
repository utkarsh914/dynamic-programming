/*
https://practice.geeksforgeeks.org/problems/largest-fibonacci-subsequence/0/

Given an array with positive number the task to find the largest subsequence from array that contain elements which are Fibonacci numbers.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N denoting the size of the array. Then in the next line are N space separated values of the array.

Output:
For each test case in a new line print the space separated elements of the  longest fibonacci subsequence.

Constraints:
1<=T<=100
1<=N<=100
1<=A[]<=1000

Example:
Input:
2
7
1 4 3 9 10 13 7
9
0 2 8 5 2 1 4 13 23

Output:
1 3 13
0 2 8 5 2 1 13

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

int solve(int a[], int n) {
	// calculate first 16 fibonacci numbers;
	int fib[17];
	fib[0]=0, fib[1]=1;
	for (int i=2; i<=16; i++)
		fib[i]=fib[i-1]+fib[i-2];
		
	u_s<int> s(begin(fib), end(fib));
	
	for (int i=0; i<n; i++) {
		if (s.count(a[i]))
			cout<<a[i]<<" ";
	}
	cout<<el;
}

int main() {
	furr;
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		int a[n];
		for (int i=0; i<n; i++) cin>>a[i];
		solve(a, n);
	}
}