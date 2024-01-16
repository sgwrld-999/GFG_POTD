//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
/*
Problem name : Sequence of sequence
Problem link : https://www.geeksforgeeks.org/problems/sequence-of-sequence1155/1
Explanation :
    - Question  
        Our task is to find the count of the number of sequqnce such that 
            seqi+1 >= 2*seqi 
            seqi > 0
            seqi <= m
    - Thought process 
    Given that we've to find the count of total number of sequence so the only thing is to do is BACKTRACKING as if 
    we've to pick and check if there is any sequence possible or not from that number and if not then we'll not pick
    that number and check for the next number.
    - Time Complexity : O(2^n)
    - Space Complexity : O(1)


*/
class Solution{
public:
    int backTrack(int currNum,int count,int n,int m){
        if(count == n)  return 1;
        if(currNum > m) return 0;
        
        int pick = backTrack(currNum*2,count+1,n,m);
        int not_Pick = backTrack(currNum+1,count,n,m);
        
        return pick+not_Pick ;
    }
    int numberSequence(int m, int n){
        // code here
        return backTrack(1,0,n,m);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends