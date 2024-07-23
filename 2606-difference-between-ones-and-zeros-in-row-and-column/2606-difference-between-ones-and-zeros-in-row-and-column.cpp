class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> onesRow(n , 0);
        vector<int> onesCol(m , 0);

        vector<vector<int>>diff(n, vector<int>(m, 0));
        for(int i = 0; i < n ; i++){
            for(int j = 0 ; j < m; j++){
                onesRow[i] += grid[i][j];
                onesCol[j] += grid[i][j];
            }
        }
        
        for(int i  = 0 ; i < n; i++){
            for(int j = 0; j < m ; j++){
                diff[i][j] = onesRow[i] + onesCol[j] - (n - onesRow[i]) - (m - onesCol[j]);
            }
        }
        return diff;
    }
};