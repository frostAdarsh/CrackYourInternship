class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (backtrack(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }


    bool backtrack(vector<vector<char>>& board, string& word, int row, int col, int index) {
        if (index == word.size()) {
            return true;
        }
        
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index]) {
            return false;
        }
        
        char temp = board[row][col];
        board[row][col] = '#'; 
        
       
        bool found = backtrack(board, word, row + 1, col, index + 1) ||
                     backtrack(board, word, row - 1, col, index + 1) ||
                     backtrack(board, word, row, col + 1, index + 1) ||
                     backtrack(board, word, row, col - 1, index + 1);
        
        board[row][col] = temp; 
        
        return found;
    }
};
