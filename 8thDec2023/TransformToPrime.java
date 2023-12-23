

/*
 * Problem name : Transform to Prime
 * Problem link : https://practice.geeksforgeeks.org/problems/transform-to-prime/0/#
 * Explanation : 
 *  Approach 1 : 
 *     1. Find the sum of all the elements in the array. 
 *     2. Check if the sum is prime or not.
 *     3. Now, keep on increasing the sum until it becomes a prime number.
 * 
 */
class Solution {
    public boolean isPrime(int num) {
        if (num == 0 || num == 1) {
            return false;
        }
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    public int minNumber(int arr[], int N) {
        int sum = 0;
        for (int x : arr) {
            sum += x;
        }
        int preSum = sum;
        while (!isPrime(sum)) {
            sum++;
        }

        return sum - preSum ;
    }
}
public class TransformToPrime {
    public static void main(String[] args) {
        int arr[] = { 1, 2, 3 };
        int N = arr.length;
        Solution obj = new Solution();
        System.out.println(obj.minNumber(arr, N));
    }
}
