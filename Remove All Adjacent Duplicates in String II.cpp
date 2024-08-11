class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stk;

        for (char c : s) {
            if (!stk.empty() && stk.top().first == c) {

                if (stk.top().second + 1 == k) {
                    stk.pop();
                } else {
                    stk.top().second++;
                }
            } else {

                stk.push({c, 1});
            }
        }

        string result;
        while (!stk.empty()) {
            auto [ch, count] = stk.top();
            stk.pop();
            result.append(count, ch);
        }

        reverse(result.begin(), result.end());

        return result;
    }
};