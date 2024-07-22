class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<int> rowMax(n, 0);
        vector<int> colMax(m, 0);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                rowMax[i] = max(rowMax[i], grid[i][j]);
                colMax[j] = max(colMax[j], grid[i][j]);
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cnt += min(rowMax[i], colMax[j]) - grid[i][j];
            }
        }

        return cnt;
    }
};
