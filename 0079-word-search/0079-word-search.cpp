class Solution {
public:
    int ROW, COL, res = false;
    bool exist(vector<vector<char>>& board, string word) {
        ROW = board.size();
        COL = board[0].size();
        for (int r = 0; r < ROW; r++) {
            for (int c = 0; c < COL; c++) {
                if (board[r][c] == word[0]) {
                    backtracking(board, word, 1, r, c);
                    if (res) return res;
                }
            }
        }
        return false;
    }

    void backtracking( vector<vector<char>>& board, string word, int i, int r, int c) {
        if (i == word.size()) {
            res = true;
            return;
        }
        char temp = board[r][c];
        board[r][c] = '?'; // mark visited  

        if (i < word.size() && c + 1 < COL && board[r][c+1] == word[i]) {
            backtracking(board, word, i+1, r, c+1);
        }

        // right
        if (i < word.size() &&  c - 1 >= 0 && board[r][c-1] == word[i]) {
            backtracking(board, word, i+1, r, c-1);

        }

        // top
        if (i < word.size() &&  r-1 >= 0 && board[r-1][c] == word[i]) {
            backtracking(board, word, i+1, r-1, c);

        }

        // down
        if (i < word.size() &&  r+1 < ROW && board[r+1][c] == word[i]) {
            backtracking(board, word, i+1, r+1, c);
        }

        board[r][c] = temp;

    }
};