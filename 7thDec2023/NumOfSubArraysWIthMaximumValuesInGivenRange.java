//{ Driver Code Starts
//Initial Template for Java

/*package whatever //do not write package name here */

import java.io.*;
/*
 * Problem name : Number of subarrays with maximum values in given range
 * Problem link : https://practice.geeksforgeeks.org/problems/number-of-subarrays-with-maximum-values-in-given-range/0/?track=amazon-arrays&batchId=192#
 * Explanation : We've given a range L and R and we've to find the number of subarrays whose sum is in the range L and R
 * We can solve this problem in O(n^2) time complexity by finding all the subarrays and then checking if their sum is in the range L and R
 * But we can solve this problem in O(n) time complexity by using the concept of sliding window and prefix sum
 * We'll use two pointer approach to solve this problem
 * We'll take two pointers i and j and we'll move j until the sum of the subarray is less than or equal to R
 * Then we'll check if the sum of the subarray is in the range L and R
 * If it is in the range then we'll add the number of subarrays to the answer
 * Then we'll move the pointer i until the sum of the subarray is less than L
 * Then we'll move the pointer j until the sum of the subarray is less than or equal to R
 * We'll repeat this process until the pointer j reaches the end of the array
 * 
 * Approach 1 : O(n^2) time complexity
 * Approach 2 : O(n) time complexity
 *  2 methods in O(n) -> Sliding window and Prefix sum
 *                    -> Removing the elements from the left range
 */

class GFG {
	public static void main (String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int testcases = Integer.parseInt(br.readLine());
		
		while(testcases-- > 0){
		    
		    String line1 = br.readLine();
		    String []element = line1.trim().split(" ");
		    int n = Integer.parseInt(element[0]);
		    int l = Integer.parseInt(element[1]);
		    int r = Integer.parseInt(element[2]);
		    
		    int arr[] = new int[n];
		    
		    
		    String line = br.readLine();
		    String[] elements = line.trim().split(" ");
		    
		    for(int index = 0;index < n; index++){
		        arr[index] = Integer.parseInt(elements[index]);
		    }
		    
		    Solution obj = new Solution();
		    
		    System.out.println(obj.countSubarrays(arr, n, l, r));
		        
		}
		
	}
}


// } Driver Code Ends


//User function Template for Java

class Solution {
    
    static int sumInNsq(int arr[], int n, int L, int R) {
        int sum = 0;
        int ctr = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                sum += arr[i] + arr[j];
                if (sum > L && sum < R) ctr++;
                else if (sum >= R) break;  
            }
            sum = 0;
        }
        return ctr;
    }
    static long sumInN(int arr[], int n, int L, int R) {
        long size = 0;
        long ctr = 0 ;
        for(int i = 0 ;  i < n ; i++){
            if(arr[i] <= R){
                while(i < n && arr[i] <= R ){
                    size++;
                    i++;
                }
                
                ctr += (size * (size + 1)) / 2 ;
                if( i < n  && arr[i] > R ) size = 0;
            }
        }
        size = 0 ;
        for(int i = 0 ;  i < n ; i++){
            if(arr[i] < L){
                while(i < n && arr[i] < L ){
                    size++;
                    i++;
                }
                
                ctr -= (size * (size + 1)) / 2 ;
                if(i < n  && arr[i] >= L ) size = 0;
            }
        }
        return ctr;
    }
    //Sliding window approach
    static long sumInNSlidingWindow(int arr[], int n, int L, int R) {
        // Complete the function
        long ans = 0;
        int i = 0;
        int j = 0;
        int sum = 0;
        while (j < n) {
            sum += arr[j];
            if (sum >= L && sum <= R) {
                ans += j - i + 1;
            }
            if (sum > R) {
                while (sum > R) {
                    sum -= arr[i];
                    i++;
                }
                if (sum >= L && sum <= R) {
                    ans += j - i + 1;
                }
            }
            j++;
        }
        return ans;
    } 
    static long countSubarrays(int arr[], int n, int L, int R) {
        // Complete the function
        return Solution.sumInN(arr, n, L, R);
    } 
}


