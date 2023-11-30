//{ Driver Code Starts
//Initial Template for Java

import java.io.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            int n = Integer.parseInt(read.readLine());

            Solution ob = new Solution();
            System.out.println(ob.minStep(n));
        }
    }
}
// } Driver Code Ends
/*
 Problem name : Shortest path from 1 to n
 Problem link : https://practice.geeksforgeeks.org/problems/shortest-path-from-1-to-n0156/1#
 Explanation:
 Given a number assuming it as a node and we've to find the shortest path from 1 to n.
 With the given condition that we can go to the next node only if it has 
 j = 1 + i or j = 3 * i.
 
 Solution: It;s given that j = 3 * i so we focus on this as multiplication  
    is faster than addition.
    And also there are 3 types of number with respect to 3 : 
    1. Number which is divisible by 3 : 3n
    2. Number which is not divisible by 3 but (3n + 1) : 3n + 1
    3. Number which is not divisible by 3 but (3n + 2) : 3n + 2

    So, if we have a number which is divisible by 3 then we can divide it by 3
    and if we have a number which is not divisible by 3 then we can subtract 1
    from it. So, we'll get a number which is divisible by 3 and we can divide it
    by 3. So, we'll get the shortest path.

For example : 9 :- 1 -> 3 -> 9 the shortest path is given with the 2 steps.
              4 :- 1 -> 3 -> 4 the shortest path is given with the 2 steps.
 */

class Solution{
    public int minStep(int n)
    {
        // code here
        int ans = 0 ; 
        while(n>1){
            if(n%3 == 0) {
                n=n/3;
            }else{
                n--;
            }
            ans++;
        }
        return ans;
    }
}
