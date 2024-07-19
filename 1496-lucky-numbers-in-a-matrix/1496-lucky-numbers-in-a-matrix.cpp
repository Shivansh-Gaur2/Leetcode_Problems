class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> row_mins(n, INT_MAX);  
        vector<int> col_maxs(m, INT_MIN);  

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                row_mins[i] = min(row_mins[i], matrix[i][j]);
            }
        }

        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                col_maxs[j] = max(col_maxs[j], matrix[i][j]);
            }
        }

        vector<int> result;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == row_mins[i] && matrix[i][j] == col_maxs[j]) {
                    result.push_back(matrix[i][j]);
                }
            }
        }

        return result;
    }
};
