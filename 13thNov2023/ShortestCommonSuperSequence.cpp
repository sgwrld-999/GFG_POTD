//{ Driver Code Starts
//Initial template for C++


/*
Problem naem: Shortest Common Supersequence
Problem link: https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1
Explanation : 
We've to find the shortest common supersequence of two strings.
A supersequence is a string that contains both the strings as subsequences.
So, we can find the length of the longest common subsequence of the two strings.
Then, the length of the shortest common supersequence will be the sum of the lengths of the two strings minus the length of the longest common subsequence.


*/
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        vector<vector<int>> dp(m + 1,vector<int>(n + 1,- 1));
        
        int ans = lcs(X,Y,m,n,dp);
        return m + n - ans;
    }
    int lcs(string &a,string &b,int m,int n,vector<vector<int>> &dp){
        if(m == 0 or n == 0){
            return 0;
        }
        
        if(dp[m][n]!= -1){
            return dp[m][n];
        }
        
        //include
        if(a[m - 1]==b[n - 1]){
            return dp[m][n] = 1 + lcs(a,b,m - 1,n - 1,dp);
        }
        
        //exclude
        return dp[m][n] = max(lcs(a,b,m - 1,n,dp),lcs(a,b,m,n - 1,dp));
    }
};


//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends