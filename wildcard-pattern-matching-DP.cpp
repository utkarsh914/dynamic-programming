/*
https://practice.geeksforgeeks.org/problems/wildcard-pattern-matching/1
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int wildCard(string pattern,string str);
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
		   string pat,text;
		   cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
		   cin>>text;
		   cout<<wildCard(pat,text)<<endl;
   }
}
// } Driver Code Ends


bool match(string pat, string str, int p, int s) {
	if (p==0 && s==0) return true;
	if (pat[p-1]=='*' && s==0)
		return match(pat, str, p-1, s);
		
	if (p==0 || s==0) return false;
	
	if (pat[p-1]==str[s-1] || pat[p-1]=='?')
		return match(pat, str, p-1, s-1);
	
	if (pat[p-1]=='*') {
		return match(pat, str, p, s-1) || match(pat, str, p-1, s);
	}
}

/*You are required to complete this method*/
int wildCard(string pattern,string str)
{
	bool ans = match(pattern, str, pattern.length(), str.length());
	return (ans==true) ? 1 : 0;
}