//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
/*
 * Problem name : Game of XOR
 * Problem link : https://www.geeksforgeeks.org/problems/game-of-xor1541/1 
 * Difficulty : Medium
 * Explanation :
 *    - Approach 1 : Brute Force : Generate all the subarrays and find the XOR of each subarray and calculate the result and return the result.
 *       - Time Complexity : O(N^3)
 *       - Space Complexity : O(1)
 *    - Approach 2 : Effective approach can be the XOR nature. We know XORing an element twice results 0 i.e i^i=0
 *       Example : 
 *              For input array:
    1, 2, 3, 4
    Sub arrays are:
    {1}
    {2}
    {3}
    {4}
    {1, 2}
    {2, 3}
    {3, 4}
    {1, 2, 3}
    {2, 3, 4}
    {1, 2, 3, 4}

    This is all possible sub arrays
    A prompt observation leads to the fact that every element 
    actually occurred even number of times while XORing all values
    1^2^3^4^(1^2)^(2^3)^(3^4)^(1^2^3)^(2^3^4)^(1^2^3^4)

    1 has appeared 4 times
    2 has appeared 6 times
    3 has appeared 6 times
    4 has appeared 4 times
    So the final result is actually 0

    Now take any even length array
    You will find all elements appearing even no of times 
    if you expand the XORing sequence like the previous one.
    So,
    For even length array the output will be always 0, 
    no matter what the elements are.

    Now what about odd lengths.
    Let's quickly revise an example
    The array be:
    1, 2, 3, 4, 5
    So,
    Subarrays are:
    {1}
    {2}
    {3}
    {4}
    {1, 2}
    {2, 3}
    {3, 4}
    {4, 5}
    {1, 2, 3}
    {2, 3, 4}
    {3, 4, 5}
    {1, 2, 3, 4}
    {2, 3, 4, 5}
    {1, 2, 3, 4, 5}
    So the expanded result sequence would be:

    1^2^3^4^5^(1^2)^(2^3)^(3^4)^(4^5)^(1^2^3) ^ 
    (2^3^4) ^ (3^4^5) ^ (1^2^3^4) ^(2^3^4^5) ^ (1^2^3 ^4^5)
    
    So, 1 appears 5 times //resulting 1
    2 appears 8 times //resulting 0
    3 appears 9 times //resulting 3
    4 appears 8 times //resulting 0
    5 appears 5 times //resulting 5
    Output will be : 1^3^5 = 7
    Thus for an odd length array it's found that:

        Result will be XORing of all even indexed elements (0-based indexing)

        You can check the argue by doing few more examples your own.

        So the entire problem actually reduced to a simple concept-

        Even length array: output 0
        Odd length array: XORing all even-indexed elements
        No need to compute all the sub arrays at all!!
 *             Optimized : 
 *      - Time Complexity : O(N)
 *      - Space Complexity : O(1)
 * 
 */
class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int N = Integer.parseInt(read.readLine());
            
            String S[] = read.readLine().split(" ");
            int[] A = new int[N];
            
            for(int i=0 ; i<N ; i++)
                A[i] = Integer.parseInt(S[i]);

            Solution ob = new Solution();
            System.out.println(ob.gameOfXor(N,A));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
    static int solveInNCube(int N , int[] A){
        int res = 0;
        for(int i = 0 ; i < N; i++){
            for(int j = i  ; j < N ; j++){
                for(int k = i ; k <= j ; k++ ){
                    res = res ^ A[k];
                }
            }
        }
        
        return res;
    }
    static int sovleInN(int N , int[] A){
        int res = 0;
        for(int i = 0 ; i < N; i++){
            int freq = (i+1) * (N-i);
            if(freq % 2 ==  1){
                res = res ^ A[i];
            }
        }
        
        return res;
    }
    static int gameOfXor(int N , int[] A) {
        // code here
        return sovleInN(N,A);
    }
};
/*
CPP Solution
class Solution {
  public:
    int gameOfXor(int N , int a[]) {
        // code here
        if(N%2==0) //for even length array
	    	return 0;
		
    	int sum=a[0];
    	// for odd length array
    	for(int it=2;it<N;it=it+2) 
    		sum=sum^a[it];
    	return sum;
    }
};
 */