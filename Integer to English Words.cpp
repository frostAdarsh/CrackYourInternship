

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";

        vector<string> lessThan20 = {
            "",        "One",     "Two",       "Three",    "Four",
            "Five",    "Six",     "Seven",     "Eight",    "Nine",
            "Ten",     "Eleven",  "Twelve",    "Thirteen", "Fourteen",
            "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"",      "",      "Twenty",  "Thirty", "Forty",
                               "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> thousands = {"", "Thousand", "Million", "Billion"};

        string res;
        for (int i = 0; num > 0; i++) {
            if (num % 1000 != 0) {
                res = helper(num % 1000, lessThan20, tens) + thousands[i] +
                      " " + res;
            }
            num /= 1000;
        }

        while (res.back() == ' ')
            res.pop_back();
        return res;
    }

private:
    string helper(int n, vector<string>& lessThan20, vector<string>& tens) {
        if (n == 0)
            return "";
        else if (n < 20)
            return lessThan20[n] + " ";
        else if (n < 100)
            return tens[n / 10] + " " + helper(n % 10, lessThan20, tens);
        else
            return lessThan20[n / 100] + " Hundred " +
                   helper(n % 100, lessThan20, tens);
    }
};
