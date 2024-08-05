

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

       
        int n = nums.size();
       
        vector<long long> result(n, 1);

       
        long long leftProduct = 1;

        
        for (int i = 0; i < n; ++i) {
            result[i] = leftProduct;
            leftProduct *= nums[i];
        }

      
        long long rightProduct = 1;

       
        for (int i = n - 1; i >= 0; --i) {
            result[i] *= rightProduct;
            rightProduct *= nums[i];
        }

        return result;
    }
};

int main() {
    int t; 
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) 
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); 

        for (int i = 0; i < n; i++) 
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
