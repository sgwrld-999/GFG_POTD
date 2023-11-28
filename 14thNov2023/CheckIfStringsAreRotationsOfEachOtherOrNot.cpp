//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
/*
Problem name : Check if strings are rotations of each other or not
Problem link : https://practice.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1
*/

// } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // Your code here
        //Concatenating and searching for the s2 
        //The idea is that string is rotated once front to back
        // MW LW FW -> We have check this is present or not 
        //If we join the two strings 
        //FW MW LW FW MW LW 
        //geeks(forgeeksgeeks)forgeeks -> contains require answer 
        return ((s1+s1).find(s2)!=string::npos);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1 ="geeksforgeeks";
        string s2="forgeeksgeeks";
        // cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends