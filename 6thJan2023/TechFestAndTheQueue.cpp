//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int findPrimeNum(int a) {
        vector<bool> primeNum(a + 1, true);
        primeNum[0] = false;
        primeNum[1] = false;

        for (int i = 2; i <= sqrt(a); i++) {
            if (primeNum[i]) {
                for (int j = i * i; j <= a; j += i) {
                    primeNum[j] = false;
                }
            }
        }

        map<int, int> mp;

        for (int i = 2; i <= a; i++) {
            while (primeNum[i] && (a % i == 0)) {
                a = a / i;
                mp[i]++;
            }
        }

        if (a > 1) {
            mp[a]++;
        }

        int ans = 0;
        for (auto it : mp) {
            ans += it.second;
        }

        return ans;
    }

    int sumOfPowers(int a, int b) {
        int ans = 0;

        for (int i = a; i <= b; i++) {
            ans += findPrimeNum(i);
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends