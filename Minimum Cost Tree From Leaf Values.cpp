class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        stack<int> st;
        int totalCost = 0;

        for (int value : arr) {
            while (!st.empty() && st.top() <= value) {
                int top = st.top();
                st.pop();
                if (!st.empty()) {
                    totalCost += top * min(st.top(), value);
                } else {
                    totalCost += top * value;
                }
            }
            st.push(value);
        }

        while (st.size() > 1) {
            int top1 = st.top();
            st.pop();
            int top2 = st.top();
            totalCost += top1 * top2;
        }

        return totalCost;
    }
};