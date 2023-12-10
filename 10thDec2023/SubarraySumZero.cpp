//{ Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;

/*
Problem name : Subarray with 0 sum
Problem Statement: Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.
Problem Link: https://practice.geeksforgeeks.org/problems/subarray-with-0-sum/0
Problem link on Leetcode: https://leetcode.com/problems/subarray-sum-equals-k/
*/

// } Driver Code Ends
class Solution {
public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool bruteForceApproach(int arr[], int n) {
        // generating all subarrays
        for (int i = 0 ; i < n ; i++) {
            if (arr[i] == 0) return true;
        }

        for (int i = 0; i < n; i++) {
            int curSum = arr[i];
            for (int j = i + 1; j < n; j++) { 
                curSum += arr[j];
                if (curSum == 0) return true;
            }
        }
        return false;
    }
    
    bool optmiseApproach(int arr[],int n){
        int sum[n] ;
        sum[0] = arr[0];
        for(int i = 1 ; i < n ; i++)sum[i] = arr[i] + sum[i-1];
        
        for(auto it : sum){
            if(it == 0) return true;
        }
        
        map<int,bool>mp;
        
        for(auto it : sum){
            if(mp.find(it) != mp.end())return true;
            else mp[it] = true;
        }
        
        return false;
    }
    bool subArrayExists(int arr[], int n) {
        // Your code here
        return optmiseApproach(arr, n);
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
// } Driver Code Ends