class Solution {
public:
    vector<vector<string>> ans;
    void helper(int start, vector<string>& board) {
        if (start == board.size()) {
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < board.size(); i++) {
            if (checkboard(board, start, i)) {
                board[start][i] = 'Q';
                helper(start + 1, board);
                board[start][i] = '.';
            }
        }
    }

    bool checkboard(vector<string>& board, int row, int col) {
        // col
        for (int i = row; i >= 0; i--) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        // left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        // right diagonal
        for (int i = row, j = col; i >= 0 && j < board.size(); i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        if (n == 2 || n == 3)
            return {};
        vector<string> board(n, string(n, '.'));
        helper(0, board);
        return ans;
    }
};
