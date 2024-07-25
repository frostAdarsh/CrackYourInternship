class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        for (int i : cardPoints) {
            sum += i;
        }

        int n = cardPoints.size();

        if (n == k) return sum;

        int window = 0;
        
        for (int i = 0; i < n - k; i++) {
            window += cardPoints[i];
        }

        int ans = sum - window;
       
        for (int i = n - k; i < n; i++) {
            window += cardPoints[i] - cardPoints[i - (n - k)];
            ans = max(ans, sum - window);
        }

        return ans;
    }
};
