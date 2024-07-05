class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> ump;

        int ans = 0;
        int row = grid.size();
        int col = grid[0].size();

        for (int i = 0; i < row; i++) {
            ump[grid[i]]++;
        }

        for (int j = 0; j < col; j++) {
            vector<int> curr;
            for (int i = 0; i < row; i++) {
                curr.push_back(grid[i][j]);
            }
            ans += ump[curr];
        }
        return ans;
    }
};