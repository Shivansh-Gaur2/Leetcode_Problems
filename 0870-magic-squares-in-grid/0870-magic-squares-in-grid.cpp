class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;

        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (grid[i][j] != 5) continue;  // The center of a magic square should be 5
                
                int upp = grid[i - 1][j - 1] + grid[i - 1][j] + grid[i - 1][j + 1];
                int mid = grid[i][j - 1] + grid[i][j] + grid[i][j + 1];
                int low = grid[i + 1][j - 1] + grid[i + 1][j] + grid[i + 1][j + 1];
                int left = grid[i - 1][j - 1] + grid[i][j - 1] + grid[i + 1][j - 1];
                int main = grid[i - 1][j] + grid[i][j] + grid[i + 1][j];
                int right = grid[i - 1][j + 1] + grid[i][j + 1] + grid[i + 1][j + 1];
                int leftDiag = grid[i - 1][j - 1] + grid[i][j] + grid[i + 1][j + 1];
                int rightDiag = grid[i - 1][j + 1] + grid[i][j] + grid[i + 1][j - 1];

                if (upp == mid && mid == low && low == left && left == main && main == right && right == leftDiag && leftDiag == rightDiag) {
                    set<int> s = {grid[i - 1][j - 1], grid[i - 1][j], grid[i - 1][j + 1],
                                  grid[i][j - 1], grid[i][j], grid[i][j + 1],
                                  grid[i + 1][j - 1], grid[i + 1][j], grid[i + 1][j + 1]};
                    if (s.size() == 9 && *s.begin() == 1 && *s.rbegin() == 9) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
