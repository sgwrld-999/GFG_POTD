//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 
/*
Problem name : Maximum of all subarrays of size k
Problem link : https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
Problem Link : https://leetcode.com/problems/sliding-window-maximum/
Approach : Sliding Window



*/
// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        int ctr = 0 , j = 0 ;
        long long int sum = 0  , max = 0;
        long long resultarrr[N];
        for(int i = 0 ; i < N ; i++){
            sum = sum + Arr[i];
            ctr++;
            if(ctr==K){
                if(sum > max){
                    max = sum;
                }
                ctr--; 
                sum = sum - Arr[j];
                j++;
            }
        }
        return max;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends