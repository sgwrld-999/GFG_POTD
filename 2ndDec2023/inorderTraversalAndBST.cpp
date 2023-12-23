//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
/*
Problem Name : Inorder Traversal And BST
Problem Link : https://practice.geeksforgeeks.org/problems/inorder-traversal-and-bst/1#
Explanation : 
Property of inorder traversal of BST is that it is always sorted in ascending order.
CHecking if the given array is sorted or not.
Sorted -> 1
Not Sorted -> 0
*/
class Solution{
    public:
    int isRepresentingBST(int arr[], int N)
    {
        // code here
        return is_sorted(arr,arr+N);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        cout<<ob.isRepresentingBST(arr,N)<<endl;
    }
    return 0;
}
// } Driver Code Ends