//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*
Problem name : Array Pair Sum Divisibility Problem
Problem link : https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1
Difficulty : Medium
Explanation : - Approach 1 : Brute Force
              - Approach 2 : Using Hashing
              - Approach 3 : Using Frequency Array
                        
*/
class Solution {
public:
    bool canPairApproach1(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%2 != 0) return false;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                if((nums[i]+nums[j])%k == 0)
                    return true;
            }
        }
        
        return false;
    }   
    bool canPairApproach2(std::vector<int>& nums, int k) {
        int n = nums.size();
        if(n%2 != 0) return false;
        
        unordered_map<int,int> mp;

        for(int i = 0 ; i < n ; i++){
            mp[nums[i]%k]++;
        }

        for(int i = 0 ; i < n ; i++){
            int rem = nums[i]%k;
            if(rem == 0){
                if(mp[rem]%2 != 0)
                    return false;
            }
            else if(2*rem == k){
                if(mp[rem]%2 != 0)
                    return false;
            }
            else if(mp[rem] != mp[k-rem])
                return false;
        }
        
        return true;
    }
    bool canPairApproach3(std::vector<int>& nums, int k) {
        int n = nums.size();
        if(n%2 != 0) return false;
        
        int ans[k] ;
        
        for(int i = 0 ; i < n ; i++){
            ans[nums[i]%k]++;
        }
        
        if(ans[0]%2 == 1) return false;
        
        for(int i = 1 ; i < k/2 ; i++){
            if(ans[i] != ans[k-i])
                return false;
        }
        
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPairApproach3(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends