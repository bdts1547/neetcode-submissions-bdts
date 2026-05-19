class Solution {
public:
    int ROW, COL, res = false;
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        ROW = board.size();
        COL = board[0].size();
        for (int r = 0; r < ROW; r++) {
            for (int c = 0; c < COL; c++) {
                if (board[r][c] == word[0]) {
                    visited[r][c] = true;
                    backtracking(board, word, 1, r, c, visited);
                    visited[r][c] = false;
                    if (res) return res;
                }
            }
        }
        return res;
    }

    void backtracking(vector<vector<char>>& board, string word, int i, int r, int c, 
    vector<vector<bool>>& visited) {
        // printf("%d %d %d\n", i, r, c);
        // printf("%c\n", word[i]);
        if (i == word.size()) {
            res = true;
            return;
        }

        // left
        if (i < word.size() && c + 1 < COL && board[r][c+1] == word[i] && !visited[r][c+1]) {
            // printf("left\n");
            visited[r][c] = true;
            backtracking(board, word, i+1, r, c+1, visited);
            visited[r][c] = false;
        }

        // right
        if (i < word.size() &&  c - 1 >= 0 && board[r][c-1] == word[i] && !visited[r][c-1]) {
            // printf("right\n");
            visited[r][c] = true;
            backtracking(board, word, i+1, r, c-1, visited);
            visited[r][c] = false;

        }

        // top
        if (i < word.size() &&  r-1 >= 0 && board[r-1][c] == word[i] && !visited[r-1][c]) {
            // printf("top\n");
            visited[r][c] = true;
            backtracking(board, word, i+1, r-1, c, visited);
            visited[r][c] = false;

        }

        // down
        if (i < word.size() &&  r+1 < ROW && board[r+1][c] == word[i] && !visited[r+1][c]) {
            // printf("down\n");
            visited[r][c] = true;
            backtracking(board, word, i+1, r+1, c, visited);
            visited[r][c] = false;

        }

    }
};
