class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<int> queens; // Track column positions of queens for each row
        solve(0, 0, 0, 0, n, queens, result);
        return result;
    }

private:
    void solve(int row, int columns, int diag1, int diag2, int n, 
               vector<int>& queens, vector<vector<string>>& result) {
        if (row == n) {
            result.push_back(generateBoard(queens, n));
            return;
        }

        int validPositions = (~(columns | diag1 | diag2)) & ((1 << n) - 1);

        while (validPositions) {
            int pos = validPositions & -validPositions;
            validPositions &= validPositions - 1;

            int columnIndex = __builtin_ctz(pos);

            queens.push_back(columnIndex);
            solve(row + 1, 
                  columns | pos, 
                  (diag1 | pos) << 1, 
                  (diag2 | pos) >> 1, 
                  n, queens, result);
            queens.pop_back();
        }
    }

    vector<string> generateBoard(const vector<int>& queens, int n) {
        vector<string> board(n, string(n, '.'));
        for (int i = 0; i < queens.size(); i++) {
            board[i][queens[i]] = 'Q';
        }
        return board;
    }
};
