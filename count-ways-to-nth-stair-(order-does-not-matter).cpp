/*
https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter/0/

There are N stairs, and a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does not matter).
Note: Order does not matter means for n=4 {1 2 1},{2 1 1},{1 1 2} are considered same.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, an integer N will be given.

Output:
For each testcase, in a new line, print number of possible ways to reach Nth stair.

Constraints:
1 <= T <= 1000
1 <= N <= 106

Example:
Input:
2
4
5
Output:
3
3
*/

#define el "\n"
#define ll long long int
#define pb push_back
#define u_m unordered_map
#define u_s unordered_set
#define p_q priority_queue
using namespace std;

int dp[1000002];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; cin>>t;
	// no. of ways to reach 0 and 1 is one only
	dp[0] = dp[1] = 1;
	// no. of ways to reach n is 1 more than that of n-2
	// because taking a step of 2 from n-2,
	// either total no. of 1s will inc, or that of 2s will inc
	for (int i=2; i<1000002; i++)
	    dp[i] = dp[i-2] + 1;
	while (t--) {
		int n; cin>>n;
		cout << dp[n] << el;
	}
}