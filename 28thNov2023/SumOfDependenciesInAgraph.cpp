//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/*
Problem name : Sum of Dependencies in a graph
Problem link : https://practice.geeksforgeeks.org/problems/sum-of-dependencies-in-a-graph/0/?track=DSASP-Graph&batchId=154
Explanation : 
Given a directed graph with V nodes and E edges. If there is an edge from u to v then u depends on v. Find out the sum of dependencies for every node. Duplicate edges should be counted as separate edges.
Basically we have to find the number of edges as the number of edges is the number of dependencies.
Time Complexity : O(V+E)
Space Complexity : O(1)

*/

/*
0 -> 2
0 -> 3
1 -> 3
2 -> 3
*/

class Solution {
  public:
    int sumOfDependencies(vector<int> adj[], int V) {
        // code here
        int sizeOfAdjList = 0 ;
        for(int i = 0 ; i < V ; i++){
            sizeOfAdjList += adj[i].size();
        }
        return sizeOfAdjList;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<int> v[N];
        for (int i = 0; i < M; i++) {
            cin >> x >> y;
            v[x].push_back(y);
        }
        Solution ob;
        cout << ob.sumOfDependencies(v, N) << "\n";
    }
}
// } Driver Code Ends