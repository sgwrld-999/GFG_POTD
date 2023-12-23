//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
/*
Problem name : How many X's
Problem Link: https://practice.geeksforgeeks.org/problems/how-many-xs5046/1/?track=md-string&batchId=144#
*/
// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int n ,int X){
        int ans = 0 ;
        while(n) {
            if(n%10 == X)ans++;
            n = n / 10 ;
        }
        return ans;
    }
    int countX(int L, int R, int X) {
        // code here
        int ans = 0 ; 
        for(int i = L+1 ; i < R ; i++){
            ans += solve(i,X);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R, X;
        cin >> L >> R >> X;
        Solution ob;
        int ans = ob.countX(L, R, X);
        cout << ans << "\n";
    }
}

// } Driver Code Ends