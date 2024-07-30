

#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        vector<int> cost(n, 0);
        
        dp[n - 1] = 0; 
        
        for (int i = n - 2; i >= 0; --i) {
            int length = -1;
            for (int j = i; j < n; ++j) {
                length += (nums[j] + 1); 
                if (length > k) break; 
                
                int extraSpaces = k - length; 
                int currentCost = (j == n - 1) ? 0 : extraSpaces * extraSpaces;
                
                if (j < n - 1) {
                    currentCost += dp[j + 1];
                }
                
                dp[i] = min(dp[i], currentCost);
            }
        }
        
        return dp[0];
    
    } 
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
