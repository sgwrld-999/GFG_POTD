
import java.io.*;
/*
 * problem name : Count the strings
 * problem link : https://practice.geeksforgeeks.org/problems/count-the-strings/0/?track=md-string&batchId=144
 * Explanation : 
 * Intiution :
 * When faced with the task of counting the number of strings of length 'n' that can be formed using the characters 'a', 'b', and 'c', 
 * subject to the condition of at most one 'b' and two 'c', it is crucial to devise an efficient approach. In this article, we will explore the problem, 
 * understand its nuances, and present a solution that strikes a balance between simplicity and optimization.
 * 
 * Intiuition : 
 * 
 * To approach this problem, we need to break down the possible cases systematically. The constraints suggest that we have to consider scenarios with at
 * most one 'b' and two 'c'. By categorizing the possible combinations, we can devise a formulaic approach to compute the total number of valid strings.
 * Approach :
 * The provided java code gives us a solid foundation to build upon. The approach involves considering various cases and summing up the possibilities:
 

- Strings with all 'a' = NCN = 1
- Strings with at most 1 'b' = NC1 = N 
- Strings with at most 1 'c' = NC1 = N
- Strings with one 'b' and one 'c' = NC1*N-1C1 = N*(N-1)
- Strings with two 'c' = NC2/2 = N*N-1/2
- Strings with one 'b' and two 'c' = NC1*N-1C2 = N*N-1*N-2/2
 

By calculating the count for each case and aggregating them, we obtain the total count of valid strings.
 */
public class CountStrings {

    class GFG{
        public static void main(String args[]) throws IOException { 
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
    
            
            int t = Integer.parseInt(br.readLine().trim()); 

            while(t > 0){
                long n = Integer.parseInt(br.readLine().trim()); 
                Solution ob = new Solution();
                System.out.println(ob.countStr(n)); 
                t--;
            }
        } 
    } 
    
}
class Solution 
    { 
        static long countStr(long n)
        {
            return 1+n+n+n*(n-1)+n*(n-1)/2 + n*(n-1)*(n-2)/2;
        }
    } 