//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

class Solution
{   
    public:
    vector<int> sumTriangles(const vector<vector<int> >& matrix, int n)
    {
        // code here
        /*
        00 01 02 
        10 11 12 
        20 21 22 
        */
        int upSum = 0 ;
        int lowSum = 0 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(j >= i) upSum += matrix[i][j];
                if(j <= i) lowSum += matrix[i][j];
            }
        }
        vector<int> ans(2,0);
        ans[0] = upSum ;
        ans[1] = lowSum ;
        return ans;
        
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }
        Solution ob;
        vector<int> result = ob.sumTriangles(matrix,n);
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}