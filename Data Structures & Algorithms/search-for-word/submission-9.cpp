class Solution {
public:
    int ROW, COL;
    bool exist(vector<vector<char>>& board, string word) {
        ROW = board.size();
        COL = board[0].size();
        for (int r = 0; r < ROW; r++) {
            for (int c = 0; c < COL; c++) {
                if (board[r][c] == word[0]) {
                    if(backtracking(board, word, 1, r, c)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool backtracking(vector<vector<char>>& board, string word, int i, int r, int c) {
        if (i == word.size()) {
            return true;
        }

        char tmp = board[r][c];
        board[r][c] = '?'; // visited

        // left
        if (i < word.size() && c + 1 < COL && board[r][c+1] == word[i]) {
            if(backtracking(board, word, i+1, r, c+1)) return true;
        }

        // right
        if (i < word.size() &&  c - 1 >= 0 && board[r][c-1] == word[i]) {
            if(backtracking(board, word, i+1, r, c-1)) return true;

        }

        // top
        if (i < word.size() &&  r-1 >= 0 && board[r-1][c] == word[i]) {
            if(backtracking(board, word, i+1, r-1, c)) return true;

        }

        // down
        if (i < word.size() &&  r+1 < ROW && board[r+1][c] == word[i]) {
            if(backtracking(board, word, i+1, r+1, c)) return true;

        }

        board[r][c] = tmp;
        return false;

    }
};
