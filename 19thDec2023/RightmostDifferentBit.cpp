#include<bits/stdc++.h>
using namespace std;

/*
Problem name : Rightmost different bit
Problem link : https://practice.geeksforgeeks.org/problems/rightmost-different-bit-1587115621/1
Exaplanation :
-Aprroach 1 : 
    Using the concept of bit manipulation and left shift operator.
    Shift the bits of both the numbers to right by 1 and check if the last bit of both the numbers are same or not.
    As if the both and result give the same output then we'll shift the bits to right by 1 and increment the ans variable.
    If the both and result give the different output then we'll return the ans variable.
    If the both the numbers are 0 then we'll return -1.
    Time Complexity : O(log(max(m,n)))
    Space Complexity : O(1)
-Approach 2 :
   Using the XOR operator as XOR gives 0 if both the bits are same and 1 if both the bits are different.
    So we'll take the XOR of both the numbers and then check if the last bit of the XOR result is 1 or not.
    If the last bit of the XOR result is 1 then we'll return the ans variable.
    If the last bit of the XOR result is 0 then we'll shift the bits to right by 1 and increment the ans variable.
    If the both the numbers are 0 then we'll return -1.
    Time Complexity : O(log(max(m,n)))
    Space Complexity : O(1)

*/
class Solution
{
    public:
    //Function to find the first position with different bits.
    int approach1(int m,int n){
        int ans = 1 ;
        while((m>0) || (n>0)){
            if((m & 1) != (n & 1)) return ans;
            
            m = m >> 1;
            n = n >> 1;
            ans++;
        }
        
        return -1;
    }
    int approach2(int m,int n){
        int xorRes = m ^ n ;
        int ans = 1 ;
        while(xorRes > 0){
            if((xorRes & 1)){
                return ans;
            }
            xorRes = xorRes >> 1;
            ans++;
        }
        
        return -1;
    }
    int posOfRightMostDiffBit(int m, int n)
    {
        // Your code here
        return approach2(m,n);
    }
};
