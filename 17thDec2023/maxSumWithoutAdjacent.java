//{ Driver Code Starts
//Initial Template for Java


/*
 * Problem name : Max sum without adjacent
 * Problem link : https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1#
 * Explanation : House robber problem
 * 
 */
import java.util.*;
import java.io.*;

 class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String[] inputLine;
            int n = Integer.parseInt(br.readLine().trim());
            int[] arr = new int[n];
            inputLine = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }

            int ans = new Solution().findMaxSum(arr, n);
            System.out.println(ans);
        }
    }
}
// } Driver Code Ends




//User function Template for Java

class Solution {
    int recursion(int idx,int arr[],int[] dp){
        if(idx < 0) return 0;
        if(idx == 0) return arr[idx];
        if(dp[idx] != -1) return dp[idx];
        
        int notPick = recursion(idx-1,arr,dp);
        int pick = arr[idx] + recursion(idx-2,arr,dp);
        
        return dp[idx] = Math.max(pick,notPick);
    }
    int findMaxSum(int arr[], int n) {
        // code here
        int[] dp = new int[n+1];
        Arrays.fill(dp,-1);
        return recursion(n-1,arr,dp);
    }
}