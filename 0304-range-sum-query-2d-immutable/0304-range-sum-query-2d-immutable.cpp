class NumMatrix {
public:
vector<vector<int>> grid;
    NumMatrix(vector<vector<int>>& matrix) {
        grid = matrix;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                grid[i][j] += grid[i][j - 1];
            }
        }
    }

int sumRegion(int row1, int col1, int row2, int col2) {
    int sum = 0;
    for (int i = row1; i <= row2; i++) {
        if (col1 > 0) {
            sum += grid[i][col2] - grid[i][col1 - 1];
        } else {
            sum += grid[i][col2];
        }
    }
    return sum;
}

};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */