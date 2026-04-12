class Solution {
public:

    void solve(int col, int n,
               vector<int>& leftRow,
               vector<int>& upperDiagonal,
               vector<int>& lowerDiagonal,
               int &cnt) {

        // Base case: all queens placed
        if (col == n) {
            cnt++;
            return;
        }

        for (int row = 0; row < n; row++) {

            if (leftRow[row] == 0 &&
                lowerDiagonal[row + col] == 0 &&
                upperDiagonal[n - 1 + col - row] == 0) {

                // Mark
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                // Recurse
                solve(col + 1, n, leftRow, upperDiagonal, lowerDiagonal, cnt);

                // Backtrack
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    int totalNQueens(int n) {
        int cnt = 0;

        vector<int> leftRow(n, 0);
        vector<int> upperDiagonal(2 * n - 1, 0);
        vector<int> lowerDiagonal(2 * n - 1, 0);

        solve(0, n, leftRow, upperDiagonal, lowerDiagonal, cnt);

        return cnt;
    }
};