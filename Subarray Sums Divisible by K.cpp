class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> map(k, 0); 
        map[0] = 1;
        int sum = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int m = sum % k;
            if (m < 0) {
                m = (m + k) % k; 
            }
            res += map[m];
            map[m]++;
        }
        return res;
    }
};
