#include <vector>
using vcc = std::vector<std::vector<char>>;
using vc  = std::vector<char>;

class Solution {
public:
    void solveSudoku(vcc &board) {
        solve(board);
    }

private:
    bool solve(vcc &board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;

                            if (solve(board)) return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false; // no valid number found
                }
            }
        }
        return true; // solved
    }

    bool isValid(vcc &board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c) return false; // check column
            if (board[row][i] == c) return false; // check row
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false; // check 3x3 box
        }
        return true;
    }
};
