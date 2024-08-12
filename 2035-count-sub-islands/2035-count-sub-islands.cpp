class Solution {
public:
    void helper(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i , int j, bool& isSubIsland) {
        if (i < 0 || i >= grid2.size() || j < 0 || j >= grid2[0].size() || grid2[i][j] == 0) {
            return;
        }

        if (grid1[i][j] == 0) {
            isSubIsland = false;
        }

        grid2[i][j] = 0;  
        helper(grid1, grid2, i + 1, j, isSubIsland);
        helper(grid1, grid2, i - 1, j, isSubIsland);
        helper(grid1, grid2, i, j + 1, isSubIsland);
        helper(grid1, grid2, i, j - 1, isSubIsland);
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int cnt = 0;
        int n = grid1.size();
        int m = grid1[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1) {
                    bool isSubIsland = true;
                    helper(grid1, grid2, i, j, isSubIsland);
                    if (isSubIsland) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
