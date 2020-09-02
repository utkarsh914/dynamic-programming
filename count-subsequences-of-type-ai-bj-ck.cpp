/*
https://practice.geeksforgeeks.org/problems/count-subsequences-of-type-ai-bj-ck/0

Given a string s, the task is to count number of subsequences of the form aibjck, where i >= 1, j >=1 and k >= 1.

Note: Two subsequences are considered different if the set of array indexes picked for the 2 subsequences are different.


Examples:

Input  : abbc
Output : 3
Subsequences are abc, abc and abbc

Input  : abcabc
Output : 7
Subsequences are abc, abc, abbc, aabc
abcc, abc and abc


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains a string s.

Output:
For each test case in a new line print the required output.

Constraints:
1<=T<=100
1<=Length of string <=100

Example:
Input:
2
abbc
abcabc
Output:
3
7
*/

#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endll "\n";
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t;cin>>t;
	while(t--){
		string s;cin>>s;
		int a=0,b=0,c=0;//count of subsequenes ending with a,b,c
		for(int i=0;i<s.length();i++){
			if(s[i]=='a'){
				a=2*a+1;//new count=previous count+
				// we can append 'a' to all previous strings ending with 'a'+
				//we can start new subsequence starting with 'a'
			}
			else if(s[i]=='b'){
				b=2*b+a;//2*b comes same as 2*a came in previous case
				//+ we can append 'b' to all strings ending with 'a'
			}
			else if(s[i]=='c'){
				c=2*c+b;//same as in previous case
			}
		}
		cout<<c<<endll;//count of strings ending with 'c'.
	}
	return 0;
}

/*

*/