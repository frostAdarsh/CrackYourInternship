class Solution {
    void solve(string s, int open, int close, vector<string>& ans) {
        if (open == 0 && close == 0) {
            ans.push_back(s);
            return;
        }
        if (open == close) {
            string s1 = s;
            s1.push_back('(');
            solve(s1, open - 1, close, ans);
        } else if (open == 0) {
            string s1 = s;
            s1.push_back(')');
            solve(s1, open, close - 1, ans);
        } else if (close == 0) {
            string s1 = s;
            s1.push_back('(');
            solve(s1, open - 1, close, ans);
        } else {
            string s1 = s;
            string s2 = s;
            s1.push_back('(');
            s2.push_back(')');
            solve(s1, open - 1, close, ans);
            solve(s2, open, close - 1, ans);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        int open = n;
        int close = n;
        string s = "";
        vector<string> ans;
        solve(s, open, close, ans);
        return ans;
    }
};