//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;
/*
Problem Name : Smith Number
Problem Statement: Given a number N, the task is to check whether it is a Smith number or not. A Smith number is a composite number whose sum of digits is equal to the sum of digits in its prime factorization.
Poblem Link: https://practice.geeksforgeeks.org/problems/smith-number/0
Explanation : 
Approach:
1. Find the sum of digits of the given number.
2. Find the sum of digits of all the prime factors of the given number.
3. If the sum of digits of prime factors is equal to the sum of digits of the given number, then the number is a Smith number.


*/
// } Driver Code Ends

class Solution {
private:
    bool isPrime(int n) {
        if (n <= 1) return false;

        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) return false;
        }

        return true;
    }

    int sumOfDigits(int n) {
        int sum = 0;
        while (n > 0) {
            sum += (n % 10);
            n = n / 10;
        }
        return sum;
    }

    int findSum(int n) {
        if (isPrime(n)) return 0;

        int sum = 0;
        int i = 2;
        while (n > 1 && i <= n) {
            if (n % i == 0 && isPrime(i)) {
                n /= i;
                int temp = i;

                while (temp > 0) {
                    sum += (temp % 10);
                    temp /= 10;
                }
            } else {
                i++;
            }
        }
        return sum;
    }

public:
    int smithNum(int n) {
        int sum = sumOfDigits(n);
        int primeSum = findSum(n);

        return (primeSum == sum);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends