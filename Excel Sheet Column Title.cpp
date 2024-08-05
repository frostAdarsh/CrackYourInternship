class Solution {
public:
    std::string convertToTitle(int columnNumber) {
        std::string result = "";
        while (columnNumber > 0) {
            columnNumber--; 
            int remainder = columnNumber % 26;
            char letter = 'A' + remainder;
            result = letter + result;
            columnNumber /= 26;
        }
        return result;
    }
};