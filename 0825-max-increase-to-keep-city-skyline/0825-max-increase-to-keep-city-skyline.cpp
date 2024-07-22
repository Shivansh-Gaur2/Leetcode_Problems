class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<int> rowMax;
        vector<int> colMax;
        for(int i =0 ; i < n; i++){
            int maxi = INT_MIN;
            for(int j = 0 ; j < m ;j++){
                maxi = max(maxi, grid[i][j]);
            }
            rowMax.push_back(maxi);
        }

        for(int i = 0 ; i < m ; i++){
            int maxi = INT_MIN;
            for(int j = 0; j < n; j++){
                maxi = max(maxi , grid[j][i]);
            }
            colMax.push_back(maxi);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < m ; j++){
                cout << rowMax[i] << " " << colMax[i] << endl;
                cnt += abs(grid[i][j] - min(rowMax[i], colMax[j]));
            }
        }
        return cnt;
    }
};