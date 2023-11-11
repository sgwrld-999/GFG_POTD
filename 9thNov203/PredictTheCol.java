//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

public class PredictTheCol
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        
        while(t-- > 0)
        {
            int N = Integer.parseInt(read.readLine());
            int arr[][] = new int[N][N];
            
            for(int i = 0; i < N; i++)
            {
                int k = 0;
                String str[] = read.readLine().trim().split("\\s+");
                for(int j = 0; j < N; j++){
                  arr[i][j] = Integer.parseInt(str[k]);
                  k++;
                }
            }
            
            System.out.println(new Solution().columnWithMaxZeros(arr,N));
        }
    }
}
/*
Calculating the  number of zeros in each colum and 
returing the number count of the column with maximum zeros.
We can do it the naive way by traversing the matrix and as the 
constraints are small we can do it in O(n^2) time.

*/
class Solution
{
    int columnWithMaxZeros(int arr[][], int N)
    {
        // code here 
        int maxCount=0;
        int ans=-1;
        for(int i=0; i<N; ++i){
            int count=0;
            for(int j=0; j<N; ++j){
                if(arr[j][i]==0) count++;
            }

            if(maxCount<count){
                ans=i;
                maxCount=count;
            }
        }
        return ans;
    }
}