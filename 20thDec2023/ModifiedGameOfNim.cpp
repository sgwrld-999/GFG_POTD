//{ Driver Code Starts
// Initial Template for C++

/*
Problem name : Modified Game of Nim
Problem link : https://practice.geeksforgeeks.org/problems/modified-game-of-nim-1587115621/1
Exaplanation :
            The game hinges on manipulating the XOR result of the array elements. 
            XOR is a bitwise operation that returns 1 for differing bits and 0 for matching bits. 
            The key insight is that if the XOR of all elements is initially zero,
            Player 1 can ensure victory by strategically choosing elements. Conversely, 
            if the XOR is non-zero, Player 2 can force a win.
            The proof is as follows:
            If the XOR is zero, Player 1 can choose any element and set it to any value.
            This will not change the XOR of the array, and Player 2 will be left with a non-zero XOR.
            Player 2 can then choose any element and set it to any value, leaving Player 1 with a non-zero XOR.
            This process continues until one player is left with an array of all zeroes,
            at which point the other player wins.
            If the XOR is non-zero, Player 2 can choose any element and set it to any value.
            This will change the XOR of the array, and Player 1 will be left with a zero XOR.
            Player 1 can then choose any element and set it to any value, leaving Player 2 with a zero XOR.
            This process continues until one player is left with an array of all zeroes,
            at which point the other player wins.
            The code is as follows:
            Time Complexity : O(n)
            Space Complexity : O(1)
*/
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findWinner(int n, int A[]){
        // code here
        int xorRes = 0;
        for(int i = 0 ; i <  n ; i++){
            xorRes ^= A[i];
        }
        
        return (xorRes == 0) ? 1 : ((n%2)+ 1) ;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i = 0;i < n;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.findWinner(n, A)<<"\n";
    }
    return 0;
}
// } Driver Code Ends