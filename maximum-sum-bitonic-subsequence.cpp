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

int bitonic(int a[], int n) {
	
	int inc[n+1]; // strictly inc
	int dec[n+1]; // strictly dec
	// initial values
	for (int i=0; i<n; i++)
		inc[i]=dec[i]=a[i];

	// calculate greatest sum inc subsequence from front to last
	for (int i=1; i<n; i++) {
		for (int j=0; j<i; j++) {
			if (a[i]>a[j] && a[i]+inc[j]>inc[i]) {
				inc[i] = a[i]+inc[j];
			}
		}
	}
	// calculate greatest sum inc subsequence from last to front
	// i.e. greatest sum dec subseq from that position onwards
	for (int i=n-2; i>=0; i--) {
		for (int j=n-1; j>i; j--) {
			if (a[i]>a[j] && a[i]+dec[j]>dec[i]) {
				dec[i] = a[i]+dec[j];
			}
		}
	}

	int ans=INT_MIN;
	for (int i=0; i<n; i++) {
		ans = max(ans, inc[i]+dec[i]-a[i]);
	}

	return ans;
}

int main() {
	furr;
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		int a[n];
		for (int i=0; i<n; i++) cin>>a[i];
		
		cout<<bitonic(a,n)<<el;
	}
}