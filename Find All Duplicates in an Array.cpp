class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]);
            int x = num - 1;
            if (nums[x] < 0) {
                result.push_back(num);
            } else {
                nums[x] *= -1;
            }
        }
        return result;
    }
};