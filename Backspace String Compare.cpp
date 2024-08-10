class Solution {
public:
    bool backspaceCompare(string s, string t) {
        auto processString = [](const string& str) -> string {
            stack<char> stk;
            for (char ch : str) {
                if (ch == '#') {
                    if (!stk.empty()) {
                        stk.pop();
                    }
                } else {
                    stk.push(ch);
                }
            }

            string result;
            while (!stk.empty()) {
                result = stk.top() + result;
                stk.pop();
            }
            return result;
        };

        string processedS = processString(s);
        string processedT = processString(t);

        return processedS == processedT;
    }
};